/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

// https://www.geeksforgeeks.org/insertion-sort-algorithm/
// https://www.geeksforgeeks.org/bubble-sort-algorithm/
// https://www.geeksforgeeks.org/selection-sort-algorithm-2/

using namespace std;

void sort_bubble(const vector<int> &v)
{
    vector<int> arr(v);
    const size_t n = arr.size();
    bool swapped = false;
    size_t i = 0;
    size_t j = 0;
    
    for (i = 0; i < n - 1; ++i) {
        swapped = false;
        for (j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
    
    for_each( arr.begin(), arr.end(), [](int i) { cout << i << " "; } );
    cout << endl;
    
    return;
}

void sort_insertion(const vector<int> &v)
{
    vector<int> arr(v);
    const size_t n = arr.size();
    size_t i = 0;
    size_t j = 0;
    int key = 0;
    
    for (i = 1; i < n; ++i) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key && j < n) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
    
    for_each( arr.begin(), arr.end(), [](int i) { cout << i << " "; } );
    cout << endl;
    
    return;
}

void sort_selection(const vector<int> &v)
{
    vector<int> arr(v);
    const size_t n = arr.size();
    size_t i = 0;
    size_t j = 0;
    size_t min_idx = 0;
    
    for (i = 0; i < n - 1; ++i) {
        min_idx = i;
        for (j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
    
    for_each( arr.begin(), arr.end(), [](int i) { cout << i << " "; } );
    cout << endl;
    
    return;
}

int main()
{
    vector<int> v = { 1, -2, -3, 4, 3, 8 };
    for_each( v.begin(), v.end(), [](int i) { cout << i << " "; } );
    cout << endl;
    
    sort_bubble(v);
    sort_selection(v);
    sort_insertion(v);
    
    for_each( v.begin(), v.end(), [](int i) { cout << i << " "; } );
    cout << endl;

    return 0;
}
