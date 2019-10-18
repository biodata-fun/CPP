#include "FastaFile.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;

int main()
{
    string example="/Users/ernesto/lib/CPP/FastaProject/src/test.fa";
    FastaFile f(example);
    f.setSeqNumber();
    cout << f.seqnumber <<endl;
    vector<string> ids;
    ids=f.getIds();
    for (int i = 0; i<ids.size(); i++) {
		std::cout << ids.at(i) << std::endl;
	}
    // testing getFasta function
    Fasta af= f.getFasta("seq1");
    std::cout << "Id:" << af.id << endl;
    std::cout << "Seq:" << af.seq << endl;
    Counts cts;
    cts=af.getNtcounts();
    cout << "Count A:" << cts.A << endl;
    cout << "Count C:" << cts.C << endl;
    cout << "Count T:" << cts.T << endl;
    cout << "Count G:" << cts.G << endl;
    return 0;
}

