#include <iostream>
#include <VCFReader.h>

using namespace std;

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error! Usage: " << argv[0] << " <VCF PATH>" << std::endl;
        return 1;
    }
    std::string vcfpath=argv[1];
    VCFReader f(vcfpath);
    f.stats();
    return 0;
}