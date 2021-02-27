#include <iostream>
#include "Book.h"

int main()
{
    Book myBook(1, "Concept of Relative Strength", "B. Moffett");

    std::cout << myBook.Author << std::endl;
    std::cout << "Hello World!\n";
}

