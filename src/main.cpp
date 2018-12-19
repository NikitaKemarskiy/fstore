#include <iostream>
#include <cstring>
#include <climits>
#include <unistd.h>
#include "parse.h"
#include "path.h"
#include "storage.h"
using namespace std;

int main(int argc, char** argv) {
	// Variables
	char userPath[PATH_MAX]; // PATH_MAX contains a number of symbols enough to store any system path
	char* execPath;
	char* userCommand;
	char* fileName;
	
	// Initialize variables
	getcwd(userPath, PATH_MAX); // Get user's current path
	execPath = getExecPath(); // Get fstore executable path
	userCommand = getCommand(argc, argv); // Get passed command

	// Code
	if (execPath[0] != '/') { // Error: can't get fstore executable path
		cout << execPath << endl;
		return 0;
	}
	if (strcmp(userCommand, "save") == 0) { // Save command
		fileName = parseSaveCommand(argc, argv); // Get passed filename
	} else if (strcmp(userCommand, "get") == 0) { // Get command
		fileName = parseGetCommand(argc, argv); // Get passed filename
	} else if (strcmp(userCommand, "help") == 0) { // Help command
		printHelp("./files/help.txt"); // Print help information
	} else { // Error: invalid command
		cout << userCommand << endl; // Print error message
		cout << "Use --help option to print help information" << endl;
	}
	
	return 0;
}