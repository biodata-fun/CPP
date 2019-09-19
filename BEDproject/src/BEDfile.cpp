//
// Created by ernesto lowy gallego on 2019-09-18.
//
#include "BEDfile.h"
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>


using namespace std;

BEDFile::BEDFile(string apath)
{
    path = apath;
}

BEDFile::~BEDFile()
{

}

/**
 * Get number of Features (entries) in BEDFile.
 */
int BEDFile::getFeatNumber() {
    ifstream file (path);
    string line;

    int counter=0;
    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            counter+=1;
        }
        file.close();
    }
    else cout << "Unable to open file";

    return counter;
}

/**
 * Get the number of bases involved in the Features
 * within this file.
 */
void BEDFile::getNumBasesInFeats() {
    ifstream file (path);
    string line;

    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            vector<string> strs;
            boost::split(strs,line,boost::is_any_of("\t"));

            std::cout << "* size of the vector: " << strs.size() << endl;
            for (size_t i = 0; i < strs.size(); i++)
                std::cout << strs[i] << endl;
            std::cout << "Number of feats:" << "caca" << std::endl;
        }
        file.close();
    }
    else cout << "Unable to open file";

}
