// Name        : quick Sort
// Dependency  : vector
// Requirement : operator > defined for members in vvector

#include <iostream>
#include <vector>

using namespace std;

// in-place version
template<class T>
int partition(vector<T>& array, int left, int right, int pivot){
    swap(array[pivot], array[right]);
    pivot = right;

    int storeindex = left;
    for(int i = left; i < right; i++){
        if(array[i] < array[pivot]){
            swap(array[storeindex], array[i]);
            
            // debug output
            // sleep(1);
            // for(int j = left; j <= right; j++){
            //     if(j == i || j == storeindex){
            //         cout << "\033[0;33m" << array[j] << " \033[0m";
            //     }else{
            //         cout << array[j] << " ";
            //     }
            // }
            // cout << endl << endl;

            storeindex += 1;
        }
    }
    swap(array[storeindex], array[right]);

    return storeindex;
}

template<class T>
void quick_sort(vector<T>& array, int left, int right){
    if(left < right){
        int pivot = (left + right) / 2;
        int newpivot = partition(array, left, right, pivot);
        quick_sort(array, left, newpivot - 1);
        quick_sort(array, newpivot + 1, right);
    }
}

int main(int argc, char** argv){
    vector<int> vec;

    for(int i = 20; i > 0; i--){
        vec.push_back(i);
    }

    quick_sort(vec, 0, vec.size() - 1);

    for(vector<int>::iterator it = vec.begin(); it < vec.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
