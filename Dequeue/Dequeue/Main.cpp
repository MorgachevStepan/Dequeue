#include "Dequeue.h"
#include <iostream>

int main() {
	Dequeue dq;
	dq.pushBack(1);
	dq.pushBack(2);
	dq.print();
	dq.pushFirst(0);
	dq.pushFirst(-1);
	dq.print();
	dq.pushFirst(-2);
	dq.pushBack(3);
	dq.print();
	dq.popBack();
	dq.pushFirst(-3);
	dq.print();
	dq.pushBack(2);
	dq.popFirst();
	dq.pushBack(2);
	dq.print();
}