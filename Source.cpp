#include <iostream>
#include <cstdlib> // Needed for EXIT_FAILURE
#include <limits> // Needed for std::numeric_limits
#include <string>
#include <fstream>
#include <sstream>

void purgeInputErrors(std::string error_message);
std::string getFormattedFileName();

int main() {
	std::string default_file_name = "Formatted.txt";
	std::string formatted_file_name;
	std::ifstream infile("input.txt");

	// Check if input file is opened successfully
	if (!infile) {
		std::cout << "Error: Unable to open input file. Terminating program.\n\n";
		exit(EXIT_FAILURE);
	}

	formatted_file_name = getFormattedFileName();
	std::ofstream outfile(formatted_file_name);

	// Check if output file is opened successfully
	if (!outfile) {
		std::cout << "Error: Unable to open output file. Terminating program.\n\n";
		exit(EXIT_FAILURE);
	}

	std::cout << "File Created Successfully as: " << formatted_file_name << std::endl << std::endl;

	// Loop through each word in the input file and remove any newline characters
	std::string line;
	while (getline(infile, line)) {
		outfile << line << ' ';
		std::cout << line << ' ';
	}

	std::cout << "File Saved Successfully" << default_file_name << std::endl;

	infile.close();
	outfile.close();

	std::cout << "\nTerminating Program...\n";
	return 0;
}

void purgeInputErrors(std::string error_message) {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << error_message << std::endl;
}

std::string getFormattedFileName() {
	std::string formatted_file_name;
	std::cout << "Enter Formatted File Name: ";
	std::cin >> formatted_file_name;

	if (!std::cin) {
		purgeInputErrors("Invalid File Name");
		formatted_file_name = "Output.txt";
	}
	else {
		// Ensure that there are no invalid characters in file name
		bool is_valid_name = true;
		int file_name_length = formatted_file_name.length();
		char current_letter;

		for (int i = 0; i < file_name_length && is_valid_name; ++i) {
			current_letter = formatted_file_name[i];
			if (ispunct(current_letter)) {
				// The only valid punctuation characters are '-' and '_'
				if (current_letter != '-' && current_letter != '_') {
					is_valid_name = false;
					formatted_file_name = "Output";
				}
			}
		}
	}
	
	// Add the .txt extension
	formatted_file_name.append(".txt");
	return formatted_file_name;
}