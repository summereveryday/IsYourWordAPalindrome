//Defines our Queue

#include "pch.h"
#include <iostream>
#include <stdexcept>
#include <string>

struct Node {
	char data;
	Node *next;
};

struct Queue {
	Node *head; // points to the first element
	Node *tail; // points to the last element
};

// Like pushing... It adds something to the end of the queue
void enqueue(Queue &theQueue, char item) { // default is 0, but if you send it a different one it will take it
	Node *temp = new Node;
	temp->data = item;
	temp->next = NULL;

	// if queue is empty, both head and tail will point to the first thing you insert
	if (theQueue.head == NULL) {
		theQueue.head = temp;
		theQueue.tail = temp;
	}
	else {
		theQueue.tail->next = temp;
		theQueue.tail = temp;
		//Node* current = theQueue.head;
		//temp->next = current->next;
		//current->next = temp;

		//if (temp->next == NULL) { // Move the tail if the tail moved.
		//	theQueue.tail->next = temp;
		//	theQueue.tail = temp;
		//}
	}
}

bool isEmpty(Queue &theQueue) {
	return (theQueue.head == NULL);
}

// Peek at the first element
char front(Queue &theQueue) {
	if (isEmpty(theQueue)) {
		std::cout << "ERROR: Queue is empty" << std::endl;
		throw std::invalid_argument("Underflow Error");
	}
	return theQueue.head->data;
}

// Peek at the last element
char back(Queue &theQueue) {
	if (isEmpty(theQueue)) {
		std::cout << "ERROR: Queue is empty" << std::endl;
		throw std::invalid_argument("Underflow Error");
	}
	return theQueue.tail->data;
}

// Like popping. It removes the item from the front or head of the queue.
char dequeue(Queue &theQueue) {
	if (isEmpty(theQueue)) {
		std::cout << "ERROR: Queue is empty" << std::endl;
		throw std::invalid_argument("Underflow Error");
	}
	char value = theQueue.head->data;
	Node *temp = theQueue.head;
	theQueue.head = theQueue.head->next; // move the head since you dequeue from the front or head of the line
	delete temp; // always ensure you relase the memory

	// If we removed last element, set the tail to NULL as well
	// if(isEmpty(theQueue)

	return value;
}

void printQueue(Queue &theQueue) {
	if (isEmpty(theQueue)) {
		std::cout << "ERROR: Queue is empty" << std::endl;
		throw std::invalid_argument("Underflow Error");
	}
	else {
		std::cout << "Queue Contents: " << std::endl;
		Node* current = theQueue.head;
		while (current != NULL) {
			std::cout << current->data << std::endl;
			current = current->next;
		}
	}
}

int count(Queue &theQueue) {
	int queueSize = 0;
	if (isEmpty(theQueue)) {
		std::cout << "The Queue is empty.";
	}
	else {
		Node *current = theQueue.head;
		while (current != NULL) {
			queueSize++;
			current = current->next;
		}
	}
	return queueSize;
	}

void purgeQueue(Queue theQueue) {
	while (theQueue.head != NULL) {
		Node *current = theQueue.head;
		theQueue.head = theQueue.head->next;
		delete current;
	}
}