#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

void purgeInputErrors(string error_message);

int main() {
	string default_file_name = "Formatted.txt";
	string formatted_file_name;
	ifstream infile("input.txt");

	if (!infile) {
		cout << "Error: Unable to open input file. Terminating program.\n\n";
		exit(EXIT_FAILURE);
	}

	cout << "Enter Formatted File Name: ";
	cin >> formatted_file_name;

	ofstream outfile;
	if (!cin) {
		purgeInputErrors("Invalid File Name");
		outfile.open(default_file_name);
		cout << "File Saved as:" << default_file_name << endl;
	}
	else {
		outfile.open(formatted_file_name);
		cout << "File Saved as:" << formatted_file_name << endl;
	}

	string line;
	while (getline(infile, line)) {
		outfile << line << ' ';
		cout << line << ' ';
	}

	infile.close();
	outfile.close();

	return 0;
}

void purgeInputErrors(string error_message) {
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << error_message << endl;
}