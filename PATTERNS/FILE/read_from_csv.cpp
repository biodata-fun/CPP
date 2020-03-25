#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

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
}