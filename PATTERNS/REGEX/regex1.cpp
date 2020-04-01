/**
Snippet using a simple regex:
USAGE : g++ regex1.cpp -o regex1
**/
#include <iostream>
#include <regex>

using namespace std;
int main()
{
    string a = "GeeksForGeeks";

    // Here b is an object of regex (regular expression)
    regex b("(Geek)(.*)"); // Geeks followed by any character

    // regex_match function matches string a against regex b
    if ( regex_match(a, b) )
        cout << "String 'a' matches regular expression 'b' \n";
    
    return 0;
}