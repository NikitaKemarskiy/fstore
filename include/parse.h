#ifndef parse
#define parse

void printHelp(char*);
void printOptions(int, char**);
char* getCommand(int, char**);
char* parseSaveCommand(int, char**);
char* parseGetCommand(int, char**);

#endif