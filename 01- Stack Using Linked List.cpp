//in the name of God

#include <iostream>
#include <limits.h>

#define ll long long
using namespace std;

struct Node {
        int data;
        Node *next;
};

class Stack {
private:
        Node *head = NULL;
        Node* createNode(int data) {
                Node *nd = new Node();
                nd->data = data;
                nd->next = NULL;
                return nd;
        }
public:
        int isEmpty() {
                return !head;
        }
        void push(int data) {
                Node* nd = createNode(data);
                nd->next = head;
                head = nd;
        }
        int pop() {
                if (isEmpty()) return INT_MIN;
                Node *nd = head;
                head = head->next;
                int rs = nd->data;
                free(nd);
                return rs;
        }
        int peek() {
                if (isEmpty()) return INT_MIN;
                return head->data;
        }
};

int main() {
        Stack *stack = new Stack();
        stack->push(10);
        stack->push(20);
        stack->push(30);
        cout << stack->pop() << endl;
        cout << "Top element is " << stack->peek() << endl;
        return 0;
}
