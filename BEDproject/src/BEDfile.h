//
// Created by ernesto lowy gallego on 2019-09-16.
//
#include <iostream>

#ifndef BEDFILE_BEDFILE_H
#define BEDFILE_BEDFILE_H

using namespace std;

class BEDFile
{
    public:
        BEDFile(string apath);
        ~BEDFile();
        void getFeatNumber(); // Class member function initialization
    private: string path;
};

#endif //BEDFILE_BEDFILE_H
