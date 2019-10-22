//
// Created by ernesto lowy gallego on 2019-10-16.
//
#include <fstream>
#include <iostream>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/algorithm/string.hpp>
#include <sstream>
#include <VCFReader.h>

using namespace std;

VCFReader::VCFReader(string apath)
{
    path = apath;
    vt_array=get_variants();
    std::cout<<"hello" <<std::endl;
}

VCFReader::~VCFReader()
{

}
/*
 * This private function will parse the VCF and will
 * return a Vector of Structs of type Variant
 */
vector<Variant> VCFReader::get_variants() {
    //Read from the first command line argument, assume it's gzipped
    std::ifstream file(path, std::ios_base::in | std::ios_base::binary);
    if (!file) {
        // Print an error and exit
        cerr << "Uh oh, *.gz file could not be opened for reading!" << endl;
        exit(1);
    }

    vector<Variant> vt_array;

    boost::iostreams::filtering_streambuf<boost::iostreams::input> inbuf;
    inbuf.push(boost::iostreams::gzip_decompressor());
    inbuf.push(file);
    //Convert streambuf to istream
    std::istream instream(&inbuf);
    //Iterate lines
    std::string line;
    while (std::getline(instream, line)) {
        std::string toMatch = "#";
        bool result = boost::algorithm::starts_with(line, toMatch);
        if (result == true) {
            //skip header
            continue;
        } else {
            vector<string> strs;
            boost::split(strs, line, boost::is_any_of("\t"));
            std::string pos_st = strs[1];
            // casting str to int
            stringstream geek(pos_st);
            int pos = 0;
            geek >> pos;
            std::string ref = strs[3];
            std::string alt = strs[4];
            std::string type;
            if (alt.length()!= ref.length()) {
                  type="indels";
            } else {
                  type="snps";
            }
            Variant vt={strs[0],pos,ref,alt,type};
            vt_array.push_back(vt);
        }
    }
    return vt_array;
}

/*
 * Function to get a set of stats from VCF
 */
void VCFReader::stats()
{
            // guess what type of variant is this one
          //  if (alt.length()!= ref.length()) {
          //      no_indels+=1;
          //  } else {
          //      no_snps+=1;
          //  }
//            std::cout << "* size of the vector: " << strs.size() << endl;
//            for (size_t i = 0; i < strs.size(); i++)
//                std::cout << strs[i] << endl;
//        }
//    }
    // Print report
//    std::cout << "##Stats###" << std::endl;
//    std::cout << "Number of SNPs:" << no_snps << std::endl;
//    std::cout << "Number of INDELs:" << no_indels << std::endl;

    //Cleanup
//    file.close();
}
