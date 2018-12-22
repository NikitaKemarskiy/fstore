#include <cstring>
#include <climits>
#include <iostream>
#include <fstream>
#include <string>
#include "storage.h"
#include "path.h"
using namespace std;

void saveFile(char* filePath, char* storagePath) { // Function that saves passed file to storage
	char newFilePath[PATH_MAX];
	char* fileName = getLastSegment(filePath);
	if (storagePath[strlen(storagePath)] != '/') {
		strcat(storagePath, "/");
	}
	strcat(newFilePath, storagePath);
	strcat(newFilePath, fileName);

	ifstream fin;
	ofstream fout;
	fin.open(filePath, ios::in | ios::binary); // Open the filestream for reading
	fout.open(newFilePath, ios::out | ios::trunc | ios::binary); // Open the filestream for writing

	if (fin.is_open() && fout.is_open()) {
		cout << "File was saved" << endl;
		fout << fin.rdbuf();
	} else {
		cout << "Permission denied. Use sudo instead" << endl;
	}

	fin.close();
	fout.close();
}

void getFile(char* fileName, char* userPath) { // Function that copies file with a specific filename to users current working directory
	//...
}
