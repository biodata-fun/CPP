#include <iostream>
#include <fstream>
#include <vector>
#include "Fasta.h"

using namespace std;

Fasta::Fasta(string anid, string aseq)
{
    id = anid;
    seq = aseq;
}

Fasta::~Fasta()
{

}

/**
 * Get counts of nucleotides for sequence in this Fasta object.
 */
Counts Fasta::getNtcounts()
{
    int A_cnt = 0;
    int C_cnt = 0;
    int T_cnt = 0;
    int G_cnt = 0;

    for(int i=0; seq[i]; i++)
        if (seq[i]=='A') {
            A_cnt++;
        } else if (seq[i]=='C') {
            C_cnt++;
        } else if (seq[i]=='T') {
            T_cnt++;
        } else if (seq[i]=='G') {
            G_cnt++;
        }

    Counts c= {id, A_cnt, C_cnt, T_cnt, G_cnt};

    return c;
}