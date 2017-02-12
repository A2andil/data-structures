//in theape name of God

#include <iostream>
#include <limits>

#define ll long long
using namespace std;

class MinHeap {
private:
        int *list, capacity, size;
public:
        MinHeap(int capacity);
        void MinHeapify(int);
        int ExtractMin();
        void UpdateKey(int i, int value);
        int GetMin() {
                return list[0];
        }
        void DeleteKey(int i);
        void InsertKey(int k);
};

MinHeap::MinHeap(int sz) {
        size = 0;
        capacity = sz;
        list = new int[sz];
}

void MinHeap::InsertKey(int k) {
        if (size == capacity) {
                cout << "\nOverflow: Could not insertKey\n";
                return;
        }
        size = size + 1;
        int i = size - 1;
        list[i] = k;
        while (i != 0 && list[(i - 1) / 2] > list[i]) {
                swap(list[i], list[(i - 1) / 2]);
                i = (i - 1) / 2;
        }
}

void MinHeap::UpdateKey(int i, int val) {
        if (val < list[i]) {
                list[i] = val;
                while (i != 0 && list[(i - 1) / 2] > list[i]) {
                        swap(list[i], list[(i - 1) / 2]);
                        i = (i - 1) / 2;
                }
        }
        else if (val > list[i]) {
                list[i] = val;
                MinHeapify(i);
        }
}

int MinHeap::ExtractMin() {
        if (size <= 0)
                return INT_MAX;
        if (size == 1) {
                size = size - 1;
                return list[0];
        }
        int root = list[0];
        list[0] = list[size - 1];
        size = size - 1;
        MinHeapify(0);
        return root;
}

void MinHeap::DeleteKey(int i) {
        UpdateKey(i, INT_MIN);
        ExtractMin();
}

void MinHeap::MinHeapify(int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;
        if (l < size && list[l] < list[i])
                smallest = l;
        if (r < size && list[r] < list[smallest])
                smallest = r;
        if (smallest != i) {
                swap(list[i], list[smallest]);
                MinHeapify(smallest);
        }
}

int main() {
        MinHeap heap(11);
        heap.InsertKey(3);
        heap.InsertKey(2);
        heap.DeleteKey(1);
        heap.InsertKey(15);
        heap.InsertKey(5);
        heap.InsertKey(4);
        heap.InsertKey(45);
        cout << heap.ExtractMin() << endl;
        cout << heap.GetMin() << endl;
        heap.UpdateKey(2, 1);
        cout << heap.GetMin() << endl;
        return 0;
}
