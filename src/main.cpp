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
	char projectPath[PATH_MAX]; // Variable for the project root path
	char helpFilePath[PATH_MAX]; // Variable for the help.txt file path
	char* execPath; // Variable for the fstore executable path
	char* userCommand; // Variable for the passed command
	char* fileName; // Variable for the passed filename
	
	// Initialize variables
	getcwd(userPath, PATH_MAX); // Get user's current path
	execPath = getExecPath(); // Get fstore executable path
	userCommand = getCommand(argc, argv); // Get passed command
	deleteLastSegment(projectPath, execPath); // Find project root path
	strcpy(helpFilePath, projectPath);
	addSegment(helpFilePath, "share");
	addSegment(helpFilePath, "fstore");
	addSegment(helpFilePath, "help.txt");

	// DEBUG
	cout << "Executable path: " << execPath << endl;
	cout << "Project path: " << projectPath << endl;
	cout << "Help file path: " << helpFilePath << endl;

	// Check if executable path is valid
	if (execPath[0] != '/') { // Error: can't get fstore executable path
		cout << execPath << endl;
		return 0;
	}

	// Get passed command and process it
	if (strcmp(userCommand, "save") == 0) { // Save command
		fileName = parseSaveCommand(argc, argv); // Get passed filename
	} else if (strcmp(userCommand, "get") == 0) { // Get command
		fileName = parseGetCommand(argc, argv); // Get passed filename
	} else if (strcmp(userCommand, "help") == 0) { // Help command
		printHelp(helpFilePath); // Print help information
	} else { // Error: invalid command
		cout << userCommand << endl; // Print error message
		cout << "Use --help option to print help information" << endl;
	}

	return 0;
}