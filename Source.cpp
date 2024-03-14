#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
	ifstream infile("input.txt");
	ofstream outfile("Formatted.txt");

	if (!infile || !outfile) {
		cout << "Error: Unable to open one of more files\n\n";
		exit;
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