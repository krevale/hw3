#include "stack.h"
#include <iostream>

using namespace std;

int main() {
	Stack<int> test;

	if (test.empty()) {
		cout << "Empty" << endl;
	} else {
		cout << "Not empty" << endl;
	}

	test.push(1);
	test.push(2);
	test.push(3);
	
	if (test.empty()) {
		cout << "Empty" << endl;
	} else {
		cout << "Not empty" << endl;
	}

	cout << "Size: " << test.size() << endl;

	cout << "Top: " << test.top() << endl;

	test.pop();

	cout << "Top: " << test.top() << endl;

	return 0;
}