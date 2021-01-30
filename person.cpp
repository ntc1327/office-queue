#include <iostream>
#include <iomanip>
#include "person.h"

// constructors and destructors
person::person(){
	ID = 0;
	timeForQuestion = 0;
	next = prev = NULL;
} // default constructor for dummy

person::person(int assignedID, float questionTime){
	ID = assignedID;
	timeForQuestion = questionTime;
	next = prev = NULL;
} // constructor given starting data for the person

person::~person(){

} // destructor

// getTimeForQuestion method
float person::getTimeForQuestion() {
	return timeForQuestion;
}

// getID method
int person::getID() {
	return ID;
}

// subtractFromQuestionTime method, subtracts from the question time given a time to subtract
void person::subtractFromQuestionTime(float timeToSubtract) {
	timeForQuestion -= timeToSubtract;
} 
