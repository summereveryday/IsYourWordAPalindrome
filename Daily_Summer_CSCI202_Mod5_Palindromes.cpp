// Daily_Summer_CSCI202_Mod5_Palindromes.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Summer Daily
// CSCI 202 Mod 5 Assignment
// Uses a queue and stack to see if an entered word is a palindrome.

#include "pch.h"
#include <iostream>
#include <cctype>
#include "defineQueue.h"
#include "defineStack.h"

int main()
{
	char c;
	Stack wordStack;
	Queue wordQ;

	//initialize Queue
	wordQ.head = NULL;
	wordQ.tail = NULL;

	// Change entered word to all lowercase
	// Store word in Queue
	std::cout << "Enter a word: ";
	do {
		std::cin.get(c);
		if (isupper(c)) {
			c = tolower(c);
		}
		if (c != '\n') {
			enqueue(wordQ, c);
		}
	} while (c != '\n');

	//Initialize Stack
	int stackSize = count(wordQ);
	initializeStack(wordStack, stackSize);

	//Store word in Stack
	Node* temp = wordQ.head;
	for (int i = 0; i < stackSize; i++) {
		push(wordStack, temp->data);
		temp = temp->next;
	}

	//As long as their are still letters to compare and as long as the front of the queue and top of the stack match, it's a palindrome.
	while ((!isEmpty(wordQ) || !isEmpty(wordStack)) && (front(wordQ) == peek(wordStack))) {
		if (!isEmpty(wordQ) && !isEmpty(wordStack)) { // You don't want to try to pop or dequeue from an empty list
			pop(wordStack);
			dequeue(wordQ);
		}
	}
	
	if (isEmpty(wordQ) && isEmpty(wordStack)) {
			std::cout << "Your word is a palindrome." << std::endl;
		}
	else {
		std::cout << "Your word is not a palindrome." << std::endl;
	}

	std::cout << "Press any key to continue...";
	while ((getchar()) != '\n');
	return 0;
}

