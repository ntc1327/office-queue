#pragma once
using namespace std;
//-----------------------------------
//           Person class
//-----------------------------------
// Describes a person waiting in line
// Acts as a node for the linked list
//-----------------------------------

class person {
	friend class dequeue;
public: 
	person();
	person(int IDassigned, float questionTime);
	~person();
	float getTimeForQuestion();
	int getID();
	void subtractFromQuestionTime(float timeToSubtract);
private:
	int ID;
	float timeForQuestion;
	person * next;
	person * prev;
};
