// Name        : Merge Sort
// Dependency  : vector
// Requirement : operator < defined for members in vvector

#include <vector>
#include <iostream>

using namespace std;

template <class T>
vector<T> merge(vector<T>& left, vector<T>& right){
    vector<T> result;

    while(!left.empty() || !right.empty()){
        if(!left.empty() && !right.empty()){
            if(left.front() < right.front()){
                result.push_back(left.front());
                left.erase(left.begin());
            }else{
                result.push_back(right.front());
                right.erase(right.begin());
            }
        }else if(!left.empty()){
            result.push_back(left.front());
            left.erase(left.begin());
        }else if(!right.empty()){
            result.push_back(right.front());
            right.erase(right.begin());
        }
    }

    return result;
}

template <class T>
vector<T>& merge_sort(vector<T>& list){
    if(list.size() <= 1)
        return list;

    int mid = list.size() / 2;
    vector<T> left(list.begin(), list.begin() + mid);
    merge_sort(left);
    vector<T> right(list.begin() + mid, list.end());
    merge_sort(right);

    list = merge<T>(left, right);

    return list;
}

int main(){
    vector<int> arr;
    for(int i = 100; i > 0; i--){
        arr.push_back(i);
    }

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << ',';
    }
    cout << endl;

    // return 0;

    arr = merge_sort<int>(arr);

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << ',';
    }
    cout << endl;

    return 0;
}