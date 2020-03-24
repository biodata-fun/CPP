/*
Add integers to a Vector of integers
USAGE: g++ -g add_int_elements.cpp -o add_int_elements
*/
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> myvector;

	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	for (int i = 0; i<myvector.size(); i++) {
		std::cout << myvector.at(i) << ' ';
	}
}