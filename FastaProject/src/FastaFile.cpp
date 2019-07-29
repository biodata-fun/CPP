#include <iostream>
#include <fstream>
#include <vector>
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

/**
 * Get a vector of ids for sequences in the file.
 */
vector<string> FastaFile::getIds() 
{
    ifstream file (path);
    string line;
    std::vector<string> ids;
    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            std::string toMatch = ">";
            bool result = boost::algorithm::starts_with(line , toMatch);
            if (result == true)
            {
                string id;
                id=line.substr(1);
                ids.push_back(id);
            }
        }
        file.close();
    }
    else cout << "Unable to open file";
    return ids;
}

/**
 * Get a Fasta object using its id.
 */
void FastaFile::getFasta(string id)
{
    ifstream file (path);
    string line;
    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            std::string toMatch = ">";
            bool result = boost::algorithm::starts_with(line , toMatch);
            if (result == true)
            {
                string this_id;
                this_id=line.substr(1);
                if (id.compare(this_id) == 0) {
                    cout<< "Found it!" << endl;
                }

            }
        }
        file.close();
    }
    else cout << "Unable to open file";

}

