//in the name of God

#include <iostream>
#include <limits>
using namespace std;

struct Node {
        int data;
        Node *next;
};

class Queue {
private:
        int *list, _front, _rear, size, capacity;
        Node* createNode(int data) {
                Node *nd = new Node();
                nd->data = data;
                nd->next = NULL;
                return nd;
        }
public:
        Queue(unsigned int sz) {
                this->capacity = sz;
                list = new int[sz];
                _front = 0, size = 0, _rear = sz - 1;
        }
        int isFull() {
                return size == capacity;
        }
        int isEmpty() {
                return !size;
        }
        void enqueue(int data) {
                if (!isFull()) {
                        _rear = (_rear + 1) % capacity;
                        list[_rear] = data;
                        size = size + 1;
                }

        }
        int dequeue() {
                if (!isEmpty()) {
                        int rs = list[_front];
                        _front = (_front + 1) % capacity;
                        size = size - 1;
                        return rs;
                }
                return INT_MIN;
        }
        int front() {
                if (!isEmpty()) {
                        list[_front];
                }
                return INT_MIN;
        }
        int rear() {
                if (!isEmpty()) {
                        return list[_rear];
                }
                return INT_MIN;
        }
};

int main() {
        Queue *queue = new Queue(1000);
        queue->enqueue(10);
        queue->enqueue(20);
        queue->enqueue(30);
        queue->enqueue(40);
        queue->enqueue(50);
        cout << "Dequeued item is" << queue->dequeue() << endl;
        return 0;
}
