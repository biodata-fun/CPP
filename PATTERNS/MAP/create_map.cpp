/*
This script demonstrates how to create a Map, insert elements in it
and iterate over it
*/

#include <iostream>
#include <map>
#include <string>
#include <iterator>
 
int main()
{
    std::map<std::string, int> mapOfWords;
    // Inserting data in std::map
    mapOfWords["earth"] = 1;
    mapOfWords["moon"] = 2;
    mapOfWords["sun"] = 3;
    // Will replace the value of already added key i.e. earth
    mapOfWords["earth"] = 4;
    // Iterate through all elements in std::map
    std::map<std::string, int>::iterator it = mapOfWords.begin();
    while(it != mapOfWords.end())
    {
        std::cout<<it->first<<" :: "<<it->second<<std::endl;
        it++;
    }
    return 0;
}