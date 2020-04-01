/*
Here goes the main function.
This is will be compiled by doing:

g++ add.cpp main.cpp

If 'add.h' is in a different folder then,
it will be compiled by doing:
g++ -I /path/to/dir/ add.cpp main.cpp

*/
#include <iostream>
#include "add.h"

int main()
{
  std::cout << "The sum of 3 and 4 is " << add(3, 4) << std::endl;
  return 0;
}