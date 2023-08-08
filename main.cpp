#include "library.h"

Library* pointer;
typedef char* (Library::* SetLibraryPtr)(char*);//pointer to method
void pointerOnObject();
void pointerToMethod();
void defaultConstructor();
void copyConstructor();
void staticMemory();
void dynamicMemory(int);

int main()
{
    printf_s("\t\t\t\tData placed in static memory\n");
    staticMemory();
    printf_s("\n\n\n\t\t\t\tData placed in dynamic memory\n");
    dynamicMemory(2);
    printf_s("\n\n\n\t\t\t\tUsage of the pointer on object\n");
    pointerOnObject();
    printf_s("\n\n\n\t\t\t\tUsage of the pointer on method\n");
    pointerToMethod();
    printf_s("\n\n\n\t\t\t\tDefault data constructor\n");
    defaultConstructor();
    printf_s("\n\n\n\t\t\t\tCopying data constructor\n");
    copyConstructor();
    system("pause");
    return 0;
}

void pointerOnObject()
{
    char str1[] = { "Sherlock Holmes" };
    char str2[] = { "Arthur Conan Doyle" };
    float a = 34;
    Library lib1(str1, str2, a);
    Library* ptr1;
    printf_s("\nregular information print: ");
    lib1.printLibrary();
    ptr1 = &lib1;
    printf("\ninformation print by pointer:    ");
    ptr1->printLibrary();
    lib1.~Library();
}
void pointerToMethod()
{
    char str1[] = { "1984" };
    char str2[] = { " George Orwell" };
    float a = 0.2;
    Library lib2(str1, str2, a);
    SetLibraryPtr method = &Library::ptrMethod;
    char* strA;
    char* strB;
    float temp;
    pointer = &lib2;
    strA = pointer->getName();
    strB = pointer->getAuthor();
    temp = lib2.getPrice();
    printf_s("Name : %s;", strA);
    printf_s("\tAuthor : %s;", strB);
    printf_s("\tPrice :  %.2f; \n", temp);
    char strZ[] = { "  Constructor called by pointer\n" };
    char* strX = (lib2.*method)(strZ);
    //strX.printPerson();
    printf_s("%s",strX);
    lib2.~Library();
}


void defaultConstructor()
{
    Library lib3;
    lib3.printLibrary();
}

void copyConstructor()
{
    char str1[] = { "Huckleberry Finn" };
    char str2[] = { "Mark Twain" };
    float a = 12;
    Library lib4(str1, str2, a);
    Library libcopy(lib4);
    printf_s("\noriginal information print:    ");
    lib4.printLibrary();
    printf_s("\ncopied information print:  ");
    libcopy.printLibrary();
    lib4.~Library();
}

void staticMemory()
{
    const int n = 3;
    char str1[] = { "The Book Thief" };
    char str4[] = { "The Time Traveler's Wife" };
    char str7[] = { "The Kite Runner " };
    char str2[] = { "Markus Zusak" };
    char str5[] = { "Audrey Niffenegger" };
    char str8[] = { "Khaled Hosseini" };
    float a = 4, b = 68, c = 45;
    Library lib5(str1, str2, a);
    Library lib6(str4, str5, b);
    Library lib7(str7, str8, c);
    Library Arr[n] = { lib5, lib7 };
    for (int i = 0; i < n; i++) Arr[i].printLibrary();
    lib5.~Library();
    lib6.~Library();
    lib7.~Library();
}

void dynamicMemory(int n)
{
    char str1[] = { "The Call of Cthulhu" };
    char str4[] = { "Winnie-the-Pooh" };
    char str2[] = { "H. P. Lovecraft" };
    char str5[] = { "A. A. Milne" };
    float a = 12, b = 27;
    Library* ptr = new Library[n];
    ptr->setName(str1);
    ptr->setAuthor(str2);
    ptr->setPrice(a);
    ptr->printLibrary();
    Library lib8(str4, str5, b);
    ptr[1] = lib8;
    ptr[1].printLibrary();
    delete[] ptr;
}
