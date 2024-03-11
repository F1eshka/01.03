#include <iostream>
using namespace std;

template <typename T>
class Deque {
	T* arr;
	int capacity = 10;
	int front = 0;
	int rear = -1;
	int size = 0;
public:
	Deque() {
		capacity = 10;
		front = 0;
		rear = -1;
		size = 0;
		arr = new T[capacity];
	}

	~Deque() {
		delete[] arr;
	}

	void push_back(T& node) {
		rear = (rear + 1) % capacity;
		arr[rear] = node;
		size++;
	}

	void push_front(T& node) {
		if (size == capacity) {
			cout << "Deque is full\n";
			return;
		}
		front = (front - 1 + capacity) % capacity;
		arr[front] = node;
		size++;
	}

	void pop_back() {
		if (size == 0) {
			cout << "Deque is empty\n";
			return;
		}
		rear = (rear - 1 + capacity) % capacity;
		size--;
	}

	void pop_front() {
		if (size == 0) {
			cout << "Deque is empty\n";
			return;
		}
		front = (front + 1) % capacity;
		size--;
	}

	void print() {
		int current = front;
		for (int i = 0; i < size; i++) {
			cout << arr[current] << " ";
			current = (current + 1) % capacity;
		}
		cout << "\n";
	}
};

int main() {
	Deque<int> dq;
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;

	dq.push_back(a);
	dq.push_front(b);
	dq.push_back(c);
	dq.push_front(d);
	dq.print();
	dq.pop_back();
	dq.pop_front();
	dq.print();
}