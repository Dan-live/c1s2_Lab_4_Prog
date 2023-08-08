#include "library.h"

Library::Library()
{
    char str1[] = { "Harry potter" };
    char str2[] = { "J. K. Rowling" };
    strcpy_s(Name, str1);
    strcpy_s(Author, str2);
    Price = 15,5;
    cout << "\nDEFAULT CONSTRUCTOR CALL" << endl;
}

Library::Library(char name[], char author[], float price)
{
    strcpy_s(Name, name);
    strcpy_s(Author, author);
    Price = price;
    cout << "\nPARAMETER CONSTRUCTOR CALL" << endl;
}
Library::Library(Library& lib)
{
    strcpy_s(Name, lib.Name);
    strcpy_s(Author, lib.Author);
    Price = lib.Price;
    cout << "\nCOPY CONSTRUCTOR CALL" << endl;
}

Library::~Library()
{
    cout << "Library was deleted" << endl;
}

void Library::setLibrary(char name[], char author[], float price)
{
    strcpy_s(Name, name);
    strcpy_s(Author, author);
    Price = price;
}

char* Library::ptrMethod(char* str)
{
    return str;
}

void Library::setName(char name[])
{
    strcpy_s(Name, name);
}

void Library::setAuthor(char author[])
{
    strcpy_s(Author, author);
}


void Library::setPrice(float price)
{
    Price = price;
}

char* Library::getName()
{
    return Name;
}

char* Library::getAuthor()
{
    return Author;
}

float Library::getPrice()
{
    return Price;
}

void Library::printLibrary()
{
    printf_s("Name : %s;", Name);
    printf_s("\tAuthor : %s;", Author);
    printf_s("\tPrice :  %.2f; \n", Price);
}
