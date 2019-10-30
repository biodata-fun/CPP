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
#include<set>

using namespace std;

VCFReader::VCFReader(string apath)
{
    path = apath;
}

VCFReader::~VCFReader()
{
}

void VCFReader::setPath(string apath)
{
    path = apath;
}

/*
 * Function to get a set of stats from VCF
 */
void VCFReader::stats()
{
    //Read from the first command line argument, assume it's gzipped
    std::ifstream file(path, std::ios_base::in | std::ios_base::binary);
    if (!file) {
        // Print an error and exit
        cerr << "Uh oh, *.gz file could not be opened for reading!" << endl;
        exit(1);
    }

    // this sets will keep record of all SNP and INDEL pos
    std::set<int> snpPos, indelPos;

    boost::iostreams::filtering_streambuf<boost::iostreams::input> inbuf;
    inbuf.push(boost::iostreams::gzip_decompressor());
    inbuf.push(file);
    //Convert streambuf to istream
    std::istream instream(&inbuf);
    //Iterate lines
    std::string line;

    int multiallelic_snps=0;
    int biallelic_snps=0;
    int multiallelic_indels=0;
    int biallelic_indels=0;

    while (std::getline(instream, line)) {
        std::string toMatch = "#";
        bool result = boost::algorithm::starts_with(line, toMatch);
        if (result == true) {
            //skip header
            continue;
        } else {
            std::string chr,pos_st,filter,ref,alt;
            // Check if there is more than 1 comma-separated allele.
            regex b(".*,.*");
            if (instream >> chr >> pos_st >> filter >> ref >> alt) {
                // casting str to int
                stringstream geek(pos_st);
                int pos = 0;
                geek >> pos;
                vector<string> altAlls;
                // regex_match function matches string a against regex b
                if (regex_match(alt, b))
                    boost::split(altAlls, alt, boost::is_any_of(","));
                else {
                    altAlls.push_back(alt);
                }

                // iterate over each of the splitted alleles
                for (size_t i = 0; i < altAlls.size(); i++) {
                    if (altAlls[i].length() != ref.length()) {
                        // indels
                        const bool is_in = indelPos.find(pos) != indelPos.end();
                        if (is_in == true) {
                            multiallelic_indels++;
                            biallelic_indels--;
                        } else {
                            indelPos.insert(pos);
                            biallelic_indels++;
                        }
                    } else {
                        // snps
                        const bool is_in = snpPos.find(pos) != snpPos.end();
                        if (is_in == true) {
                            multiallelic_snps++;
                            biallelic_snps--;
                        } else {
                            snpPos.insert(pos);
                            biallelic_snps++;
                        }
                    }
                }
            }
            else {
                std::cout << "This line didn't meet the expected format." << std::endl;
            }
        }
    }

    file.close();

    // Print report
    std::cout << "##Stats###" << std::endl;
    std::cout << "Number of multiallelic SNPs:" <<  multiallelic_snps << std::endl;
    std::cout << "Number of biallelic SNPs:" <<  biallelic_snps << std::endl;
    std::cout << "Number of multiallelic INDELs:" << multiallelic_indels << std::endl;
    std::cout << "Number of biallelic INDELs:" << biallelic_indels << std::endl;
}
