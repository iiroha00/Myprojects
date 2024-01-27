#include <LiquidCrystal.h>
#include "DHT.h"
// define sensor and pins
#define DHTTYPE DHT11
const int rs = 10, en = 9, d4 = 8, d5 = 7, d6 = 6, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int sensor_pin = 12;
DHT dht(sensor_pin, DHTTYPE);

void setup() {
// setup the lcd and start the sensor
lcd.begin(16, 2);
lcd.setCursor(0, 0);
lcd.print("Temp: ");
lcd.setCursor(0, 1);
lcd.print("Hum: ");
dht.begin();
}

void loop() {
// read the sensors
float h = dht.readHumidity();
float t = dht.readTemperature();
// print the values to lcd
lcd.setCursor(7, 0);
lcd.print(t);
lcd.print(" C");
lcd.setCursor(6, 1);
lcd.print(h);
lcd.print(" %");
}
