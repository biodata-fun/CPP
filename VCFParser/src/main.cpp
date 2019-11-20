#include <iostream>
#include <VCFReader.h>
#include <getopt.h>

using namespace std;

void printSummary(char** argv) {
    cerr << "usage: " << argv[0] << " [options] --file [file]" << endl
         << endl
         << "options:" << endl
         << "    -s, --stats     Calculate basic stats on the VCF." << endl
         << "    -a, --add_chr     Add 'chr' to chromosome names." << endl
         << "    -r  --remove_chr  Remove 'chr' from chromosome names." <<endl
         << "    -f, --file     VCF file to analyse." << endl
         << "    -o  --out      File for output." << endl
         << "    -h, --help     Print this summary." << endl
         << endl
         << "Perform operations on a certain VCF." << endl;
    exit(0);
}

int main(int argc, char** argv) {

    std::string ifile;
    std::string ofile;
    bool runStats=false;
    bool runaddchr=false;
    bool runremovechr=false;
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
                        {"add_chr", no_argument, 0, 'a'},
                        {"remove_chr", no_argument, 0, 'r'},
                        {"out", required_argument, 0, 'o'},
                        {0, 0, 0, 0}
                };
        /* getopt_long stores the option index here. */
        int option_index = 0;

        c = getopt_long (argc, argv, "hmf:p:P:n:",
                         long_options, &option_index);

        // if user does not provide option than c will be -1
        if (c == -1)
        {
            break;
        }

        switch (c) {

            case 'h':
                printSummary(argv);
                break;

            case 'f':
                ifile=optarg;
                f.setPath(ifile);
                break;

            case 's':
                runStats=true;
                break;

            case 'o':
                ofile=optarg;
                break;

            case 'a':
                runaddchr=true;
                break;

            case 'r':
                runremovechr=true;
                break;

            case '?':
                printSummary(argv);
                exit(1);
                break;

            default:
                abort ();
        }
    }

    //check that all required arguments conditions are satisfied
    if (runStats==true) {
        if (ifile.empty()) {
            std::cerr << "I need a VCF file!" << std::endl;
            return 1;
        }
        f.stats();
    }

    if (runremovechr==true) {
        if (ifile.empty()) {
            std::cerr << "I need a VCF file!" << std::endl;
            return 1;
        } else if (ofile.empty()) {
            std::cerr << "I need an output VCF file name!" << std::endl;
            return 1;
        }
        f.removeChr(ofile);
    }

    if (runaddchr==true) {
        if (ifile.empty()) {
            std::cerr << "I need a VCF file!" << std::endl;
            return 1;
        } else if (ofile.empty()) {
            std::cerr << "I need an output VCF file name!" << std::endl;
            return 1;
        }
        f.addChr(ofile);
    }

    return 0;
}