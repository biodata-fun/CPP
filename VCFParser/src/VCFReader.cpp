//
// Created by ernesto lowy gallego on 2019-10-16.
//
#include <fstream>
#include <iostream>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/algorithm/string.hpp>
#include <VCFReader.h>
#include <regex>
#include <map>

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

            // Check if there is more than 1 comma-separated allele.

            regex b(".*,.*");

            vector<string> altAlls;
            // regex_match function matches string a against regex b
            if ( regex_match(alt, b) )
                boost::split(altAlls,alt,boost::is_any_of(","));
            else {
                altAlls.push_back(alt);
            }

            for (size_t i = 0; i < altAlls.size(); i++) {
                std::string type;
                if (altAlls[i].length() != ref.length()) {
                    type = "indels";
                } else {
                    type = "snps";
                }
                Variant vt = {strs[0], pos, ref, altAlls[i], type};
                vt_array.push_back(vt);
            }
        }
    }
    return vt_array;
}

/*
 * Function to get a set of stats from VCF
 */
void VCFReader::stats()
{
    vector<int> snp_pos, indel_pos;
    std::map<int, int> snpCounter,indelCounter;
    for (int i = 0; i < vt_array.size(); i++)
        if (vt_array[i].type=="snps") {
            ++snpCounter[vt_array[i].pos];
        } else if (vt_array[i].type=="indels") {
            ++indelCounter[vt_array[i].pos];
        }

    int multiallelic_snps=0;
    int biallelic_snps=0;
    // Iterate through all elements in std::map
    std::map<int, int>::iterator it = snpCounter.begin();
    while(it != snpCounter.end())
    {
        if (it->second>1) {
            multiallelic_snps++;
        } else {
            biallelic_snps++;
        }
        it++;
    }
    int multiallelic_indels=0;
    int biallelic_indels=0;
    std::map<int, int>::iterator it1 = indelCounter.begin();
    while(it1 != indelCounter.end())
    {
        if (it1->second>1) {
            multiallelic_indels++;
        } else {
            biallelic_indels++;
        }
        it1++;
    }

    // Print report
    std::cout << "##Stats###" << std::endl;
    std::cout << "Number of multiallelic SNPs:" <<  multiallelic_snps << std::endl;
    std::cout << "Number of biallelic SNPs:" <<  biallelic_snps << std::endl;
    std::cout << "Number of multiallelic INDELs:" << multiallelic_indels << std::endl;
    std::cout << "Number of biallelic INDELs:" << biallelic_indels << std::endl;
}
