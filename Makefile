#Phony targets
.PHONY: all clean assemble install uninstall

#Variables
CXX = g++
CXXFLAGS =
NAME = fstore
PREFIX = /usr/local
BIN = ./bin
OBJ = ./obj
SRC = ./src

#Default target
all: $(OBJ)/main.o $(BIN)/fstore

#Clean targer
clean:
	rm -f $(OBJ)/*.o

#Assembling
assemble: $(OBJ)/main.o

#Installation
install:
	mkdir -p $(PREFIX)/bin
	mkdir -p $(PREFIX)/src
	mkdir -p $(PREFIX)/share
	mkdir -p $(PREFIX)/src/$(NAME)
	mkdir -p $(PREFIX)/share/$(NAME)
	mkdir -p $(PREFIX)/share/$(NAME)/storage
	install $(BIN)/fstore $(PREFIX)/bin/
	install $(SRC)/main.cpp $(PREFIX)/src/$(NAME)/

#Uninstallation
uninstall:
	rm -f $(PREFIX)/bin/fstore
	rm -rf $(PREFIX)/src/$(NAME)
	rm -rf $(PREFIX)/share/$(NAME)

#Assembling source files target
$(OBJ)/main.o: $(SRC)/main.cpp
	mkdir -p $(OBJ)
	$(CXX) -c $(SRC)/main.cpp -o $(OBJ)/main.o

#Linking from object files target
$(BIN)/fstore: $(OBJ)/main.o
	mkdir -p $(BIN)
	$(CXX) $(OBJ)/main.o $(CXXFLAGS) -o $(BIN)/fstore
