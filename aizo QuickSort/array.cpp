#include <limits>
#include <cstdint>
#include <cstring>
#include "array.h"

using namespace std;

template<typename dataType>
    void Array<dataType>::generateData(int size) {
        dataSize = size;
        delete[] data;
        data = new dataType[size];
        srand(time(nullptr));
        for (int i = 0; i < size; ++i) {
            if constexpr (std::is_same_v<dataType, int>) {
                data[i] = rand();
            } else if constexpr (std::is_floating_point<dataType>::value) {
                data[i] = static_cast<float>(rand())/RAND_MAX * size;
            }
            else {
                data[i] = 'a' + rand() % 26;
            }
        }
    }

template<typename dataType>
void Array<dataType>::loadFromFile(const string& fileName) {
    ifstream file(fileName);
    if (!file) {
        cerr << "Error reading file: " << fileName << endl;
        exit(EXIT_FAILURE);
    }
    if (!(file >> dataSize) || dataSize <= 0) {
        cerr << "Invalid array size in file: " << fileName << endl;
        exit(EXIT_FAILURE);
    }
    delete[] data;
    // Zwiększamy rozmiar tablicy o 1 dla przechowywania dataSize
    data = new dataType[dataSize + 1];
    // W pierwszym elemencie tablicy zapisujemy dataSize
    data[0] = dataSize;
}

template<typename dataType>
void Array<dataType>::displayArray() const {
    for (int i = 0; i < dataSize; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
}

template<typename dataType>
bool Array<dataType>::sortCheck() const {
    for (int i = 1; i < dataSize; ++i) {
        if (data[i] < data[i - 1]) {
            return false;
        }
    }
    return true;
}

template<typename dataType>
void Array<dataType>::quickSort(int left, int right) {
    if (left >= right) return;
    int m = partition(left, right);
    quickSort(left, m);
    quickSort(m + 1, right);
}

template<typename dataType>
int Array<dataType>::partition(int left, int right){
    dataType pivot = data[left];
    int l = left; int r = right;
    while (1){
        while(data[l] < pivot) ++l;
        while(data[r] > pivot) --r;
        if (l < r){
            swap(data[l],data[r]);
            ++l;
            --r;
        }else{
            if (r == right) r--;
            return r;
        }
    }
}

template<typename dataType>
void Array<dataType>::insertionSort() {
    for (int i = 1; i < dataSize; ++i) {
        dataType key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
}

template<typename dataType>
void Array<dataType>::binaryInsertionSort() {
    for (int i = 1; i < dataSize; ++i) {
        dataType key = data[i];
        int left = 0;
        int right = i - 1;
        int j = i - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (data[mid] < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        while (j >= left) {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
}

template<typename dataType>
void Array<dataType>::heapSort() {
    for (int i = dataSize / 2 - 1; i >= 0; i--)
        heapify(dataSize, i);

    for (int i = dataSize - 1; i > 0; i--) {
        swap(data[0], data[i]);
        heapify(i, 0);
    }
}

template<typename dataType>
void Array<dataType>::heapify(int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && data[left] > data[largest])
        largest = left;

    if (right < n && data[right] > data[largest])
        largest = right;

    if (largest != i) {
        swap(data[i], data[largest]);
        heapify(n, largest);
    }
}

template<typename dataType>
int Array<dataType>::size() const {
    return dataSize;
}