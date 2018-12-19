#include "parse.h"
#include "storage.h"
#include <iostream>
#include <cstdio>
#include <unistd.h>
using namespace std;

int main(int argc, char** argv) {
	char buff[FILENAME_MAX]; // FILENAME_MAX contains a number of symbols enough to store any filename
	getcwd(buff, FILENAME_MAX);
	cout << buff << endl;
	return 0;
}