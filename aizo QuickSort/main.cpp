#include "array.cpp"

using namespace std;

template<typename T>
void runProgram(Array<T>& array);

int main(){
    cout << "Choose data type:\n" << "1. int\n"
                                  << "2. float\n"
                                  << "3. double\n"
                                  << "4. char\n";
    int dataType;
    cout << "Your choice: ";
    cin >> dataType;
    switch (dataType) {
        case 1: {
            Array<int> array;
            runProgram(array);
            break;
        }
        case 2: {
            Array<float> array;
            runProgram(array);
            break;
        }
        case 3: {
            Array<double> array;
            runProgram(array);
            break;
        }
        case 4: {
            Array<char> array;
            runProgram(array);
            break;
        }default:{
            cout << "Not correct data type\n";
            break;
        }
    }
    return 0;
}

template<typename dataType>
void runProgram(Array<dataType>& array){
    bool arrayIsGenerated = false;
    while (true){
        cout << "\nMenu:\n" << "1. Uploud array from file\n"
                            << "2. Generate random array\n"
                            << "3. Show array\n"
                            << "4. Sort array\n"
                            << "5. Sort correctness checker\n"
                            << "6. Exit\n"
                            << "Choose: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:{
                cout << "Enter fileName: ";
                string filename;
                cin >> filename;
                array.loadFromFile(filename);
                arrayIsGenerated = true;
                break;
            }
            case 2:{
                cout << "Enter size of an array: ";
                int size;
                cin >> size;
                array.generateData(size);
                arrayIsGenerated = true;
                break;
            }
            case 3:{
                if (arrayIsGenerated){
                    cout << "Array: \n";
                    array.displayArray();
                } else cout << "An array has not been generated yet\n";
                break;
            }
            case 4:{
                if (arrayIsGenerated){
                    cout << "Sorting...\n";
                    array.quickSort(0, array.size()-1);
                    cout << "Sorted array:\n";
                    array.displayArray();
                } else cout << "First generate or load an array.\\n";
                break;
            }
            case 5:{
                cout << (arrayIsGenerated ? (array.sortCheck() ? "The array is sorted correctly\n" : "Error: The array is not sorted correctly.\\n") : "First generate or uploud the array\n");
                break;
            }
            case 6:{
                return;
            }
            default:{
                cout << "Your choice is not correct. Please try again:\n";
                break;
            }
        }
    }
}


