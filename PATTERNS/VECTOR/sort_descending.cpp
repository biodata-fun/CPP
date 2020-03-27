/*
 C++ program to sort a vector in descending order 
 USAGE: g++ -Wall -std=c++11 sort_descending.cpp -o sort_descending
 */

#include <iostream>
#include <vector>

using namespace std; 
  
int main() 
{ 
    vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 }; 
  
    sort(v.begin(), v.end(), greater<int>());
  
    cout << "Sorted \n"; 
    for (auto x : v) 
        cout << x << " "; 
  
    return 0; 
} 