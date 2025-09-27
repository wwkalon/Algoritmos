// BINARY SEARCH

#include <vector>
#include <iostream>
using namespace std;


int bs_iterative (vector<int>& nums, int target) {

    int l = 0; int r = nums.size() - 1;
    int m = (l + r) / 2;
    
    while (l <= r) {        

        if (nums[m] == target) return m;
        else if (nums[m] < target) l = m + 1;
        else r = m - 1;
    }

    return -1;
}


int bs_recursive (vector<int>& nums, int target, int l, int r) {

    if (l > r) return -1;

    int m = (l + r) / 2;

    if (nums[m] ==  target) return m;
    if (nums[m] < target) return bs_recursive(nums, target, m + 1, r);
    else return bs_recursive(nums, target, l, m -  1); 
}


int main() {
    vector<int> v {1, 2, 3, 4, 5};
    cout << "index: " << bs_recursive(v, 3, 0, v.size() - 1);
}