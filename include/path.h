#ifndef path
#define path

char* getExecPath();
char* getLastSegment(char*);
void deleteLastSegment(char*, char*);
void addSegment(char*, char*);

#endif