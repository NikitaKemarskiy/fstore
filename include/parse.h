#ifndef parse
#define parse

void printOptions(int, char**);
void printHelp();
char* getCommand(int, char**);
char* parseSaveCommand(int, char**);
char* parseGetCommand(int, char**);

#endif