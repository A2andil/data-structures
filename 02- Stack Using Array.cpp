//in the name of God

#include <iostream>
#include <limits.h>

#define ll long long
using namespace std;

class Stack {
private:
	int start = 0, end = 0, sz = 1e5 + 5;
	int *list = new int[sz];
public:
	int isEmpty() {
		return end < start || !end;
	}
	void push(int data) {
		list[end++] = data;
	}
	int pop() {
		if (isEmpty()) return INT_MIN;
		return list[--end];
	}
	int peek() {
		if (isEmpty()) return INT_MIN;
		return list[end - 1];
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