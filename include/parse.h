#ifndef parse
#define parse

void printHelp(char*);
void printOptions(int, char**);
bool newNameDefined(int, char**);
char* getCommand(int, char**);
char* parseSaveCommand(int, char**);
char* parseGetCommand(int, char**);
char* parseRemoveCommand(int, char**);
char* parseNameCommand(int, char**);

#endif