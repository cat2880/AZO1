#include "array.h"

using namespace std;

template<typename dataType>
void Array<dataType>::generateData(int size) {
    data.clear();
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        if constexpr ( is_same_v<dataType, float> || is_same_v<dataType, double> ){
            data.push_back(static_cast<dataType>(rand()+rand()/static_cast<dataType>(RAND_MAX)));
        }else if constexpr ( is_same_v<dataType, char>){
            data.push_back('a' + rand() % 26);
        }else{
            data.push_back(rand() % 1000);
        }
    }
}

template<typename dataType>
void Array<dataType>::loadFromFile(const string& fileName){
    data.clear();
    ifstream file(fileName);
    if (!file){
        cerr<<"Error reading file: "<<fileName<<endl;
        exit(EXIT_FAILURE);
    }
    int size;
    file >> size;
    dataType fileData;
    for (int i = 0; i < size; ++i) {
        if (!(file >> fileData)){
            cerr<<"Error reading file: "<<fileName<<endl;
            exit(EXIT_FAILURE);
        }else{
            data.push_back(fileData);
        }
    }
}

template<typename dataType>
void Array<dataType>::displayArray() const{
    for(const auto& element : data){
        cout << element << " ";
    } cout<<endl;
}

template<typename dataType>
bool Array<dataType>::sortCheck() const {
    for (int i = 1; i < data.size(); ++i) {
        if (data[i] < data[i - 1]) {
            return false; // Zwracamy false, jeśli znaleziono nieposortowaną parę
        }
    }
    return true; // Zwracamy true, jeśli żadna para nie została znaleziona
}

template<typename dataType>
void Array<dataType>::quickSort(int left, int right){
    if (left >= right) return;
    int m = partition(left, right);
    quickSort(left,m);
    quickSort(m+1, right);
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

/*template<>
void Array<char>::quickSort(int left, int right) {
    sort(data.begin(), data.end());
}*/

template<typename dataType>
int Array<dataType>::size() const {
    return data.size();
}