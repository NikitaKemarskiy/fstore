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
	strcat(newFilePath, storagePath);
	addSegment(newFilePath, fileName);

	ifstream fin;
	ofstream fout;
	fin.open(filePath, ios::in | ios::binary); // Open the filestream for reading
	fout.open(newFilePath, ios::out | ios::trunc | ios::binary); // Open the filestream for writing

	if (fin.is_open() && fout.is_open()) {
		fout << fin.rdbuf();
	} else {
		cout << "Permission denied. Use sudo instead" << endl;
	}

	fin.close(); // Close the filestreams
	fout.close();
}

void getFile(char* newFilePath, char* storagePath) { // Function that copies file with a specific filename to users current working directory
	char filePath[PATH_MAX];
	char* fileName = getLastSegment(newFilePath);
	strcpy(filePath, storagePath);
	addSegment(filePath, fileName);

	ifstream fin;
	ofstream fout;
	fin.open(filePath, ios::in | ios::binary); // Open the filestream for reading
	fout.open(newFilePath, ios::out | ios::trunc | ios::binary); // Open the filestream for writing

	if (fin.is_open() && fout.is_open()) {
		fout << fin.rdbuf();
	} else {
		cout << "Can't get your file. Did you save it?" << endl;
	}

	fin.close(); // Close the filestreams
	fout.close();
}
