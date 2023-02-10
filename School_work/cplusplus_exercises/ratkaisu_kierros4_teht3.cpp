#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	ofstream outputFile;
	string filename = "index.html";
	string name, about;

	cout << "Enter your fullname: ";
	getline(cin, name);
	cout << "Describe yourself: ";
	getline(cin, about);

	outputFile.open("index.html");
	if (!outputFile) {
		cout << "File open failure";
	}
	outputFile << "<html>\n<head></head>\n<body>\n<center>\n<h1>" << name << "</h1>\n";
	outputFile << "</center>\n<hr />" << about << "<hr />\n</body>\n</html>";
	outputFile.close();

	return 0;
}