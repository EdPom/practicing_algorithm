// Name        : Heap Sort
// Dependency  : vector
// Requirement : operator <= defined for members in vvector
#include <iostream>
#include <vector>
#include <iterator>
#include <time.h>

using namespace std;

template <class T>
void siftdown(vector<T>& array, int start, int end){
    // start is the position of the parent ndoe
    // end is the position of the last node
    int root = start;
    int child;
    int  biggest;
    while(root * 2 + 1 <= end){
        // left shild
        child = root * 2 + 1;

        // not using the reference method
        // since we cannot track the index using this method
        // T& minimum = (T&) max(max(array[root], array[child]),
        //                       array[child + 1]);

        // if the root is smaller than its children, swap them
        biggest = array[child] >= array[root] ? child : root;
        // only comapre the right child when there is one
        if(child + 1 <= end){
            biggest = array[biggest] >= array[child + 1] ? biggest : child + 1;
        }

        if(biggest != root){
            // debug output
            // if(end <= 4){
            //     sleep(1);
            //     cout << " Swap " << root << " -> " << biggest;
            //     cout << " (" << array[root] << " -- " << array[child];
            //     cout << ", " <<  array[child + 1] << endl;
            // }

            swap(array[root], array[biggest]);

            // if(end <= 4){
            //     for(int i = 0, j = 1, k =1; i < array.size(); i++, k++){
            //         if(i == root || i == biggest){
            //             cout << "\033[0;33m" << array[i] << " \033[0m";
            //         }else{
            //             cout << array[i] << " ";
            //         }
            //         if(k == j){
            //             cout << endl;
            //             j *= 2;
            //             k = 0;
            //         }
            //     }
            //     cout << endl;
            // }

            // update the root index, and go to the next iteration
            root = biggest;
        }else{
            return;
        }
    }
}

template <class T>
void heapfy(vector<T>& array){
    // nothing to do if the array has only 1 or no elements
    if(array.size() <= 1){
        return;
    }

    // location of the last parent node
    int start = (array.size() - 1) / 2;

    while(start >= 0){
        siftdown(array, start, array.size() - 1);
        start -= 1;
    }

}

template <class T>
void heap_sort(vector<T>& array){
    vector<T> sorted_array;
    heapfy(array);

    int end = array.size() - 1;
    while(end > 0){
        // swap the first one (the biggest element) to the back
        swap(array[0], array[end]);
        // should not touch the tail of the vector since they are sorted
        end -= 1;
        // make the heap valid again
        siftdown(array, 0, end);
    }

    return;
}

int main(int argc, char** argv){
    vector<int> vec;

    for(int i = 0; i < 100; i++){
        vec.push_back(i);
    }

    // swap(vec[0], (int&) min(vec[0], vec[1]));
    // swap(vec[0], (int&) min(min(vec[0], vec[1]), vec[2]));

    heapfy(vec);

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
    cout << endl << endl;

    heap_sort(vec);

    j = 1;
    k = 0;
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