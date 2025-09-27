//  MERGESORT

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


void merge(vector<int>& arr, int l, int r) {

    vector<int> temp (arr.size());
    for (int i = l; i <= r; i++) temp[i] = arr[i];

    int m = (l + r) / 2;
    int i1 = l;
    int i2 = m + 1;

    for (int cur = l; cur <= r; cur++) {

        if (i1 == m + 1) arr[cur] = temp[i2++];
        else if (i2 > r) arr[cur] = temp[i1++];
        else if (temp[i1] <= temp[i2]) arr[cur] = temp[i1++];
        else arr[cur] = temp[i2++];
    }
}


void mergesort(vector<int>& arr, int l, int r) {

    if (l < r) {

        int m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, r);
    }
}


int main() {

    vector<int> nums {-4,0,7,9, 4,-5,-1,0,-7,-1};

    cout << "Array inicial: "; printarr(nums);
    cout << "\n";

    mergesort(nums, 0, nums.size() - 1);

    cout << "Array final: "; printarr(nums);
    cout << "\n";

    return 0;
}