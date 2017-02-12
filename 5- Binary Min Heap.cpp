//in the name of God

#include <iostream>
#include <limits>

using namespace std;

void swap(int *x, int *y);

class MinHeap {
private:
        int *list;
        int capacity;
        int size;
public:
        MinHeap(int capacity);
        void MinHeapify(int);
        int parent(int i) {
                return (i - 1) / 2;
        }
        int left(int i) {
                return 2 * i + 1;
        }
        int right(int i) {
                return 2 * i + 2;
        }
        int extractMin();
        void decreaseKey(int i, int value);
        int getMin() {
                return list[0];
        }
        void deleteKey(int i);
        void insertKey(int k);
};

MinHeap::MinHeap(int sz) {
        size = 0;
        capacity = sz;
        list = new int[sz];
}

void MinHeap::insertKey(int k) {
        if (size == capacity) {
                cout << "\nOverflow: Could not insertKey\n";
                return;
        }
        size = size + 1;
        int i = size - 1;
        list[i] = k;
        while (i != 0 && list[parent(i)] > list[i]) {
                swap(&list[i], &list[parent(i)]);
                i = parent(i);
        }
}

void MinHeap::decreaseKey(int i, int val) {
        list[i] = val;
        while (i != 0 && list[parent(i)] > list[i]) {
                swap(&list[i], &list[parent(i)]);
                i = parent(i);
        }
}

int MinHeap::extractMin() {
        if (size <= 0)
                return INT_MAX;
        if (size == 1) {
                size--;
                return list[0];
        }
        int root = list[0];
        list[0] = list[size - 1];
        size--;
        MinHeapify(0);
        return root;
}

void MinHeap::deleteKey(int i) {
        decreaseKey(i, INT_MIN);
        extractMin();
}

void MinHeap::MinHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < size && list[l] < list[i])
                smallest = l;
        if (r < size && list[r] < list[smallest])
                smallest = r;
        if (smallest != i) {
                swap(&list[i], &list[smallest]);
                MinHeapify(smallest);
        }
}

void swap(int *x, int *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
}

int main() {
        MinHeap h(11);
        h.insertKey(3);
        h.insertKey(2);
        h.deleteKey(1);
        h.insertKey(15);
        h.insertKey(5);
        h.insertKey(4);
        h.insertKey(45);
        cout << h.extractMin() << endl;
        cout << h.getMin() << endl;
        h.decreaseKey(2, 1);
        cout << h.getMin() << endl;
        return 0;
}
