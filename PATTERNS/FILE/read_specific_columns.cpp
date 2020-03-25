/*
This script will print out certain columns from a text file
USAGE: g++ -g read_specific_columns.cpp -o read_specific_columns
*/

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
int main()
{
    ifstream file("./DATA/in.dat");
    string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue;     // skips empty lines
        std::istringstream is(line);    // construct temporary istringstream
        std::string col1, col2, col3;
        if (is >> col1 >> col2 >> col3) {
            std::cout << "column 1: " << col1 << " column 3: " << col3 << std::endl;
        }
        else {
            std::cout << "This line didn't meet the expected format." << std::endl;
        }
    }
    return 0;
}