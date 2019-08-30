// Fasta.h
#include <iostream>
#ifndef FASTA_H
#define FASTA_H

using namespace std;

struct Counts
{
    string id;
    int A;
    int C;
    int T;
    int G;
};

class Fasta
{
    public:
        int seqnumber;
        Fasta(string id, string seq);
        ~Fasta();
        string id;
        string seq;
        Counts getNtcounts();
};

#endif /* FASTA_H */ 