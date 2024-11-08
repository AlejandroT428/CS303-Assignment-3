#include <iostream>

#include "queueLink.h"
#include "vectorN.h"

//Question 2: Modify so it displays the last occurence of the target.
template<typename Item_Type>
int linear_search(AT::vector<Item_Type>& items, int target, size_t pos_last) {
	if (pos_last == 0) {
		if (target == items[pos_last]) {
			return pos_last;
		}
		else {
			return -1;
		}
		
	}

	if (target == items[pos_last]) {
		return pos_last;
	}
	else {
		return linear_search(items, target, pos_last - 1);
	}
}

//Question 3: Modify so it sorts a queue of integers.
void insertion_sort(Queue <int>& userQueue) {
	int i, j, key;

	bool insertionNeeded = false;

	AT::vector<int> num;

	while (!userQueue.empty()) {
		num.push_back(userQueue.front());
		userQueue.pop();
	}

	for (j = 1; j < num.size(); j++) {
		key = num[j];
		insertionNeeded = false;


		for (i = j - 1; i >= 0; i--) {
			if (key < num[i]) {
				num[i + 1] = num[i]; // larger values move right
				insertionNeeded = true;
			}
			else {
				break;
			}
		}

		if (insertionNeeded) {
			num[i + 1] = key; // Put key into its proper location.
		}

	}

	for (i = 0; i < num.size(); i++) {
		userQueue.push(num[i]);
	}
}

int main() {

	/*
	Q1. (13 points) Implement the Queue data structure (you can use linked list or circular array
for implementation) with push(), pop(), front(), size() and empty() functions. The queue should
be a template class (should work with any data type). Perform the following operations:
*/
	//push()
	//pop()
	//front()
	//size()
	//empty()
	/*
a) Instantiate the queue with integers and push 10 values into the queue


b) Display all the elements in a queue using just the queue functions mentioned above
(push, pop, front, size etc.)


c) Write a new queue function called move_to_rear that moves the element currently at
the front of the queue to the rear of the queue. The element that was second in line will
be the new front element. Do this using functions push, front, and pop.


Q2. (5 points) Write a recursive linear search function with a recursive step that finds the last
occurrence of a target in a vector, not the first. You will need to modify the linear search
function (You can find it in the slides Lecture 9 slide 30).


Q3. (7 points) Modify the source code for the insertion sort so that it can sort a list (linked list
or you can also use queue) of integers (You can find the source code on lecture 10 slide 138*/
try {
	//Question 2: Modify so it takes the last occurence of a value. //NOT COMPLETED
	Queue<int> numPool;

	//Question 1
	// part a
	std::cout << "Question 1 part a: " << std::endl;

	for (int i = 0; i < 10; i++) {
		numPool.push(i);
		std::cout << "   Push: " << i << std::endl;
		numPool.displayQueue();
	}
	std::cout << std::endl;

	
	//part b
	std::cout << "Question 1 part b: " << std::endl;
	int tempSize = numPool.size();
	for (int i = 0; i < tempSize; i++) {
		std::cout << numPool.front() << std::endl;
		numPool.pop();
	}
	std::cout << std::endl;


	// part c
	std::cout << "Question 1 part c: " << std::endl;
	for (int i = 0; i < 10; i++) {
		numPool.push(i);
	}

	numPool.moveToRear();
	numPool.displayQueue();

	std::cout << std::endl;


	// Question 2
	std::cout << "Question 2: " << std::endl;

	AT::vector<int> test;
	test.push_back(1);
	test.push_back(3);
	test.push_back(4);
	test.push_back(8);
	test.push_back(2);
	test.push_back(8);
	test.push_back(10);
	test.push_back(10);

	
	int tempNum = linear_search(test, 8, test.size() - 1);
	
	std::cout << "Here is the given vector, linear_search is set to find the last instance of 8." << std::endl;
	for (int i = 0; i < test.size(); i++) {
		std::cout << test[i] << " ";
	}

	std::cout << std::endl << "This is the index of the last occurence: " << tempNum << std::endl << std::endl;

	// Question 3
	std::cout << "Question 3: " << std::endl;

	Queue<int> numPool2;
	numPool2.push(34);
	numPool2.push(36);
	numPool2.push(97);
	numPool2.push(48);
	numPool2.push(68);
	numPool2.push(83);
	numPool2.push(75);
	numPool2.push(11);

	std::cout << "This is the given Queue to sort: ";
	numPool2.displayQueue();
	std::cout << std::endl << "This is what it looks like after its sorted: ";
	insertion_sort(numPool2);
	numPool2.displayQueue();

}
catch (const std::out_of_range& ex) {
	std::cout << "\nERROR: " << ex.what() << std::endl;
}
catch (const std::invalid_argument& ex) {
	std::cout << "\nERROR: " << ex.what() << std::endl;
}
catch (const std::exception& ex) {
	std::cout << "\nERROR: " << ex.what() << std::endl;
}
// Catches any arguement out of the scope of errors.
catch (...) {
	std::cout << "Something happend with the code." << std::endl;
	return 0;
}

	return 0;
}