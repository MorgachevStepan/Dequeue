#define SIZE 5

class Dequeue {
	int start = -1, end = -1;
	int buffer[SIZE];

public:
	Dequeue() = default;
	bool isEmpty() const;
	bool isFull() const;
	int counter() const;
	int front() const;
	int back() const;
	void reset();
	bool popFirst();
	bool popBack();
	bool pushFirst(int);
	bool pushBack(int);
	void print() const;
};