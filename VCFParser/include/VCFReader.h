//
// Created by ernesto lowy gallego on 2019-10-17.
//

#ifndef VCFPARSER_VCFREADER_H
#define VCFPARSER_VCFREADER_H

using namespace std;

class VCFReader
{
    public:
        void stats(); // Class member function initialization
        VCFReader(string apath);
        ~VCFReader();
    private: string path;
};


#endif //VCFPARSER_VCFREADER_H
