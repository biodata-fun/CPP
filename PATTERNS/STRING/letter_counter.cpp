/*
Script that implements a letter counter.
It returns the total number of letter in a string
USAGE: g++ -g letter_counter.cpp -o letter_counter
*/
#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
    string str = "anyString";
    int cnt = 0;
    for(int i=0; str[i]; i++)
        cnt++;
    cout << cnt << endl;
    return 0;
}