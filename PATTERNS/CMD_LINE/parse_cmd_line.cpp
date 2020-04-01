/*
This script shows how to use parse the command line options
*/
#include <getopt.h>
#include <iostream>

using namespace std;

void printSummary(char** argv) {
    cerr << "usage: " << argv[0] << " [options] --file [file]" << endl
         << endl
         << "options:" << endl
         << "    -s, --stats     Calculate basic stats on the VCF." << endl
         << "    -f, --file     File to analyse." << endl
         << "    -h, --help     Print this summary." << endl
         << endl
         << "Example snippet on how to parse command line args." << endl;
    exit(0);
}

int main(int argc, char** argv) {

    std::string ifile;
    bool runStats=false;
    
    int c;
    while (true) {
        static struct option long_options[] =
                {
                        /* These options set a flag. */
                        // required_argument means 
                        // than an argument is required: For example: --reference file.fa
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
        {
            break;
        }

        switch (c) {

            case 'h':
                printSummary(argv);
                break;

            case 'f':
                ifile=optarg;
                break;

            case 's':
                runStats=true;
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
       std::cout << " 's' was true!!!" << std::endl;
    }

    return 0;
}