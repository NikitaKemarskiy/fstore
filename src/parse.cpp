#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "parse.h"
using namespace std;

void printHelp(char* helpfile) { // Function that prints help information
	string buff; // String for containing data from file

	ifstream fin;
	fin.open(helpfile, ios_base::in); // Open the filestream for reading

	if (!fin.is_open()) { // Can't open file
		cout << "Error: can't get help information" << endl;
	} else { // File was opened
		while (!fin.eof()) { // While it's not end of file
			getline(fin, buff); // Read current line from file
			cout << buff << endl; // Print it with a newline
		}
	}

	fin.close(); // Close the filestream
}

void printOptions(int argc, char** argv) { // Function that prints console parameters
	for (int i = 0; i < argc; i++) {
		cout << "Option " << (i + 1) << ": " << argv[i] << endl;
	}
}

char* getCommand(int argc, char** argv) { // Function that indicates which command was called by user
	for (int i = 0; i < argc; i++) {
		if (i < (argc - 1)) {
			if (strcmp(argv[i], "--save") == 0 || strcmp(argv[i], "-s") == 0) { // Save command
				return "save";
			}
			if (strcmp(argv[i], "--get") == 0 || strcmp(argv[i], "-g") == 0) { // Get command
				return "get";
			}
		}
		if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) { // Help command
			return "help";
		}
	}
	return "Error: invalid options were passed"; // Error: invalid command
}

char* parseSaveCommand(int argc, char** argv) { // Function that parses save command options
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "--save") == 0 || strcmp(argv[i], "-s") == 0) { // Save command was encountered
			return argv[i + 1];
		}
	}
}

char* parseGetCommand(int argc, char** argv) { // Function that parses get command options
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "--get") == 0 || strcmp(argv[i], "-g") == 0) { // Get command was encountered
			return argv[i + 1];
		}
	}
}