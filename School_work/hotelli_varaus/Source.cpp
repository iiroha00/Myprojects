#include <iostream>
#include <cstdlib>
#include <string>
#include <random>
using namespace std;

struct varaus {
	string nimi;
	char Huone_koko;
	int Huone_numero;
	int Varaus_numero;
	int yot;
	float loppusumma;
};


//taulukoita
int huoneet[300];
varaus varaukset[300];

//aliohjelmia
		//Tarkistaa userInput syötteen
bool syötteen_tarkistus(char userInput) {
	if (userInput == '1' || userInput == '2' || userInput == '3' || userInput == '0') {
		return true;
	}
	else {
		return false;
	}
}

//Tarkistaa että Huone_numero on 1-yhden_huoneet välillä
bool tarkistus(int Huone_numero, int yhden_huoneet) {
	if (Huone_numero >= 1 && Huone_numero <= yhden_huoneet) {
		return true;
	}
	else {
		return false;
	}
}

//Tarkistaa että Huone_numero on kahden_min_huoneet-max_huoneet välillä
bool tarkistus_kahden_huoneet(int Huone_numero, int kahden_min_huoneet, int max_huoneet) {
	if (Huone_numero >= kahden_min_huoneet && Huone_numero <= max_huoneet) {
		return true;
	}
	else {
		return false;
	}
}

//Tarkistaa huoneen varauksen
bool tarkistus_Huone(int Huone_numero) {
	if (huoneet[Huone_numero - 1] == 0) {
		return true;
	}
	else {
		return false;
	}
}

//Luo varaus numeron 10000-99999 väliltä
int numero_generaattori() {
	random_device generaattori;
	uniform_int_distribution<int> varausnumero(10000, 99999);
	return varausnumero(generaattori);
}

//arpoo huone numeron a-b väliltä. a on min  b on max
int arvohuonenumero(int a, int b) {
	random_device generaattori;
	uniform_int_distribution<int> huonenumero(a, b);
	return huonenumero(generaattori);
}

//luo alennuksen
float luoalennus() {
	int luku;
	srand(time(0));
	luku = 1 + (rand() % 3);
	if (luku == 1) { // 0% alennus
		return 1;
	}
	if (luku == 2) { // 10% alennus
		return 0.90;
	}
	if (luku == 3) { // 20% alennus
		return 0.80;
	}
}
//tarkistaa että huoneita on vapaana
bool onkohuoneitavapaana(int min_huoneet, int max_huoneet) {
	for (int i = min_huoneet; i < max_huoneet; i++) {
		if (huoneet[i] == 0) {
			return true;
		}
	}
	return false;
}

//Varauksen teko
varaus luoVaraus(int max_huoneet, int yhden_huoneet) {
	int  yhden_huoneen_hinta = 100, kahden_huoneen_hinta = 150;
	int kahden_min_huoneet = yhden_huoneet + 1;
	int m;
	char syöte;
	float alennus;
	varaus varaus;
	varaus.Varaus_numero = numero_generaattori();
	cout << "Tervetuloa huoneen varaukseen\n";
	cout << "Varausnumerosi on: " << varaus.Varaus_numero << "\n";
	cout << "Anna koko nimesi: ";
	cin.clear();
	cin.ignore(100, '\n');
	getline(cin >> ws, varaus.nimi);
	m = onkohuoneitavapaana(0, yhden_huoneet); //tarkistetaan onko yhden hengen huoneita vapaana.
	if (m == true) {
		cout << "\n" << "Yhden hengen huoneita on vapaana. " << endl;
	}
	else {
		cout << "Yhden hengen huoneita ei varattavissa" << endl;
	}
	m = onkohuoneitavapaana(kahden_min_huoneet, max_huoneet); //tarkistetaan onko kahden hengen huoneita vapaana.
	if (m == true) {
		cout << "Kahden hengen huoneita on vapaana. " << endl;
	}
	else {
		cout << "Kahden hengen huoneita ei varattavissa" << endl;
	}
	cout << "\n\n*************************\n" << "* 1hh: 100 euroa per yö *\n" << "*                       *\n" << "* 2hh: 150 euroa per yö *\n" << "*                       *\n" << "*************************\n" << endl;
	cout << "Valitse huoneen koko painamalla: 1 (yhden hengen huone) tai 2 (kahden hengen huone): ";
	cin.clear();
	cin >> varaus.Huone_koko;
	//tarkistaa että syötettiin 1 tai 2
	while (varaus.Huone_koko != '1' && varaus.Huone_koko != '2') {
		cout << "Virhe! Valitse huoneen koko painamalla: 1 (yhden hengen huone) tai 2 (kahden hengen huone): ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> varaus.Huone_koko;
	}

	cout << "\n";
	//jos yhden hegen huoneita ei ole varattavissa ja käyttäjä silti valitsee yhden hengen huoneet. siirretään kahden hengen huoneisiin
	if (onkohuoneitavapaana(0, yhden_huoneet) == false) {
		if (varaus.Huone_koko == '1') {
			cout << "Yhden hengen huoneita ei ole varattavissa. \n" << "Paina 2: Siirry varaamaan kahden hengen huone." << endl;
			cin.clear();
			cin >> varaus.Huone_koko;
			while (varaus.Huone_koko != '2') {
				cout << "Virhe! Paina 2: Siirry varaamaan kahden hengen huone." << endl;
				cin.clear();
				cin.ignore(100, '\n');
				cin >> varaus.Huone_koko;
			}
		}
	}//jos kahden hegen huoneita ei ole varattavissa ja käyttäjä silti valitsee kahden hengen huoneet. siirretään yhden hengen huoneisiin
	if (onkohuoneitavapaana(kahden_min_huoneet, max_huoneet) == false) {
		if (varaus.Huone_koko == '2') {
			cout << "kahden hengen huoneita ei ole varattavissa. \n" << "Paina 1: Siirry varaamaan yhden hengen huone." << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cin >> varaus.Huone_koko;
			while (varaus.Huone_koko != '1') {
				cout << "Virhe! Paina 1: Siirry varaamaan yhden hengen huone." << endl;
				cin.clear();
				cin.ignore(100, '\n');
				cin >> varaus.Huone_koko;
			}
		}
	}//jos Huoneita ei ole varattavissa suljetaan ohjelma
	if (onkohuoneitavapaana(0, yhden_huoneet) == false && onkohuoneitavapaana(kahden_min_huoneet, max_huoneet) == false) {
		cout << "Huoneita ei varattavissa. Suljetaan ohjelma." << endl;
		exit(0);
	}

	// jos Käyttäjä valitsi yhden hengen huoneen
	if (varaus.Huone_koko == '1') {
		cout << "1: Arvo huonenumero\n" << "2: Valitse huonenumero\n";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> syöte;
		//tarkistaa että syätettiin 1 tai 2
		while (syöte != '1' && syöte != '2') {
			cout << "Virhe! 1: Arvo huonenumero\n" << "2: Valitse huonenumero\n";
			cin.clear();
			cin.ignore(100, '\n');
			cin >> syöte;
		}
		//syöte on 1 arvo huone numero
		if (syöte == '1') {
			varaus.Huone_numero = arvohuonenumero(1, yhden_huoneet);
			m = tarkistus_Huone(varaus.Huone_numero);
			while (m == false) {
				varaus.Huone_numero = arvohuonenumero(1, yhden_huoneet);
				m = tarkistus_Huone(varaus.Huone_numero);
			}
			cout << "\nHuone numerosi on " << varaus.Huone_numero << endl;
		}
		//syöte on 2 valitsee käyttäjä huone numeron
		if (syöte == '2') {
			cout << "Anna haluamasi huoneen numero " << "(1-" << yhden_huoneet << "): ";
			cin.clear();
			cin.ignore(100, '\n');
			cin >> varaus.Huone_numero;
			//syötteen tarkastus
			while (!cin) {
				cout << "Virhe! Syötä huone numero " << "(1-" << yhden_huoneet << "): \n";
				cin.clear();
				cin.ignore(100, '\n');
				cin >> varaus.Huone_numero;
			}
		}
		//Tarkistaa että huone numero on 1-yhden_huoneet välillä
		while (tarkistus(varaus.Huone_numero, yhden_huoneet) == false) {
			cout << "Huone numero on virheellinen\n" << "Anna uusi huone numero " << "(1-" << yhden_huoneet << "): ";
			cin >> varaus.Huone_numero;
			//syötteen tarkastus
			while (!cin) {
				cout << "Virhe! Syötä huone numero " << "(1-" << yhden_huoneet << "): \n";
				cin.clear();
				cin.ignore(100, '\n');
				cin >> varaus.Huone_numero;
			}
		}
		//Tarkistaa että onko huone vapaa
		while (tarkistus_Huone(varaus.Huone_numero) == false) {
			cout << "Huone on varattu. " << "Anna uusi huoneen numero: ";
			cin.clear();
			cin >> varaus.Huone_numero;
			//syötteen tarkastus
			while (!cin) {
				cout << "Virhe! Syötä huone numero " << "(1-" << yhden_huoneet << "): \n";
				cin.clear();
				cin.ignore(100, '\n');
				cin >> varaus.Huone_numero;
			}//tarkistetaan onko uusi huone numero oikealta väliltä
			while (tarkistus(varaus.Huone_numero, yhden_huoneet) == false) {
				cout << "Huone numero on virheellinen\n" << "Anna uusi huone numero " << "(1-" << yhden_huoneet << "): ";
				cin >> varaus.Huone_numero;
				//syötteen tarkastus
				while (!cin) {
					cout << "Virhe! Syötä huone numero " << "(1-" << yhden_huoneet << "): \n";
					cin.clear();
					cin.ignore(100, '\n');
					cin >> varaus.Huone_numero;
				}
			}
		}
		//jos huone on vapaa
		if (tarkistus(varaus.Huone_numero, yhden_huoneet) == true) {
			if (tarkistus_Huone(varaus.Huone_numero) == true) {
				huoneet[varaus.Huone_numero - 1] = 1; //varaa huoneen
				cout << "Anna moneksi yöksi haluat varata huoneen: ";
				cin.clear();
				cin.ignore(100, '\n');
				cin >> varaus.yot; //käyttäjä antaa moneksi yöksi haluaa varatahuoneen
				//syötteen tarkistus
				while (!cin) {
					cout << "Virhe! Moneksi yöksi haluat varata huoneen: \n";
					cin.clear();
					cin.ignore(100, '\n');
					cin >> varaus.yot;
				}
				alennus = luoalennus();
				varaus.loppusumma = varaus.yot * yhden_huoneen_hinta * alennus; //laskee varauksen hinnan
				cout << "Varauksesi hinta on " << varaus.loppusumma << " euroa\n\n";
				return varaus;
			}
		}
	}
	// jos Käyttäjä valitsi kahden hengen huoneen
	if (varaus.Huone_koko == '2') {
		cout << "1: Arvo huonenumero\n" << "2: Valitse huonenumero\n";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> syöte;
		//tarkistaa että syätettiin 1 tai 2
		while (syöte != '1' && syöte != '2') {
			cout << "Virhe! 1: Arvo huonenumero\n" << "2: Valitse huonenumero\n";
			cin.clear();
			cin.ignore(100, '\n');
			cin >> syöte;
		}
		//syöte on 1 arvo huone numero
		if (syöte == '1') {
			varaus.Huone_numero = arvohuonenumero(kahden_min_huoneet, max_huoneet);
			while (tarkistus_Huone(varaus.Huone_numero) == false) {
				varaus.Huone_numero = arvohuonenumero(kahden_min_huoneet, max_huoneet);
			}
			cout << "Huone numerosi on " << varaus.Huone_numero << endl;
		}
		//syöte on 2 valitsee käyttäjä huone numeron
		if (syöte == '2') {
			cout << "Anna haluamasi huoneen numero " << "(" << kahden_min_huoneet << "-" << max_huoneet << "): ";
			cin.clear();
			cin.ignore(100, '\n');
			cin >> varaus.Huone_numero;
			//syötteen tarkistus
			while (!cin) {
				cout << "Virhe! Syötä huone numero " << "(" << kahden_min_huoneet << "-" << max_huoneet << "): \n";
				cin.clear();
				cin.ignore(100, '\n');
				cin >> varaus.Huone_numero;
			}
		}

		//Tarkistaa että huone numero on yhden_huoneet+1-max_huoneet välillä
		while (tarkistus_kahden_huoneet(varaus.Huone_numero, kahden_min_huoneet, max_huoneet) == false) {
			cout << "Huone numero on virheellinen\n" << "Anna uusi huone numero " << "(" << kahden_min_huoneet << "-" << max_huoneet << "): ";
			cin.clear();
			cin.ignore(100, '\n');
			cin >> varaus.Huone_numero;
			//syötteen tarkistus
			while (!cin) {
				cout << "Virhe! Syötä huone numero " << "(" << kahden_min_huoneet << "-" << max_huoneet << "): \n";
				cin.clear();
				cin.ignore(100, '\n');
				cin >> varaus.Huone_numero;
			}
		}
		//Tarkistaa että onko huone vapaa
		while (tarkistus_Huone(varaus.Huone_numero) == false) {
			cout << "Huone on varattu. " << "Anna uusi huoneen numero: ";
			cin.clear();
			cin.ignore(100, '\n');
			cin >> varaus.Huone_numero;
			//syötteen tarkistus
			while (!cin) {
				cout << "Virhe! Syötä huone numero " << "(" << kahden_min_huoneet << "-" << max_huoneet << "): \n";
				cin.clear();
				cin.ignore(100, '\n');
				cin >> varaus.Huone_numero;
			}
			while (tarkistus_kahden_huoneet(varaus.Huone_numero, kahden_min_huoneet, max_huoneet) == false) {
				cout << "Huone numero on virheellinen\n" << "Anna uusi huone numero " << "(" << kahden_min_huoneet << "-" << max_huoneet << "): ";
				cin.clear();
				cin.ignore(100, '\n');
				cin >> varaus.Huone_numero;
				//syötteen tarkistus
				while (!cin) {
					cout << "Virhe! Syötä huone numero " << "(" << kahden_min_huoneet << "-" << max_huoneet << "): \n";
					cin.clear();
					cin.ignore(100, '\n');
					cin >> varaus.Huone_numero;
				}
			}
		}
		//jos huone on vapaa
		if (tarkistus_kahden_huoneet(varaus.Huone_numero, kahden_min_huoneet, max_huoneet) == true) {
			if (tarkistus_Huone(varaus.Huone_numero) == true) {
				huoneet[varaus.Huone_numero - 1] = 1; //varaa huoneen
				cout << "Anna moneksi yöksi haluat varata huoneen: ";
				cin.clear();
				cin.ignore(100, '\n');
				cin >> varaus.yot; //käyttäjä antaa moneksi yöksi haluaa varatahuoneen
				//syötteen tarkistus
				while (!cin) {
					cout << "Virhe!\n" << "Anna moneksi yöksi haluat varata huoneen:\n";
					cin.clear();
					cin.ignore(100, '\n');
					cin >> varaus.yot;
				}
				alennus = luoalennus();
				varaus.loppusumma = varaus.yot * kahden_huoneen_hinta * alennus; //laskee varauksen hinnan
				cout << "Varauksesi hinta on " << varaus.loppusumma << " euroa\n\n";
				return varaus;
			}
		}
	}
}
//luo parillisen huonemäärän 40-300 väliltä
int luoHuonemaara() {
	int Huoneet;
	srand(time(0));
	Huoneet = 40 + (rand() % 261);
	if (Huoneet % 2 == 0) {
		return Huoneet;
	}
	else {
		while (Huoneet % 2 != 0) {
			Huoneet = 40 + (rand() % 261);
		}
		return Huoneet;
	}
}
//tarkastaa että annetulla varausnumerolla ei ole varauksia
bool varausten_haku_tarkistus_numerolla(int x) {
	for (int i = 0; i < 300; i++) {
		if (varaukset[i].Varaus_numero == x) {
			return false;
		}
	}
	return true;
}
//tarkastaa että annetulla nimellä ei ole varauksia
bool varausten_haku_tarkistus_nimella(string x) {
	for (int i = 0; i < 300; i++) {
		if (varaukset[i].nimi == x) {
			return false;
		}
	}
	return true;
}

int main() {
	//Alku hommia
	setlocale(LC_ALL, "fi_FI");
	char userInput, Syöte;
	int x = 0;
	int max_huoneet, yhden_huoneet;

	for (int a = 0; a < 300; a++) { //alustetaan kaikki huoneet pois
		huoneet[a] = 3;
	}
	max_huoneet = luoHuonemaara(); // luodaan max huoneiden määrä
	yhden_huoneet = max_huoneet / 2;
	for (int i = 0; i < max_huoneet; i++) { // alustetaan max määrä huoneita
		huoneet[i] = 0;
	}

	//varsinainen Ohjelma alkaa
	cout << "TERVETULOA HOTELLIIN" << endl;
	cout << "\n---------------------------------------------------------" << endl;

	//VALIKKO
	cout << "Valitse mitä haluat tehdä painamalla 1-3 \n";
	cout << "1: Huoneen varaus\n";		//Huoneen varaus
	cout << "2: Katso varauksia\n";	//Katso varauksia
	cout << "3: Lopeta\n";				//Lopeta ohjelma
	cin >> userInput;
		while (syötteen_tarkistus(userInput) == false) { //syötteen tarkistus
			cout << "Error. Anna uusi syöte: ";
			cin.clear();
			cin.ignore(100, '\n');
			cin >> userInput;
	}
	cout << "\n------------------------------------------------------------------------------------\n" << endl;

	while (userInput != '4') {
		if (userInput == '0') {
			//VALIKKO
			cout << "\nValitse mitä haluat tehdä painamalla 1-3 \n";
			cout << "1: Huoneen varaus\n";
			cout << "2: Katso varauksia\n";
			cout << "3: Lopeta\n";
			cin >> userInput;
				while (syötteen_tarkistus(userInput) == false) { //syötteen tarkistus
					cout << "Error. Anna uusi syöte: ";
					cin.clear();
					cin.ignore(100, '\n');
					cin >> userInput;
			}
			cout << "\n------------------------------------------------------------------------------------\n" << endl;
		}
		if (userInput == '1') { // varauksien luonti ja tallennus taulukkoon
			varaus varaus1 = luoVaraus(max_huoneet, yhden_huoneet);
			varaukset[x] = varaus1;
			x++;
			//Palaa valikkoon
			userInput = '0';
		}

		//varauksien haku
		if (userInput == '2') {
			int varaus_numero;
			string nimi;
			cout << "Haluatko hakea\n" << "1: Varaus numerolla\n" << "2: Varaus nimellä\n" << "3: Palaa valikkoon\n";
			cin.clear();
			cin >> Syöte;
				while (Syöte != '1' && Syöte != '2' && Syöte != '3') {
					cout << "Virhe!\n" << "1: Varaus numerolla\n" << "2: Varaus nimellä\n" << "3: Palaa valikkoon\n";
					cin.clear();
					cin.ignore(100, '\n');
					cin >> Syöte;
				}
			//Katsotaan varauksia varausnumerolla
			if (Syöte == '1') {
				cout << "Anna varausnumero:";
				cin.clear();
				cin.ignore(100, '\n');
				cin >> varaus_numero;
				//syötteen tarkistus
				while (!cin) {
					cout << "Virhe! Syötä varausnumero: \n";
					cin.clear();
					cin.ignore(100, '\n');
					cin >> varaus_numero;
				}
				for (int l = 0; l < 300; l++) {
					if (varaukset[l].Varaus_numero == varaus_numero) {
						cout << "\nVaraajan nimi: " << varaukset[l].nimi << "\n";
						cout << "Varaus numero: " << varaukset[l].Varaus_numero << "\n";
						cout << "Huone koko: " << varaukset[l].Huone_koko << "\n";
						cout << "Huone huonenumero: " << varaukset[l].Huone_numero << "\n";
						cout << "Moneksi yöksi varattu: " << varaukset[l].yot << "\n";
						cout << "Hinta: " << varaukset[l].loppusumma << "\n\n";
					}
				}
				if (varausten_haku_tarkistus_numerolla(varaus_numero) == true) {
					cout << "\nVarausnumerolla ei ole varauksia\n" << endl;
				}
			}
			//Katsotaan varauksia nimellä
			if (Syöte == '2') {
				cout << "Anna varaajan nimi:";
				cin.clear();
				cin.ignore(100, '\n');
				getline(cin >> ws, nimi);
				for (int l = 0; l < 300; l++) {
					if (varaukset[l].nimi == nimi) {
						cout << "\nVaraajan nimi: " << varaukset[l].nimi << "\n";
						cout << "Varaus numero: " << varaukset[l].Varaus_numero << "\n";
						cout << "Huone koko: " << varaukset[l].Huone_koko << "\n";
						cout << "Huone huonenumero: " << varaukset[l].Huone_numero << "\n";
						cout << "Moneksi yöksi varattu: " << varaukset[l].yot << "\n";
						cout << "Hinta: " << varaukset[l].loppusumma << "\n\n";
					}
				}
				if (varausten_haku_tarkistus_nimella(nimi) == true) {
					cout << "\nTällä nimellä ei varauksia.\n" << endl;
				}
			}
			//Palaa takaisin valikkoon
			if (Syöte == '3') {
				userInput = '0';
			}
		}
		//Ohjelman sulkeminen
		while (userInput == '3') {
			cout << "Näkemiin! Kiitos käynnistä.";
			return 0;
		}
	}
}
