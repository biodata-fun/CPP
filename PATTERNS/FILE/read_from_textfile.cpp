/**
Snippet for reading from a file: 
USAGE : g++ read_from_textfile.cpp -o read_from_textfile
**/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  string line;
  ifstream myfile ("acsvfile.csv");
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