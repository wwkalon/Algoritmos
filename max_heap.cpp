// HEAP IMPLEMENTATION

#include <vector>
#include <iostream>
using namespace std;


class Heap {
public:

    int size;

    Heap() { this->size = 0; };
    Heap(vector<int>& arr) {

        this->heap = arr;
        this->size = arr.size();
        for (int i = size/2; i >= 0; i--) { heapify_down(i); }
    };


    void insert(int value) {

        this->heap.push_back(value);
        this->size++;
        heapify_up(size - 1);
    }


    int pop() {

        int top = this->heap[0];

        swap(this->heap[0], this->heap[size - 1]);
        this->heap.pop_back();
        this->size--;
        heapify_down(0);

        return top;
    }


    void heapsort() {

        int init_size = this->size;

        for (int i = 0; i < size; i++) {
            swap(this->heap[0], this->heap[i]);
            this->size--;
            heapify_down(0);
        }

        this->size = init_size;
    };
    

private:

    vector<int> heap;

    void heapify_down(int key) {

        int val = this->heap[key];
        bool is_heap = false;

        while (!is_heap && 2*key + 1 <= size) {

            int c = 2*key + 1;

            if(c < size && this->heap[c] < this->heap[c + 1]) c++;
            if (val >= this->heap[c]) is_heap = true;
            else {
                this->heap[key] = this->heap[c];
                key = c;
            }
        }

        this->heap[key] = val;
    };


    void heapify_up(int key) {

        int val = this->heap[key];
        bool is_heap = false;

        while (!is_heap && key > 0) {

            int p = (key - 1)/2;

            if (this->heap[p] < this->heap[key]) {         
                this->heap[key] = this->heap[p];
                this->heap[p] = val;
                key = p;
            }

            else is_heap = true;
        }
    } 
};


int main() {
    return 0;
}