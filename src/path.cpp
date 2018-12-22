#include <climits>
#include <cstring>
#include <climits>
#include <unistd.h>
#include "path.h"

char* getExecPath() { // Function that returns fstore executable path
	char execPath[PATH_MAX];
	int count = readlink("/proc/self/exe", execPath, PATH_MAX);
	if (count > 0) { // Executable path was get
		int index; 
		char execPath_[PATH_MAX];
		deleteLastSegment(execPath_, execPath); // Delete executable name from path

		char* ptr = execPath_;
		return ptr; // Return path without executable name at the end
	} 
	return "Error: can't get fstore executable path"; // Error: can't get fstore executable path
}

char* getLastSegment(char* fullPath) { // Function that returns last segment of specified path
	int length = strlen(fullPath);
	int index = 0;
	char segment[PATH_MAX];
	// Check if there's a slash at the end 
	if (fullPath[length - 1] == '/') { // There's a slash at the end
		length--; // Remove it
	}
	for (int i = length; i >= 0; i--) { // Find last slash in path
		if (fullPath[i] == '/') { // Last slash was found
			index = i; // Save the index
			break;
		}
	}
	strncpy(segment, fullPath + index + 1, length - index - 1);
	char* ptr = segment;
	return ptr; // Return last segment
}

void deleteLastSegment(char* newPath, char* oldPath) { // Function that deletes last segment from passed path
	int length = strlen(oldPath);
	int index = 0;
	// Check if there's a slash at the end 
	if (oldPath[length - 1] == '/') { // There's a slash at the end
		length--; // Remove it
	}
	for (int i = length - 1; i >= 0; i--) { // Find last slash in path
		if (oldPath[i] == '/') { // Last slash was found
			index = i; // Save the index
			break;
		}
	}
	strncpy(newPath, oldPath, index + 1); // Save new path to the newPath variable
}

void addSegment(char* oldPath, char* segment) { // Function that adds a segment to the path
	int length = strlen(oldPath);
	if (segment[0] != '/') { // There's no slash at the beginning of the segment
		if (oldPath[length - 1] != '/') { // There's no slash at the end of the path and no slash at the beginning of the segment
			strcat(oldPath, "/");
			strcat(oldPath, segment);
		} else { // There's a slash at the end of the path and no slash at the beginning of the segment
			strcat(oldPath, segment);
		}
	} else { // There's a slash at the beginning of the segment
		if (oldPath[length - 1] == '/') { // There's a slash at the end of the path and a slash at the beginning of the segment
			strcat(oldPath, segment + 1);
		} else { // There's no slash at the end of the path and a slash at the beginning of the segment
			strcat(oldPath, segment);
		}
	}
}