//
// Created by ernesto lowy gallego on 2019-09-18.
//
#include "BEDfile.h"
#include <fstream>
#include <string>
#include <map>
#include <boost/algorithm/string.hpp>
#include <sstream>
#include <iterator>


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

    std::map<std::string, int> featBychros;
    std::map<std::string, int> mapOfWords;
    mapOfWords.insert(std::make_pair("earth", 1));
    mapOfWords["sun"] = 3;

    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            vector<string> strs;
            boost::split(strs,line,boost::is_any_of("\t"));
            string chr = strs[0];
            // convert strings to int
            stringstream start_str(strs[1]);
            stringstream end_str(strs[2]);
            int start = 0;
            int end = 0;
            start_str >> start;
            end_str >> end;
            if ( start > end) {
                cerr << "Invalid feature, start is higher than the end" << endl;
                exit(1);
            }
            int substr = end - start;
            std::cout << strs[0] << endl;
            featBychros.insert(std::make_pair(chr, substr));
            featBychros["sun"] = 3;
        }
        file.close();
    }
    else cout << "Unable to open file";

}
