// Name        : Insertion Sort
// Dependency  : vector
// Requirement : operator > defined for members in vvector

#include <iostream>
#include <vector>

using namespace std;

template <class T>
void insertion_sort(vector<T>& array){
    if(array.size() < 2){
        return;
    }

    for(int i = 1; i < array.size(); i++){
        for(int j = i - 1; j >= 0; j--){
            if(array[j] > array[j + 1]){
                swap(array[j], array[j + 1]);
            }else{
                break;
            }
        }
    }
}

int main(int argc, char** argv){
    vector<int> vec;

    for(int i = 100; i > 0; i--){
        vec.push_back(i);
    }

    insertion_sort(vec);

    int j = 1;
    int k = 0;
    for(vector<int>::iterator it = vec.begin(); it < vec.end(); it++){
        k++;
        cout << *it << " ";
        if(k == j){
            j *= 2;
            k = 0;
            cout << endl;
        }
    }
    cout << endl;

    return 0;
}