#include <iostream>
#include <VCFReader.h>

using namespace std;

int main() {
    std::cout << "hello" << std::endl;
    std::string example="/Users/ernesto/lib/CPP/VCFParser/ggvp_bam.bcftools.20190731.HG02570.biallelic.onlyvts.chr20.vcf.gz";
    VCFReader f(example);
//    f.stats();
    return 0;
}