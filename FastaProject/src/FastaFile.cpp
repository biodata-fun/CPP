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
Fasta FastaFile::getFasta(string id)
{
    ifstream file (path);
    string line;
    bool id_seen = false;
    string seq;
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
                if (id.compare(this_id) == 0 && id_seen == false) {
                    id_seen=true;
                    continue;
                } else if (id_seen == true) {
                    Fasta f(id,seq);
                    return f;
                    break;
                }
            } else {
                if (id_seen==true) {
                    seq += line;
                }
            }
        }
        file.close();
    }
    else cout << "Unable to open file";

}

