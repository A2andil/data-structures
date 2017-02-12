//in the name of God

#include <iostream>
using namespace std;

struct Node {
        int data;
        Node *next;
};

class Queue {
private:
        Node *front, *rear;
        Node* createNode(int data) {
                Node *nd = new Node();
                nd->data = data;
                nd->next = NULL;
                return nd;
        }
public:
        Queue() {
                front = rear = NULL;
        }
        void enqueue(int data) {
                Node *nd = createNode(data);
                if (rear == NULL) {
                        front = rear = nd;
                        return;
                }
                rear->next = nd;
                rear = nd;
        }
        Node* dequeue() {
                if (front == NULL)
                        return NULL;
                Node *nd = front;
                front = front->next;
                if (front == NULL)
                        rear = NULL;
                return nd;
        }
};

int main() {
        Queue *queue = new Queue();
        queue->enqueue(10);
        queue->enqueue(20);
        queue->dequeue();
        queue->dequeue();
        queue->enqueue(30);
        queue->enqueue(40);
        queue->enqueue(50);
        Node *nd = queue->dequeue();
        if (nd != NULL)
                cout << "Dequeued item is " << nd->data << endl;
        return 0;
}
