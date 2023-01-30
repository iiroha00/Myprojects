#include <iostream>
using namespace std;

enum kolmio { epasaannollinen=1, tasakylkinen, tasasivuinen, suorakulmainen };

bool onKolmiollinen(double a, double b, double c, kolmio *tyyppi);

int main() {
	double sivu1, sivu2, sivu3;
	bool status;
	kolmio tyyppi, *tyyppi_p=&tyyppi;
	cout << "Anna sivun 1 pituus: ";
	cin >> sivu1;
	cout << "Anna sivun 2 pituus: ";
	cin >> sivu2;
	cout << "Anna sivun 3 pituus: ";
	cin >> sivu3;
	status=onKolmiollinen(sivu1, sivu2, sivu3, tyyppi_p);
	if (status == true) {
		if (tyyppi == epasaannollinen)
			cout << "Voidaan muodostaa epasaannollinen kolmio" << endl;
		if (tyyppi == tasakylkinen) {
			cout << "Voidaan muodostaa tasakylkinen kolmio" << endl;
		}
		if (tyyppi == tasasivuinen) {
			cout << "Voidaan muodostaa tasasivuinen kolmio" << endl;
		}
		if (tyyppi == suorakulmainen) {
			cout << "Voidaan muodostaa suorakulmainen kolmio" << endl;
		}
	}
	if (status == false) {
		cout << "Ei voida muodostaa kolmiota" << endl;
	}
	
	return 0;
}

bool onKolmiollinen(double a, double b, double c, kolmio *tyyppi) {
	if (a * a == b * b + c * c || b * b == c * c + a * a || c * c == a * a + b * b) {
		*tyyppi = suorakulmainen;
		return true;
	}
	if (a == b && a == c && b == c) {
		*tyyppi = tasasivuinen;
		return true;
	}
	if (a == b || a == c || b == c) {
		*tyyppi = tasakylkinen;
		return true;
	}
	if (a != b || a != c || b != c) {
		*tyyppi = epasaannollinen;
		return true;
	}
	return false;
}