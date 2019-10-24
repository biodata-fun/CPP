#include <iostream>
#include <VCFReader.h>

using namespace std;

int main() {
    std::cout << "hello" << std::endl;
    std::string example="/Users/ernesto/lib/ggvp_bam.bcftools.20190731.chr20_10e6_15e6.HG02570.vcf.gz";
    VCFReader f(example);
    f.stats();
    return 0;
}