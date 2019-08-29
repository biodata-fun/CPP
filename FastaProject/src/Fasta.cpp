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