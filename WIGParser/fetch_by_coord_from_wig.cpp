/*
* Script to parse a .WIG file and extract the regions defined in a .csv file.
* The script will take into account 
*/

#include <iostream> 
#include <fstream> 
#include <algorithm>
#include <string>
#include <bits/stdc++.h> 
#include <vector>

using namespace std;

/*
This function will parse the WIG file and extract the values for the regions
specified by the 'coords' parameter

Returns
-------
std::vector<float>
*/
std::vector<float> fetch_region(std::string ifile, std::string coord)
{     
    std::ifstream myfile(ifile);
    std::vector<float> covs;
    if (myfile.is_open())
    {
        smatch match; 
        regex re("^fixedStep chrom=(.+) start=.*"); 

        // Split coord
        std::string name;
        std::string chr_c;
        char strand;
        int start;
        int end;
        std::replace(coord.begin(), coord.end(), ',', ' ');
        std::istringstream iss1(coord);
        iss1 >> name >> chr_c >> strand >> start >> end ;

        std::string line;
        std::string chrom;
        float cov;
        int count =1;
        bool seen = false;
        while (std::getline(myfile, line)) {
            if( line[0]=='t')
            {
                continue;
            } 
            if (regex_search(line, match, re) == true)
            {
                chrom=match.str(1);
                count =1;
                continue;
            }
            if ((chrom == chr_c) && (count>=start) && (count<=end))
            {
                std::replace(line.begin(), line.end(), ',', ' ');
                std::istringstream iss(line);
                iss >> cov; 
                covs.push_back(cov);
                seen = true;
            }
            if ((seen == true) && (chrom!=chr_c))
            {
                break;
            }
            count++;
        }
        if (strand == '-')
        {
            reverse(covs.begin(), covs.end()); 
        }
    } else {
        std::cout << "Unable to open file";
    }
    return covs;
}

/*
Function to parse a .csv file in the following format:
<gene,chr,strand,start,end>
*/
std::vector<std::string> parse_csv(std::string ifile)
{
    std::vector<std::string> myvector;
    std::ifstream myfile(ifile);
    if (myfile.is_open())
    {
        cout<< "file opened successfully"<<endl;

        std::string line;
        while (std::getline(myfile, line)) {
            myvector.push_back(line);
        }
    } else {
        std::cout << "Unable to open file";
    }

    return myvector;
}

int main(int argc, char *argv[]) 
{ 
    if(argc!=4) 
    { 
        std::cout<< "\nUSAGE: fetch_by_coord <in_file.wig> <coords.csv> <outfile.csv>\n"<<endl;
    }
    // Creation of ofstream class object 
    ofstream fout;
    fout.open(argv[3]); 

    std::vector<std::string> linevector;
    linevector=parse_csv(argv[2]);
    std::vector<float> covs;
    for (int i = 0; i<linevector.size(); i++) {
        std::cout << "Processing " << linevector.at(i) << std::endl;
        std::string out_str;
        out_str=linevector.at(i) + ',';
        covs=fetch_region(argv[1], linevector.at(i));
        for (auto i = covs.begin(); i != covs.end(); ++i)
            out_str += std::to_string(*i)+',';
        out_str.erase(std::prev(out_str.end()));
        out_str += '\n';
        fout << out_str; 
    }
    fout.close(); 
    return 0;
}