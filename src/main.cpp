#include <iostream>
#include <cstring>
#include <cstdio>
#include <unistd.h>
#include "parse.h"
#include "storage.h"
using namespace std;

int main(int argc, char** argv) {
	// Variables
	char userPath[FILENAME_MAX]; // FILENAME_MAX contains a number of symbols enough to store any filename
	char* userCommand;
	char* fileName;
	
	// Initialize variables
	getcwd(userPath, FILENAME_MAX);
	userCommand = getCommand(argc, argv);

	// Code
	if (strcmp(userCommand, "save") == 0) { // Save command
		fileName = parseSaveCommand(argc, argv); // Get passed filename
	} else if (strcmp(userCommand, "get") == 0) { // Get command
		fileName = parseGetCommand(argc, argv); // Get passed filename
	} else if (strcmp(userCommand, "help") == 0) { // Help command
		printHelp(); // Print help information
	} else { // Error: invalid command
		cout << userCommand << endl; // Print error message
		cout << "Use --help option to print help information" << endl;
	}
	
	return 0;
}