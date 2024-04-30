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
    dataType *data;
    int dataSize;
    int partition(int low, int high);
    void heapify(int n, int i);
public:
    Array(int size = 0) : data(new dataType[size]), dataSize(size) {}
    ~Array() { delete[] data; }

    void generateData(int size);
    void loadFromFile(const string& fileName);
    void quickSort(int left, int right);
    void insertionSort();
    void binaryInsertionSort();
    void heapSort();
    void displayArray() const;
    bool sortCheck() const;
    int size() const;
};

#endif

