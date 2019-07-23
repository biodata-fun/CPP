#include <iostream>
#include <fstream>
#include "FastaFile.h"
#include <boost/algorithm/string.hpp>
 
using namespace std;

FastaFile::FastaFile(string apath)
{
    path = apath;
}

FastaFile::~FastaFile() 
{

}

// Class member function declaration
void FastaFile::setSeqNumber() 
{
    ifstream file (path);
    string line;
    int seq_count=0;
    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            std::string toMatch = ">";
            bool result = boost::algorithm::starts_with(line , toMatch);
            if (result == true)
            {
                seq_count++;
            }
        }
        file.close();
    }
    else cout << "Unable to open file";
    seqnumber=seq_count;
}
