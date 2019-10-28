//
// Created by ernesto lowy gallego on 2019-10-17.
//

#ifndef VCFPARSER_VCFREADER_H
#define VCFPARSER_VCFREADER_H

#include <vector>

using namespace std;

class VCFReader
{
    public:
        // Class member function initialization
        void stats();
        VCFReader(string apath);
    ~VCFReader();
    private:
        string path;
};

#endif //VCFPARSER_VCFREADER_H
