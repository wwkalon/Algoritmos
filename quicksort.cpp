// QUICKSORT 

#include <vector>
#include <iostream>
using namespace std;


void printarr(vector<int>& arr) {

    int len = arr.size();   
    if (len < 0) return;

    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n";
}


int partition(vector<int>& arr, int l, int r) {

    if (arr.size() < 2) return -1;

    int pivot = arr[l];
    int i = l;
    int j = r + 1;

    do {
        do { i++; } while (arr[i] < pivot && i < r);
        do { j--; } while (arr[j] > pivot);
        swap(arr[i], arr[j]);

    } while (i < j);

    swap(arr[i], arr[j]);
    swap(arr[l], arr[j]);
    return j;
}


void quicksort(vector<int>& arr, int s, int e) {

    if (s >= e || arr.size() < 1) return;

    int p = partition(arr, s, e);
    quicksort(arr, s, p - 1);
    quicksort(arr, p + 1, e);
}


int main() {

    vector<int> nums {7, 3, 2, 2, 4, 0, 5};

    cout << "Array inicial: "; printarr(nums);
    cout << "\n";

    quicksort(nums, 0, nums.size() - 1);

    cout << "Array final: "; printarr(nums);
    cout << "\n";

    return 0;
}