#include "Dequeue.h"
#include <iostream>

bool Dequeue::isEmpty()const {
	return ((start == end) && (end == -1));
}

bool Dequeue::isFull() const {
	return ((end + 1) % SIZE == start);
}

int Dequeue::counter() const {
	if (isEmpty())
		return 0;
	else
		return (start <= end) ? (end - start + 1) : (SIZE - (start - end - 1));
}

int Dequeue::front() const {
	if (isEmpty()) {
		std::cout << "Front called when dequeue is empty\n";
		exit(1);
	}
	return buffer[start];
}

int Dequeue::back() const {
	if (isEmpty()) {
		std::cout << "Back is called when dequeue is empty\n";
		exit(1);
	}
	return buffer[end];
}

void Dequeue::reset(){
	start = end = -1;
}

bool Dequeue::popBack() {
	if (isEmpty()) {
		std::cout << "PopBack is called when dequeue is empty\n";
		return false;
	}
	if (start == end)
		reset();
	else if (end == 0)
		end = SIZE - 1;
	else
		end--;
	return true;
}

bool Dequeue::popFirst() {
	if (isEmpty()) {
		std::cout << "PopFirst is called when dequeue is empty\n";
		return false;
	}
	if (start == end)
		reset();
	else
		start = (start + 1) % SIZE;
	return true;
}

bool Dequeue::pushFirst(int element) {
	if (isFull()) {
		std::cout << "Dequeue is full\n";
		return false;
	}
	if (isEmpty()) {
		start++;
		buffer[++end] = element;
	}
	else if (start == 0) {
		start = SIZE - 1;
		buffer[start] = element;
	}
	else
		buffer[--start] = element;
	return true;
}

bool Dequeue::pushBack(int element) {
	if(isFull()) {
		std::cout << "Dequeue is full\n";
		return false;
	}
	if (isEmpty()) {
		start++;
		buffer[++end] = element;
	}
	else {
		end = (end + 1) % SIZE;
		buffer[end] = element;
	}
	return true;
}

void Dequeue::print() const {
	if (isEmpty())
		std::cout << "The dequeue is empty\n";
	else {
		for (int i = start; i != end; i = (i + 1) % SIZE)
			std::cout << buffer[i] << " -> ";
		std::cout << buffer[end] << std::endl;
	}
}