/**
Snippet for reading a file and skipping lines starting with '#': 
USAGE : g++ -g skip_lines_starting_w.cpp -o skip_lines_starting_w
**/
#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>
using namespace std;

int main () {
    string line;
    ifstream myfile ("./DATA/in.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            std::string toMatch = "#";
            bool result = boost::algorithm::starts_with(line, toMatch);
            if (result == true) {
                //skip header
                continue;
            } else {
                cout << line << '\n';
            }
        }
        myfile.close();
    }

    else cout << "Unable to open file";
    
    return 0;
}