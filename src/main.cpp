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
	char storagePath[PATH_MAX]; // Variable for the help.txt file path
	char* execPath; // Variable for the fstore executable path
	char* userCommand; // Variable for the passed command
	char* fileName; // Variable for the passed filename
	
	// Initialize variables
	getcwd(userPath, PATH_MAX); // User's current path
	execPath = getExecPath(); // Fstore executable path
	userCommand = getCommand(argc, argv); // Passed command
	deleteLastSegment(projectPath, execPath); // Project root path
	strcpy(helpFilePath, projectPath); // Help file path
	addSegment(helpFilePath, "share");
	addSegment(helpFilePath, "fstore");
	addSegment(helpFilePath, "help.txt");
	strcpy(storagePath, projectPath);
	addSegment(storagePath, "share");
	addSegment(storagePath, "fstore");
	addSegment(storagePath, "storage");

	// Check if executable path is valid
	if (execPath[0] != '/') { // Error: can't get fstore executable path
		cout << execPath << endl;
		return 0;
	}

	// Get passed command and process it
	if (strcmp(userCommand, "save") == 0) { // Save command
		char filePath[PATH_MAX];
		fileName = parseSaveCommand(argc, argv); // Get passed filename
		strcat(filePath, userPath);
		addSegment(filePath, fileName);
		saveFile(filePath, storagePath);
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