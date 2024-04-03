#ifndef AIZO_ARRAY_H
#define AIZO_ARRAY_H

#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
template <typename dataType>
class Array{
private:
    vector<dataType> data;
    int partition(int low, int high);
public:
    Array(){}

    void generateData(int size);
    void loadFromFile(const string& fileName);
    void quickSort(int left, int right);
    void displayArray() const;
    bool sortCheck() const;
    int size() const;
};

#endif
