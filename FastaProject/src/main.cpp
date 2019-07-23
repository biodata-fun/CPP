#include "FastaFile.h"
#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>
 
using namespace std;

int main()
{
    string example="test.fa";
    FastaFile f(example);
    f.setSeqNumber();
    cout << f.seqnumber <<endl;
    return 0;
}