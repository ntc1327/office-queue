#include <iostream>
#include "dequeue.h"

// constructors and destructor
dequeue::dequeue() {
	head = rear = NULL;
} // constructor

dequeue::~dequeue() {
	person * temp = head; // starts the person that will be deallocated each time at the head

	// executes while the temp is not null, effectively running through the list
	while (temp) {
		person * next = temp->next; // stores the next person after temp
		delete temp; // deletes temp
		temp = next; // then re-assigns temp as the next person and repeats
	}
} // destructor

// insert method, inserts door client at the rear of the line
void dequeue::insert(int IDassigned, float questionTime) {
	person * newPerson = new person(IDassigned, questionTime); // creates a new person using given data

	// if no one is in line, places person as head and rear
	// otherwise, they are placed at rear with prev and next pointers being arranged accordingly
	if (head == NULL) {
		head = newPerson;
		rear = newPerson;
	}
	else if (rear != NULL) {
		rear->prev = newPerson;
		newPerson->next = rear;
		rear = newPerson;
	}
}

//insertCaller method, inserts a caller at the head of the line
void dequeue::insertCaller(int IDassigned, float questionTime) {
	person * newPerson = new person(IDassigned, questionTime); // creates a new person using given data

	// if no one is in line, places person as head and rear
	// otherwise, they are placed at head with next and prev pointers being arranged accordingly
	if (head == NULL) {
		head = newPerson;
		rear = newPerson;
	}
	else {
		head->next = newPerson;
		newPerson->prev = head;
		head = newPerson;
	}	
} 

//finished method, removes head of line when they are done
void dequeue::finished() {
	person * nextInLine = head->prev; // stores the person behind the head so they can be moved to head later

	// if only one person is in line, essentially makes line empty
	// otherwise, the next person in line becomes the head and pointers are arranged accordingly
	if (head == rear) {
		head = rear = NULL;
	}
	else {
		head->prev = NULL;
		nextInLine->next = NULL;
		head = nextInLine;
	}				
}

//isEmpty method, gives corresponding bool value depending on if line is empty
bool dequeue::isEmpty() {
	// if no one is in line, returns true
	// otherwise, someone is in line and returns false
	if (head == NULL && rear == NULL) {
		return true;
	}
	else {
		return false;
	}
}

//lineLength method, gets the length of the line
int dequeue::lineLength() {
	person * p = head; // a storage pointer that starts at head, used to progress through line
	int lineCount = 0; // keeps track of how many people are in line

	// condition if there is only one person in line
	// needed to be made as I use the rear as the sentinel for the while loop, doesn't count it if head and rear are the same person
	if (head == rear && head != NULL) {
        	lineCount = 1;
                return lineCount;
        }
	
	// increments lineCount by 1 each time, special case for if the previous person is the rear so they also get counted
	while (p != rear) {
		lineCount += 1;
		if (p->prev == rear) {
			lineCount += 1;
		}
		p = p->prev;
	}

	return lineCount;
}

//getIDofHead method, returns the ID of the head person
int dequeue::getIDofHead() {
	person * temp = head;
	int ID = temp->ID;
	return ID;
}

//headQuestionTime, returns the question time of the head person
float dequeue::headQuestionTime() {
	person * temp = head;
	float questionTime = temp->timeForQuestion;
	return questionTime;
}

//subtractFromQuestionTime, allows the question time of the head to be subtracted from outside the person class
void dequeue::subtractFromQuestionTime(float timeToSubtract) {
	head->subtractFromQuestionTime(timeToSubtract);
}	
