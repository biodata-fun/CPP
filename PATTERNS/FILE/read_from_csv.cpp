#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
/*
Script to read-in a .csv file

USAGE: g++ -Wall read_from_csv.cpp -o read_from_csv
*/



/*
std::string split implementation by using delimiter as a character.
*/

std::vector<std::string> split(std::string strToSplit, char delimeter)
{
	std::stringstream ss(strToSplit);
	std::string item;
	std::vector<std::string> splittedStrings;
	while (std::getline(ss, item, delimeter))
	{
		splittedStrings.push_back(item);
	}
	return splittedStrings;
}


int main()
{
     string line;
     ifstream myfile ("./DATA/in.csv");

     if (myfile.is_open())
     {
          while ( getline (myfile,line) )
          {
               std::vector<std::string> splitted_names;
               splitted_names=split(line,',');

	          for (int i = 0; i<splitted_names.size(); i++) {
		          std::cout << splitted_names.at(i) << '\n';
	          }
          }
          myfile.close();
    }
    else std::cout << "Unable to open file";
    
   return 0;
}