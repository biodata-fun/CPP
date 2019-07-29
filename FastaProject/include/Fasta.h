// Fasta.h
#include <iostream>
#ifndef FASTA_H
#define FASTA_H

using namespace std;

class Fasta
{
    public:
        int seqnumber;
        Fasta(string id, string seq);
        ~Fasta();
    private: string id;
    private: string seq;
};

#endif /* FASTA_H */ 