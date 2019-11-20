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
        void setPath(string apath);
        void addChr(string ofile);
        void removeChr(string ofile);

        // Constructors
        VCFReader()=default;
        VCFReader(string apath);
        // Destructor
        ~VCFReader();

    private:
        string path;
};

#endif //VCFPARSER_VCFREADER_H
