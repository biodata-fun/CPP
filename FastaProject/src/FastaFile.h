// FastaFile.h
#include <iostream>
#include "Fasta.h"
#ifndef FASTAFILE_H
#define FASTAFILE_H

using namespace std;

class FastaFile
{
    public:
        int seqnumber;
        FastaFile(string apath);
        ~FastaFile();
        void setSeqNumber(); // Class member function initialization
        vector<string> getIds();
        Fasta getFasta(string id);
    private: string path;
};

#endif /* FASTAFILE_H */