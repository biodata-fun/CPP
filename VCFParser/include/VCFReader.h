//
// Created by ernesto lowy gallego on 2019-10-17.
//

#ifndef VCFPARSER_VCFREADER_H
#define VCFPARSER_VCFREADER_H

#include <vector>

using namespace std;

struct Variant
{
    basic_string<char> chr;
    int pos;
    std::string ref;
    std::string alt;
    std::string type;
};

class VCFReader
{
    public:
        // Class member function initialization
        void stats();
        VCFReader(string apath);
    ~VCFReader();
    private:
        string path;
        vector<struct Variant> get_variants();
        vector<struct Variant> vt_array;
};

#endif //VCFPARSER_VCFREADER_H
