/*
Script to illustrate how to use a template so a function
can be used with different data types

USAGE: g++ -Wall a_template.cpp -o a_template
*/

#include <iostream>
#include "a_template.hpp"

int main() {
  
  std::cout << get_smallest(100, 60) << "\n";
  std::cout << get_smallest(2543.2, 3254.3) << "\n";
  
}