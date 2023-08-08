#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Library {
private:
    char Name[20];
    char Author[20];
    float Price;

public:
    Library();
    Library(char name[], char author[], float price);
    Library(Library& lib);
    ~Library();
    void setLibrary(char name[], char author[], float price);
    char* ptrMethod(char* str);
    void setName(char name[]);
    void setAuthor(char author[]);
    void setPrice(float price);
    char* getName();
    char* getAuthor();
    float getPrice();
    void printLibrary();
};
