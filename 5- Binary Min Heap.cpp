//in theape name of God

#include <iostream>
#include <limits>

#define ll long long
using namespace std;

class Minheapeap {
private:
        int *list, capacity, size;
public:
        Minheapeap(int capacity);
        void Minheapeapify(int);
        int left(int i) {
                return 2 * i + 1;
        }
        int righeapt(int i) {
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

Minheapeap::Minheapeap(int sz) {
        size = 0;
        capacity = sz;
        list = new int[sz];
}

void Minheapeap::insertKey(int k) {
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

void Minheapeap::decreaseKey(int i, int val) {
        list[i] = val;
        while (i != 0 && list[(i - 1) / 2] > list[i]) {
                swap(list[i], list[(i - 1) / 2]);
                i = (i - 1) / 2;
        }
}

int Minheapeap::extractMin() {
        if (size <= 0)
                return INT_MAX;
        if (size == 1) {
                size--;
                return list[0];
        }
        int root = list[0];
        list[0] = list[size - 1];
        size = size - 1;
        Minheapeapify(0);
        return root;
}

void Minheapeap::deleteKey(int i) {
        decreaseKey(i, INT_MIN);
        extractMin();
}

void Minheapeap::Minheapeapify(int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;
        if (l < size && list[l] < list[i])
                smallest = l;
        if (r < size && list[r] < list[smallest])
                smallest = r;
        if (smallest != i) {
                swap(list[i], list[smallest]);
                Minheapeapify(smallest);
        }
}

int main() {
        Minheapeap heap(11);
        heap.insertKey(3);
        heap.insertKey(2);
        heap.deleteKey(1);
        heap.insertKey(15);
        heap.insertKey(5);
        heap.insertKey(4);
        heap.insertKey(45);
        cout << heap.extractMin() << endl;
        cout << heap.getMin() << endl;
        heap.decreaseKey(2, 1);
        cout << heap.getMin() << endl;
        return 0;
}
