#include "FastaFile.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>
 
using namespace std;

int main()
{
    string example="test.fa";
    FastaFile f(example);
    f.setSeqNumber();
    cout << f.seqnumber <<endl;
    vector<string> ids;
    ids=f.getIds();
    for (int i = 0; i<ids.size(); i++) {
		std::cout << ids.at(i) << std::endl;
	}
    return 0;
}