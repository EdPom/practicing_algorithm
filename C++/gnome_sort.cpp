// Name        : Gnome Sort
// Dependency  : vector
// Requirement : operator > defined for members in vvector
#include <iostream>
#include <vector>

using namespace std;

template<class T>
void gnome_sort(vector<T>& array){
    int index = 1;
    while(index < array.size()){
        if(array[index] >= array[index - 1]){
            index += 1;
        }else{
            swap(array[index], array[index - 1]);
            if(index > 1){
                index -= 1;
            }else{
                index += 1;
            }
        }
    }
}

int main(int argc, char** argv){
    vector<int> vec;

    for(int i = 20; i > 0; i--){
        vec.push_back(i);
    }

    gnome_sort(vec);

    for(vector<int>::iterator it = vec.begin(); it < vec.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}