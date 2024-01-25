#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

void searcher(string &searchWord, string &searchFile);
void searcher_Options(string& searchWord, string& searchFile, string &searchOpt);
void reverse_searcher_Options(string& searchWord, string& searchFile, string& searchOpt);
void caseinsensitive_search(string& searchWord, string& searchFile, string& searchOpt);
bool fileSize(string& searchFile);

int main(int argc, char *argv[]) {
	string data, search;
	int position;
	bool result;
	if (argc == 1) {

		// Ask the user for data string which we search from
		cout << "Give a string from which to search for: ";
		getline(cin, data);
		// Ask the user for search string to search for from data string 
		cout << "Give search string: ";
		getline(cin, search);

		// Searches for search string from data string and stores the position if found
		position = data.find(search);
		// if not found
		if (position == -1) {
			cout << "\"" << search << "\"" << " NOT found in " << "\"" << data << "\"" << endl;
		}
		// Outputs the answers
		if (position > -1) {
			cout << "\"" << search << "\"" << " found in " << "\"" << data << "\"" << " in position " << position << endl;
		}
		return 0;
	}
	// if user input starting argument in cmd
	if (argc == 3) { // if no options were given but search word and file was given.
		string searchWord = argv[1];
		string searchFile = argv[2];
		try
		{
			result = fileSize(searchFile); // tries to get file size
		}
		catch (const char* msg)
		{
			cout << "An exception occurred. Exception Nr. "<< msg << endl;
			cout << "Could not find out the size of file \"" << searchFile << "\"" << endl;
			return 0;
		}
		searcher(searchWord, searchFile);
	}
	if (argc == 4) {
		string searchOpt = argv[1];
		string searchWord = argv[2];
		string searchFile = argv[3];
		try
		{
			result = fileSize(searchFile); // tries to get file size
		}
		catch (const char* msg)
		{
			cout << "An exception occurred. Exception Nr. " << msg << endl;
			cout << "Could not find out the size of file \"" << searchFile << "\"" << endl;
			return 0;
		}
		int reverse = searchOpt.find("r"); // checks reverse
		int caseinsensitive = searchOpt.find("i"); // checks caseinsensitive
		int option_prefix1 = searchOpt.find("-");
		int option_prefix2 = searchOpt.find("o");
		try
		{
			if (option_prefix1 == 0 && option_prefix2 == 1) {
				searchOpt.erase(0, 2); // removes "-o" from searchOpt or the first two letter that should be "-o"
			}
			else {
				throw "ERROR: Option prefix -o not included before options"; // if search option prefix "-o" are not the first letters in searchOpt throw error
				return 0;
			}
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			return 0;
		}
		if (reverse > -1 && caseinsensitive > -1) {
			caseinsensitive_search(searchWord, searchFile, searchOpt); // if reverse and caseinsensitive is on
		}
		else if (reverse > -1 && caseinsensitive ==-1) { // if reverse is on and caseinsensitive isnt.
			reverse_searcher_Options(searchWord, searchFile, searchOpt);
		}
		else if (caseinsensitive > -1 && reverse ==-1) { // caseinsensitive is on and reverse isnt
			caseinsensitive_search(searchWord, searchFile, searchOpt);
		}
		else { // caseinsensitive and reverse are off
			searcher_Options(searchWord, searchFile, searchOpt);
		}
	}
	return 0;
}
// Performs the searching in the file
void searcher(string &searchWord, string &searchFile) {
	ifstream inputFile;
	string line;
	int position;
	try
	{
		inputFile.open(searchFile); // opens the file
		if (!inputFile) {
			throw "File open failure";
		}
	}
	catch (const char* error)
	{
		cout << error << endl;
	}
	if (inputFile) {
		while (getline(inputFile, line)) { // while there is a row of text in the file does this
		position = line.find(searchWord); // searches line of text for given search word
		if (position > -1) { 
			cout << line << endl; // if search word was found in the line prints the line of text
			}
		}
		inputFile.close(); // closes the file
	}
}

void searcher_Options(string& searchWord, string& searchFile, string& searchOpt) {
	ifstream inputFile;
	string line;
	int position, row = 0, count = 0, l,o;
	l = searchOpt.find("l");
	o = searchOpt.find("o");
	try
	{
		inputFile.open(searchFile); // opens the file
		if (!inputFile) {
			throw "File open failure";
		}
	}
	catch (const char* error)
	{
		cout << error << endl;
	}
	if (inputFile) {
		while (getline(inputFile, line)) { // while there is a row of text in the file does this
			position = line.find(searchWord); // searches line of text for given search word
			row++;
			if (position > -1) {
				if (l>-1 && o == -1) {
					cout << row << ": " << line << endl; // prints the line and row number
				}
				else if (o>-1 && l == -1) {
					cout << line << endl; //prints the line and adds 1 to count
					count++;
				}
				else if (l>-1 && o>-1) {
					cout << row << ": " << line << endl; // prints the line and row number and add 1 to count
					count++;
				}
				else {
					cout << line << endl; // prints the line
				}
			}
		}
		if (o>-1) { // if option o is used anywhere prints occurrences of search word
			cout << "\nOccurrences of lines containing \"" << searchWord << "\": " << count << endl;
		}
		inputFile.close(); // closes the file
	}
}

void reverse_searcher_Options(string& searchWord, string& searchFile, string& searchOpt) {
	ifstream inputFile;
	string line;
	int position, row = 0, count = 0, r, l, o;
	r = searchOpt.find("r"); // checks reverse should be on we are in reverse_searcher_options function
	l = searchOpt.find("l"); // checks l
	o = searchOpt.find("o"); // checks occurrences
	try
	{
		inputFile.open(searchFile); // opens the file
		if (!inputFile) {
			throw "File open failure";
		}
	}
	catch (const char* error)
	{
		cout << error << endl;
	}
	if (inputFile) {
		while (getline(inputFile, line)) { // while there is a row of text in the file does this
			position = line.find(searchWord); // searches line of text for given search word
			row++;
			if (position == -1) {
				if (r > -1 && l == -1 && o == -1) { // if only reverse is on
						cout << line << endl;
				}
				else if (r > -1 && l > -1 && o == -1) { // if l and reverse is on
					cout << row << ": " << line << endl;
				}
				else if (r > -1 && o > -1 && l == -1) { // if occurrences and reverse is on
					cout << line << endl;
					count++;
				}
				else if (r>-1 && l > -1 && o > -1) { // if l and occurrences and reverse is on
					cout << row << ": " << line << endl;
					count++;
				}
			}
		}
		if (o>-1) { // if option o is used anywhere prints occurrences of search word
			cout << "\nOccurrences of lines not containing \"" << searchWord << "\": " << count << endl;
		}
		inputFile.close(); // closes the file
	}
}
void caseinsensitive_search(string& searchWord, string& searchFile, string& searchOpt) {
	ifstream inputFile;
	string line, line_original, searchWord_original;
	int position, row = 0, count = 0, r,i,l,o;
	r = searchOpt.find("r"); // checks if reverse option is on
	i = searchOpt.find("i"); // checks if case insensitive option is on. this should be on because we are in caseinsensitive_search function
	l = searchOpt.find("l"); // checks if l is in options
	o = searchOpt.find("o"); // checks if o is in options
	searchWord_original = searchWord; // stores the original searchWord
	transform(searchWord.begin(), searchWord.end(), searchWord.begin(), ::tolower); // makes the search word all lower case
	try
	{
		inputFile.open(searchFile); // opens the file
		if (!inputFile) {
			throw "File open failure";
		}
	}
	catch (const char* error)
	{
		cout << error << endl;
	}
	if (inputFile) {
		while (getline(inputFile, line)) {	// while there is a row of text in the file does this
			line_original = line;	// stores the original line
			transform(line.begin(), line.end(), line.begin(), ::tolower);// makes the line all lower case
			position = line.find(searchWord);// searches for the search word in line.
			row++;
			if (r > -1) { // if reverse search is on does one of these options
				if (position == -1) {
					if (r > -1 && i > -1 && l == -1 && o == -1) { // reverse and case insensitive
						cout << line_original << endl;
					}
					else if (r > -1 && l > -1 && i > -1 && o == -1) { // with row number l option
						cout << row << ": " << line_original << endl;
					}
					else if (r > -1 && o > -1 && i > -1 && l == -1) { // with occurrences
						cout << line_original << endl;
						count++;
					}
					else if(r > -1 && o > -1 && l > -1 && o > -1 ) { //with occurrences and row number
						cout << row << ": " << line_original << endl;
						count++;
					}
				}
			}
			if (position > -1) {
				if (i > -1 && r == -1 && l == -1 && o == -1) { // only case insensitive
					cout << line_original << endl;
				}
				else if (i > -1 && l > -1 && r == -1 && o == -1) { // with row number
					cout << row << ": " << line_original << endl;
				}
				else if (i > -1 && o > -1 && r == -1 && l == -1) { // with occurrences
					cout << line_original << endl;
					count++;
				}
				else if (i > -1 && o > -1 && l > -1 && r == -1) { // with row and occurrences
					cout << row << ": " << line_original << endl;
					count++;
				}
			}
		}
		if (o>-1 && r == -1) { // if occurrences is on and reverse is not
			cout << "\nOccurrences of lines containing \"" << searchWord_original << "\": " << count << endl;
		}
		else if (o>-1 && r > -1) { // if occurrences is on and reverse is on
			cout << "\nOccurrences of lines not containing \"" << searchWord_original << "\": " << count << endl;
		}
		inputFile.close(); // closes the file
	}
}
bool fileSize(string& searchFile) {
	ifstream infile(searchFile, ios::binary);
	infile.seekg(0, ios::end);
	int file_size = infile.tellg(); // tells the size in bytes
	infile.close();
	if (file_size == -1) {
		throw "-1";
	}
	else {
		return true;
	}
}