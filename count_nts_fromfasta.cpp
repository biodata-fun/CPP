#include <iostream>
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>

using namespace std;

struct Counts
{
    string id;
    int A;
    int C;
    int T;
    int G;
};


Counts get_nt_count(string id, string line)
{
    int A_cnt = 0;
    int C_cnt = 0;
    int T_cnt = 0;
    int G_cnt = 0;

    for(int i=0; line[i]; i++)
        if (line[i]=='A') {
            A_cnt++;
        } else if (line[i]=='C') {
            C_cnt++;
        } else if (line[i]=='T') {
            T_cnt++;
        } else if (line[i]=='G') {
            G_cnt++;
        }
    
    Counts c= {id, A_cnt, C_cnt, T_cnt, G_cnt};
    
    return c;
}
 
int main()
{
    string line;
    ifstream myfile ("example.txt");
    if (myfile.is_open())
    {
        string id;
        int countA = 0, countC = 0, countT = 0, countG=0;
        bool id_seen=false;
        while ( getline (myfile,line) )
        {
            std::string toMatch = ">";
            bool result = boost::algorithm::starts_with(line , toMatch);
            if (result == true && id_seen == false)
            {
                id=line.substr(1);
                id_seen=true;
            } else if (result == true && id_seen == true) {
                cout << "id:" << id << endl;
                cout << "countA:" << countA << endl;
                cout << "countC:" << countC << endl;
                cout << "countT:" << countT << endl;
                cout << "countG:" << countG << endl;
                id=line.substr(1);
                countA = 0, countC = 0, countG = 0, countT =0;
            } else {
                Counts line_ct;
                line_ct=get_nt_count(id,line);
                countA+=line_ct.A;
                countC+=line_ct.C;
                countG+=line_ct.G;
                countT+=line_ct.T;
            }
        }
        cout << "id:" << id << endl;
        cout << "countA:" << countA << endl;
        cout << "countC:" << countC << endl;
        cout << "countT:" << countT << endl;
        cout << "countG:" << countG << endl;
        myfile.close();
    }

    else cout << "Unable to open file";

    return 0;
}
