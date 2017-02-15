//in the name of God

#include <iostream>
#include <limits>

#define ll long long
using namespace std;

class MinHeap {
private:
        ll *list, capacity, size;
        void MinHeapify(int i) {
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
public:
        MinHeap(int sz) {
                size = 0;
                capacity = sz;
                list = new ll[sz];
        }
        ll ExtractMin() {
                if (size <= 0)
                        return INT_MAX;
                if (size == 1) {
                        size = size - 1;
                        return list[0];
                }
                ll root = list[0];
                list[0] = list[size - 1];
                size = size - 1;
                MinHeapify(0);
                return root;
        }
        void UpdateKey(int i, int val) {
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
        ll GetMin() {
                if (!size)
                        return INT_MIN;
                return list[0];
        }
        void DeleteKey(int i) {
                UpdateKey(i, INT_MIN);
                ExtractMin();
        }
        void InsertKey(ll k) {
                if (size == capacity) {
                        cout << "Overflow: Could not insertKey" << endl;
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
};


class PriorityQueue {
private:
        MinHeap *hp;
public:
        PriorityQueue(int sz) {
                hp = new MinHeap(sz);
        }
        ll top() {
                return hp->GetMin();
        }
        void remove() {
                hp->ExtractMin();
        }
        void add(ll k) {
                hp->InsertKey(k);
        }
};
int main() {
        PriorityQueue *pq = new PriorityQueue(1000);
        pq->add(1), pq->add(5), pq->add(-2);
        cout << pq->top() << endl;
        pq->remove();
        cout << pq->top() << endl;
        return 0;
}
