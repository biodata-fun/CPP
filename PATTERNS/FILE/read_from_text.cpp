/**
Snippet for reading from a file: 
USAGE : g++ -g read_from_text.cpp -o read_from_text
**/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  string line;
  ifstream myfile ("in.csv");
  if (myfile.is_open())
    {
      while ( getline (myfile,line) )
        {
          cout << line << '\n';
        }
      myfile.close();
    }

  else cout << "Unable to open file";

  return 0;
}
