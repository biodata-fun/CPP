/**
Snippet using the library chrono
to check how long a snippet takes
to run:
USAGE : g++ time_taken.cpp -o time_taken
**/

#include <iostream>
#include <chrono>

#include "night.hpp"

int main() {
  
  // Measure time taken for goodnight1():
  std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

  std::cout << "Do something";
  
  std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> time_span = end - start;

  // Print time taken for goodnight1():
  std::cout << "Time taken: " << time_span.count() << " milliseconds.\n\n";
}