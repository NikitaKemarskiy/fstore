#Phony targets
.PHONY: all clean assemble install uninstall

#Variables
CXX = g++
CXXFLAGS = -I ./include
NAME = fstore
PREFIX = /usr/local
BIN = ./bin
OBJ = ./obj
SRC = ./src
FILES = ./files
INCLUDE = ./include

#Default target
all: $(OBJ)/main.o $(OBJ)/parse.o $(OBJ)/storage.o $(BIN)/fstore

#Clean target
clean:
	rm -f $(OBJ)/*.o

#Assembling
assemble: $(OBJ)/main.o $(OBJ)/parse.o $(OBJ)/storage.o

#Installation
install:
	mkdir -p $(PREFIX)/bin
	mkdir -p $(PREFIX)/src
	mkdir -p $(PREFIX)/share
	mkdir -p $(PREFIX)/include
	mkdir -p $(PREFIX)/src/$(NAME)
	mkdir -p $(PREFIX)/share/$(NAME)
	mkdir -p $(PREFIX)/include/$(NAME)
	mkdir -p $(PREFIX)/share/$(NAME)/storage
	install $(BIN)/fstore $(PREFIX)/bin/
	install $(SRC)/main.cpp $(PREFIX)/src/$(NAME)/
	install $(SRC)/parse.cpp $(PREFIX)/src/$(NAME)/
	install $(SRC)/storage.cpp $(PREFIX)/src/$(NAME)/
	install $(FILES)/help.txt $(PREFIX)/share/$(NAME)/
	install $(INCLUDE)/parse.h $(PREFIX)/include/$(NAME)/
	install $(INCLUDE)/storage.h $(PREFIX)/include/$(NAME)/

#Uninstallation
uninstall:
	rm -f $(PREFIX)/bin/$(NAME)
	rm -f $(PREFIX)/share/help.txt
	rm -rf $(PREFIX)/src/$(NAME)
	rm -rf $(PREFIX)/share/$(NAME)
	rm -rf $(PREFIX)/include/$(NAME)

#Assembling main.cpp file target
$(OBJ)/main.o: $(SRC)/main.cpp
	mkdir -p $(OBJ)
	$(CXX) -c $(SRC)/main.cpp $(CXXFLAGS) -o $(OBJ)/main.o

#Assembling parse.cpp file target
$(OBJ)/parse.o: $(SRC)/parse.cpp
	mkdir -p $(OBJ)
	$(CXX) -c $(SRC)/parse.cpp $(CXXFLAGS) -o $(OBJ)/parse.o

#Assembling storage.cpp file target
$(OBJ)/storage.o: $(SRC)/storage.cpp
	mkdir -p $(OBJ)
	$(CXX) -c $(SRC)/storage.cpp $(CXXFLAGS) -o $(OBJ)/storage.o

#Linking from object files target
$(BIN)/fstore: $(OBJ)/main.o $(OBJ)/parse.o $(OBJ)/storage.o
	mkdir -p $(BIN)
	$(CXX) $(OBJ)/main.o $(OBJ)/parse.o $(OBJ)/storage.o $(CXXFLAGS) -o $(BIN)/fstore
