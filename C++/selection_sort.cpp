// Name        : Selection Sort
// Dependency  : vector
// Requirement : operator > defined for members in vvector

#include <iostream>
#include <vector>

using namespace std;

template<class T>
void selection_sort(vector<T>& array){
    int index;
    int minpos;

    for(int i = 0; i < array.size() - 1; i++){

        // find the next minimum
        minpos = i;
        for(int j = i + 1; j < array.size(); j++){
            if(array[j] < array[minpos]){
                minpos = j;
            }
        }

        // new minimum found, move it to the left
        if(minpos != i){
            swap(array[i], array[minpos]);
        }
    }
}

int main(int argc, char** argv){
    vector<int> vec;

    for(int i = 20; i > 0; i--){
        vec.push_back(i);
    }

    selection_sort(vec);

    for(vector<int>::iterator it = vec.begin(); it < vec.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
