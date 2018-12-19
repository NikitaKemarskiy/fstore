#include <iostream>
#include <cstring>
#include "parse.h"
using namespace std;

void printOptions(int argc, char** argv) {
	for (int i = 0; i < argc; i++) {
		cout << "Option " << (i + 1) << ": " << argv[i] << endl;
	}
}

char* getCommand(int argc, char** argv) {
	for (int i = 0; i < argc; i++) {
		if (i < (argc - 1)) {
			if (strcmp(argv[i], "--save") == 0 || strcmp(argv[i], "-s") == 0) {
				return (char*)"save";
			}
			if (strcmp(argv[i], "--get") == 0 || strcmp(argv[i], "-g") == 0) {
				return (char*)"get";
			}
		}
		if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
			return (char*)"help";
		}
	}
	return (char*)"Error: invalid options were passed.";
}

char* parseSaveCommand(int argc, char** argv) {
	//...
}

char* parseGetCommand(int argc, char** argv) {
	//...
}