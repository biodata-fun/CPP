// FastaFile.h
#include <iostream>
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
    private: string path;
};

#endif /* FASTAFILE_H */ 