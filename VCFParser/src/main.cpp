#include <iostream>
#include <VCFReader.h>
#include <getopt.h>

using namespace std;

void printSummary(char** argv) {
    cerr << "usage: " << argv[0] << " [options] --file [file]" << endl
         << endl
         << "options:" << endl
         << "    -s, --stats     Calculate basic stats on the VCF." << endl
         << "    -f, --file     VCF file to analyse." << endl
         << "    -h, --help     Print this summary." << endl
         << endl
         << "Perform operations on a certain VCF." << endl;
    exit(0);
}

int main(int argc, char** argv) {

    std::string ifile;
    VCFReader f;

    int c;
    while (true) {
        static struct option long_options[] =
                {
                        /* These options set a flag. */
                        // required_argument means that if for example -f or --reference is passed
                        // then an argument is required: For example: --reference file.fa
                        {"help", no_argument, 0, 'h'},
                        {"file", required_argument, 0, 'f'},
                        {"stats", no_argument, 0, 's'},
                        {0, 0, 0, 0}
                };
        /* getopt_long stores the option index here. */
        int option_index = 0;

        c = getopt_long (argc, argv, "hmf:p:P:n:",
                         long_options, &option_index);

        // if user does not provide option than c will be -1
        if (c == -1)
            break;

        switch (c) {

            case 'h':
                printSummary(argv);
                break;

            case 'f':
                ifile=optarg;
                f.setPath(ifile);

            case 's':
                if(ifile.empty()) {
                    std::cerr << "I need a VCF file!" << std::endl;
                    return 1;
                }
                f.stats();
                break;

            case '?':
                printSummary(argv);
                exit(1);
                break;

            default:
                abort ();
        }
    }

    return 0;
}