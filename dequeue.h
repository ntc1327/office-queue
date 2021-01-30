#pragma once
//----------------------------------
// 	    dequeue class
//----------------------------------
// A dequeue implemented using a
// linked list to represent the line
// at the office.
//----------------------------------
#include "person.h"

class dequeue {
public:
	dequeue();
	~dequeue();
	void insert(int IDassigned, float questionTime);
	void insertCaller(int IDassigned, float questionTime);
	void finished();
	bool isEmpty();
	int lineLength();
	int getIDofHead();
	float headQuestionTime();
	void subtractFromQuestionTime(float timeToSubtract);
private:
	person * head;
	person * rear;
};
