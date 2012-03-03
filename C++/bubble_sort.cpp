// Name        : Bubble Sort
// Dependency  : vector
// Requirement : operator > defined for members in vvector
#include <iostream>
#include <vector>

using namespace std;

template<class T>
void bubble_sort(vector<T>& array){
    for(int i = 0; i < array.size(); i++){
        for(int j = 0; j < array.size() - i; j++){
            if(array[j] > array[j + 1]){
                swap(array[j], array[j + 1]);
            }
        }
        // for(int j = 0; j < array.size(); j++){
        //     cout << array[j] << " ";
        // }
        // cout << endl;
    }
}

int main(int argc, char** argv){
    vector<int> vec;

    for(int i = 20; i > 0; i--){
        vec.push_back(i);
    }

    bubble_sort(vec);

    for(vector<int>::iterator it = vec.begin(); it < vec.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}