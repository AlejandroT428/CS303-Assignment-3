//queueLink.h
#ifndef QUEUELINK_H_
#define QUEUELINK_H_

template<typename Item_type>

class Queue {
private:

	struct Node {
		//Data Fields 
		// the data
		Item_type data;
		// The pointer to the next node.
		Node* next;


		//Constructor
		/* Creates a new node that points to another Node.
		*	@param data_item the data stored
		*   @param next_ptr Pointer to the Node that is pointed to by the new Node.*/
		Node(const Item_type& data_item, Node* next_ptr = NULL) :
			data(data_item), next(next_ptr) {}
	};

	Node* head;
	Node* tail;
	size_t num_items;


public:
	// Constructor
	Queue();

	void push(const Item_type& item);
	void pop();
	Item_type& front();	// Return the data of the front node.
	size_t size() const;
	bool empty() const;	// is the queue empty?
	void moveToRear(); // moving the front item to the rear.

	void displayQueue();

	

};

template<typename Item_type>
Queue<Item_type>::Queue() {
	head = nullptr;
	tail = nullptr;
	num_items = 0;
}

template<typename Item_type>
void Queue<Item_type>::push(const Item_type& item) {
	if (head == NULL) {
		tail = new Node(item, NULL);
		head = tail;
	}
	else {
		tail->next = new Node(item, NULL);
		tail = tail->next;
	}
	num_items++;
}

template<typename Item_type>
void Queue<Item_type>::pop() {
	Node* tempHead = head;
	head = head->next;

	if (head == NULL) {
		tail = NULL;
	}

	delete tempHead;
	num_items--;
}

template<typename Item_type>
Item_type& Queue<Item_type>::front() {
	return head->data;
}

template<typename Item_type>
size_t Queue<Item_type>::size() const {
	return num_items;
}

template<typename Item_type>
bool Queue<Item_type>::empty() const {
	if (head == NULL) {
		return true;
	}
	else {
		return false;
	}
}

template<typename Item_type>
void Queue<Item_type>::moveToRear() { // moving the front item to the rear.
	
	Item_type tempData = this->front();
	this->pop();
	this->push(tempData);
}

template<typename Item_type>
void Queue<Item_type>::displayQueue() {
	Node* current = head;
	while (current) {
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;
}


#endif