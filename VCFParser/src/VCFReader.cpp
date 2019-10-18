//
// Created by ernesto lowy gallego on 2019-10-16.
//
#include <fstream>
#include <iostream>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <VCFReader.h>

using namespace std;

VCFReader::VCFReader(string apath)
{
    path = apath;
}

VCFReader::~VCFReader()
{

}

/*
 * Function to get a set of stats from VCF
 */
void VCFReader::stats()
{
    //Read from the first command line argument, assume it's gzipped
    std::ifstream file(path, std::ios_base::in | std::ios_base::binary);
    boost::iostreams::filtering_streambuf<boost::iostreams::input> inbuf;
    inbuf.push(boost::iostreams::gzip_decompressor());
    inbuf.push(file);
    //Convert streambuf to istream
    std::istream instream(&inbuf);
    //Iterate lines
    std::string line;
    while(std::getline(instream, line)) {
        std::cout << line << std::endl;
    }
    //Cleanup
    file.close();
}