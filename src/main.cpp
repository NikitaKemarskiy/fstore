#include <iostream>
#include <cstdio>
#include <unistd.h>
#include "parse.h"
#include "storage.h"
using namespace std;

int main(int argc, char** argv) {
	// Variables
	char userPath[FILENAME_MAX]; // FILENAME_MAX contains a number of symbols enough to store any filename
	char* userCommand;
	// Initialize variables
	getcwd(userPath, FILENAME_MAX);
	userCommand = getCommand(argc, argv);
	// Debug output
	cout << "User path: " << userPath << endl;
	cout << "User command: " << userCommand << endl;
	printOptions(argc, argv);
	
	return 0;
}