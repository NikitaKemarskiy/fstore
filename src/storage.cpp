#include <cstring>
#include <climits>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "storage.h"
#include "path.h"
using namespace std;

// Function that saves passed file to storage
void saveFile(char* filePath, char* storagePath) {
	char newFilePath[PATH_MAX];
	char* fileName = getLastSegment(filePath);
	strcat(newFilePath, storagePath);
	addSegment(newFilePath, fileName);

	ifstream fin;
	ofstream fout;
	fin.open(filePath, ios::in | ios::binary); // Open the filestream for reading
	
	if (fin.is_open()) { // Read stream is opened
		fout.open(newFilePath, ios::out | ios::trunc | ios::binary); // Open the filestream for writing
		if (fout.is_open()) { // Write stream is opened
			fout << fin.rdbuf();
		} else {
			cout << "Permission denied. Use sudo instead" << endl;
		}
	} else {
		cout << "Can't get your file. Please check the name of your file" << endl;
	}

	fin.close();
	fout.close();
}

// Function that saves passed file to storage
void saveFile(char* filePath, char* storagePath, char* newName) {
	char newFilePath[PATH_MAX];
	char* fileName = getLastSegment(filePath);
	strcat(newFilePath, storagePath);
	addSegment(newFilePath, newName);

	ifstream fin;
	ofstream fout;
	fin.open(filePath, ios::in | ios::binary); // Open the filestream for reading
	
	if (fin.is_open()) { // Read stream is opened
		fout.open(newFilePath, ios::out | ios::trunc | ios::binary); // Open the filestream for writing
		if (fout.is_open()) { // Write stream is opened
			fout << fin.rdbuf();
		} else {
			cout << "Permission denied. Use sudo instead" << endl;
		}
	} else {
		cout << "Can't get your file. Please check the name of your file" << endl;
	}

	fin.close();
	fout.close();
}

// Function that copies file with a specific filename to the current working directory
void getFile(char* newFilePath, char* storagePath) {
	char filePath[PATH_MAX];
	char* fileName = getLastSegment(newFilePath);
	strcpy(filePath, storagePath);
	addSegment(filePath, fileName);

	ifstream fin;
	ofstream fout;
	fin.open(filePath, ios::in | ios::binary); // Open the filestream for reading

	if (fin.is_open()) { // Read stream is opened
		fout.open(newFilePath, ios::out | ios::trunc | ios::binary); // Open the filestream for writing
		if (fout.is_open()) { // Write stream is opened
			fout << fin.rdbuf();
		} else {
			cout << "Permission denied. Use sudo instead" << endl;
		}
	} else {
		cout << "Can't get your file. Is it in the storage?" << endl;
	}

	fin.close();
	fout.close();
}

// Function that removes user's file from the storage
void removeFile(char* fileName, char* storagePath) {
	char filePath[PATH_MAX];
	strcpy(filePath, storagePath);
	addSegment(filePath, fileName);

	if (remove(filePath)) {
		cout << "Can't remove your file. Is it in the storage?" << endl;
	}
}

