#include <iostream>
#include "src/BEDfile.h"

using namespace std;

int main() {
    string testBedf="/Users/ernesto/lib/CPP/BEDproject/data/test.bed";
    BEDFile f(testBedf);
    int n_feats=f.getFeatNumber();
    std::cout << "Number of feats:" << n_feats << std::endl;

    f.getNumBasesInFeats();
}