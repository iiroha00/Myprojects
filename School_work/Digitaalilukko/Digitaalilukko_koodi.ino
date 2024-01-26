#include <Servo.h> 
#include "rgb_lcd.h" 
#include <EEPROM.h> 
#include <Wire.h> 
#include <String.h> 
#include <Key.h> 
#include <Keypad.h> 
#include <avr/wdt.h> 
  
const int BUTTON_PIN = 2; 
int sensorPin = A6; // Potentiometrin pinni

Servo lock; 
rgb_lcd lcd;  

const float MAX_MS = 20000; // Lukon aukiolon maksimiaika
float ms_time; // Lukon aukioloaika
int val; // AD-muunnos arvo 

const int LOCKED_DEG = 0; // servon asento asteissa, kun lukossa
const int OPEN_DEG = 180; // servon asento asteissa, kun auki 
const char PIN_CODE[4]; // EEPROM:sta haettu arvo
const int PIN_LENGTH = 4; 
const int ROW_NUM = 4;
const int COLUMN_NUM = 4;

// Näppäimistön alustus 
char keys[ROW_NUM][COLUMN_NUM] = { 
    {'1', '2', '3', 'A'}, 
    {'4', '5', '6', 'B'}, 
    {'7', '8', '9', 'C'}, 
    {'*', '0', '#', 'D'} 
}; 
 
// Sijoitetaan näppäimistön napit arduinon pinneihin
byte pin_rows[ROW_NUM] = {12, 11, 10, 3};
byte pin_column[COLUMN_NUM] = {4, 5, 6, 7}; 

// Sijoitetaan alustetut arvot muuttujaan 
Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM); 
 
String input; // Salasana, joka tulee käyttäjän syötteestä
int status = 0; // Muuttuja näppäimistön syötteen hallintaan
String pin; // Muuttuja EEPROM:ista saadun oikean pin-koodin tallentamiseen

// Haetaan oikea pin-koodi EEPROM:ista
void loadPinCode() { 
    for (int i = 0; i < PIN_LENGTH; i++) { 
        EEPROM.get(i, PIN_CODE[i]); 
    } 
} 

// Pin-koodien vertaus funktio 
void submitPinCode() { 
    lcd.setCursor(0, 1); 
    if (input == pin) { ¨
    // Jos pin-koodit ovat samat, 
    // niin kirjoitetaan näyttöön oikein ja käännetään servoa
        lcd.print("Oikein"); 
        lock.write(OPEN_DEG); 
        PORTB=B00000010; // Sammutetaan punainen valo, vihreä päälle
        // Sammutetaan watchdog, jotta ei tapahdu resettiä delayn aikana 
        wdt_disable(); 
        delay(ms_time); // Viivytetään niin kauan kuin halutaan lukon olevan auki
    } else { 
      //Jos pin-koodit ovat erit, niin kirjoitetaan näyttöön vaarin
      // ja pyyhitaan se 2 sekunnin kuluttua
        lcd.print("Vaarin"); 
        delay(2000); 
        lcd.setCursor(0, 1); 
        lcd.print("                                        "); 
    } 
} 

// Keskeytys, joka tapahtuu, kun painetaan nappia 
void buttonInterrupt() { 
  wdt_enable(WDTO_15MS); 
} 
 
void ADC_init() { 
  // Asetetaan vertailu arvo
  ADMUX |= (1 << REFS0); 
  // Asetetaan muunnos pinnistä A6
  ADMUX |= (1 << MUX2) | (1 << MUX1) | (0 << MUX0); 
  // Sallitaan AD-muunnos 
  ADCSRA |= (1 << ADEN); 
} 
 
uint16_t ADC_read(uint8_t ch) { 
  // Aloitetaan AD-muunnos
  ADCSRA |= (1 << ADSC); 
  // Odotetaan muunnoksen valmistumista
  while (ADCSRA & (1 << ADSC)) { 
    // Odotus loop 
  } 
  // Palautetaan AD-muunnoksesta saatu arvo 
  val = ADC; 
  return val; 
} 
 
void setup() { 
    DDRD &= ~(1 << DDD2); // Pinni input:iksi
    PORTD |= (1 << PORTD2); // Pinni input-pullup:iksi
    // Nappikeskeytys
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonInterrupt, FALLING); 
    Serial.begin(9600); 
    lock.attach(A1); // Servon alustus
    DDRB=B00000011; // LED:ien pinnit output:eiksi
    // Näytön alustus
    lcd.begin(16, 2); 
    lcd.setRGB(255, 0, 0); 
    loadPinCode(); 
    pin = String(PIN_CODE); // Muutetaan EEPROM:ista saatu pin stringiksi
    Serial.println(PIN_CODE); 
    Serial.println(pin); 
    ADC_init(); // AD-muunnos päälle
    delay(300); // Delay, jotta AD-muunnos saadaan päälle
    uint16_t sensorValue = ADC_read(sensorPin); // AD-muunnoksesta saatu arvo
    // Vertailu, joka määrittää, kuinka kauan lukko on auki
    if(sensorValue <= 500){ 
      ms_time = 10000; 
    } else { 
      ms_time = (sensorValue * MAX_MS) / 1023.0; 
    } 
    Serial.print("Raw ADC Value: "); 
    Serial.print(sensorValue); 
    Serial.print(", Time (ms): "); 
    Serial.println(ms_time); 
    delay(500); // Delay, jotta kaikki saadaan alustettua oikein
} 
 
void loop() 
{ 
    PORTB=B00000001; // Punainen LED päälle, vihreä pois
    lock.write(LOCKED_DEG); // Servo lukkossa asentoon
    lcd.clear(); 
    lcd.setCursor(0, 0); 
    lcd.print("Anna PIN: "); 
 
    // Kerätään nappien painallukset
    char key = keypad.getKey(); 
    if (key) { 
        status = 1; 
        lcd.print("*"); 
        input = key; // Painetun napin arvo tallennetaan muuttujaan
        Serial.println(key); 
        // Watchdog reset tapahtuu, jos mitään nappia ei paineta 8 sekuntiin
        wdt_enable(WDTO_8S); 
    } 
    while (status == 1) { 
        key = keypad.getKey(); 
        if (key) { 
            Serial.println(key);
            // Jos # näppäintä painetaan, siirrytään vertailuun
            if (key == '#') { 
              submitPinCode(); 
              status = 0;
              break; // Poistutaan loopista
            } 
            input = input + key; // Lisätään painettu nappi muuttujaan
            lcd.print("*"); 
            Serial.println(input); 
            // Restoidaan watchdog timer, joka kerta kun jotain nappia painetaan
            wdt_reset(); 
        } 
    } 
    // Sammutetaan watchdog, jotta resettejä ei tapahdu, kun nappeja ei paineta
    wdt_disable(); 
} 

