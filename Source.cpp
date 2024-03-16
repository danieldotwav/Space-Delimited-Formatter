#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void purgeInputErrors(std::string error_message);

int main() {
	std::string default_file_name = "Formatted.txt";
	std::string formatted_file_name;
	std::ifstream infile("input.txt");

	if (!infile) {
		std::cout << "Error: Unable to open input file. Terminating program.\n\n";
		exit(EXIT_FAILURE);
	}

	std::cout << "Enter Formatted File Name: ";
	std::cin >> formatted_file_name;

	std::ofstream outfile;
	if (!std::cin) {
		purgeInputErrors("Invalid File Name");
		outfile.open(default_file_name);
		std::cout << "File Saved as:" << default_file_name << std::endl;
	}
	else {
		outfile.open(formatted_file_name);
		std::cout << "File Saved as:" << formatted_file_name << std::endl;
	}

	std::string line;
	while (getline(infile, line)) {
		outfile << line << ' ';
		std::cout << line << ' ';
	}

	infile.close();
	outfile.close();

	return 0;
}

void purgeInputErrors(std::string error_message) {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << error_message << std::endl;
}