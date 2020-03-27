/*
 C++ program to sort a vector in asceding order 
 USAGE: g++ -Wall -std=c++11 sort_ascending.cpp -o sort_ascending
 */

#include <iostream>
#include <vector>

using namespace std; 
  
int main() 
{ 
    vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 }; 
  
    sort(v.begin(), v.end()); 
  
    cout << "Sorted \n"; 
    for (auto x : v) 
        cout << x << " "; 
  
    return 0; 
} 