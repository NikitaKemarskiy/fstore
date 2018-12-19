#include <climits>
#include <cstring>
#include <unistd.h>
#include "storage.h"
using namespace std;

char* getExecPath() { // Function that gets fstore executable path
	char execPath[PATH_MAX];
	int count = readlink("/proc/self/exe", execPath, PATH_MAX);
	if (count > 0) { // Executable path was get
		int index; 
		char execPath_[PATH_MAX];
		for (int i = strlen(execPath) - 1; i >= 0; i--) { // Find path without executable name at the end
			if (execPath[i] == '/') {
				index = i;
				break;
			}
		}
		strncpy(execPath_, execPath, index + 1);
		char* ptr = execPath_;
		return ptr; // Return path without executable name at the end
	} 
	return "Error: can't get fstore executable path"; // Error: can't get fstore executable path
}
