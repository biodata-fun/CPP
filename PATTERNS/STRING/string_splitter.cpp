/*
std::string Split function implementation by using delimiter as a character.
USAGE: g++ -g string_splitter.cpp -o string_splitter
*/

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

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
	std::string Names="Jose\tPepe";

	std::vector<std::string> splitted_names;
	splitted_names=split(Names,'\t');

	for (int i = 0; i<splitted_names.size(); i++) {
		std::cout << splitted_names.at(i) << '\n';
	}
    return 0;
}