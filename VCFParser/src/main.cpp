#include <iostream>
#include <VCFReader.h>

using namespace std;

int main() {

    std::string example="/Users/ernesto/lib/CPP/test_boost_compression/ggvp_bam.bcftools.20190731.HG02570.biallelic.onlyvts.vcf.gz";
    VCFReader f(example);
    f.stats();
    return 0;
}