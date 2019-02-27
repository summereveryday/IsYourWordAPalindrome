//Defines our Stack

#include "pch.h"
#include <iostream>
#include <stdexcept>

struct Stack {
	char *data;
	int stacktop;
	int numElements;
};

void initializeStack(Stack &theStack, int stackSize) {		// Need to make sure you pass by reference so you can modify the stack
	theStack.numElements = stackSize;
	theStack.data = new char[theStack.numElements]; // allocated memory
	theStack.stacktop = 0; // set it to empty
}

bool isEmpty(Stack theStack) {
	return (theStack.stacktop == 0);
}

char peek(Stack theStack) {
	if (isEmpty(theStack)) {	//make sure stack isn't empty
		throw std::invalid_argument("Underflow Error");
	}
	return theStack.data[--theStack.stacktop];
}

bool isFull(Stack theStack) {
	return (theStack.stacktop == theStack.numElements);
}

void push(Stack &theStack, char newValue) { //pass by reference
	if (isFull(theStack)) {
		throw std::invalid_argument("Overflow Error");
	}
	theStack.data[theStack.stacktop++] = newValue; // theStack.stacktop++ means that after putting newValue in stacktop
													// you increment stacktop
}

char pop(Stack &theStack) {  // pass by reference
	if (isEmpty(theStack)) {
		throw std::invalid_argument("Underflow Error");
	}
	return theStack.data[--theStack.stacktop]; // Decrement first and then use the value.
}