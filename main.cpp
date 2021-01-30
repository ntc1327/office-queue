#include <iostream>
#include <cstdlib>
#include <time.h>
#include "dequeue.h"
#include "person.h"
using namespace std;

dequeue line; // line object, is the linked list structure in form of a dequeue

float const Q = 1.0; //seconds to answer
float const D = 2.0; //someone comes in the door
float const P = 2.0; //someone phones in

int clientCount = 0; // keeps track of clients who have entered and also serves as basis for ID

float currentTime = 0; // simulates a clock, advances in time when events happen
float nextClientEnter, nextClientCall, clientFinish, timeForQuestion;

// produces random values from Q, D and P, helps make main look cleaner
float randomValue(float x) {
        float theValue = (x * ((float) rand())/RAND_MAX);
        return theValue;
}

// process for when a client will come in the door next
void doorClientProcess() {
	timeForQuestion = randomValue(Q); // computes time to answer question
        currentTime += nextClientEnter; // moves clock to when client enters
        clientCount += 1; // increments when a client comes in
        line.insert(clientCount, timeForQuestion); // puts client in line
	
	// log that shows the updates to the line for this event
	cout << "Client " << clientCount << " has walked in." << endl;
        cout << "The time is " << currentTime << " seconds." << endl;
        cout << "The line length is now " << line.lineLength() << "." << endl;
}

// process for when a client will call next
void callProcess() {
	timeForQuestion = randomValue(Q); // computes time to answer question
        currentTime += nextClientCall; // moves clock to when client calls
        clientCount += 1; // increments for phone caller
        line.insertCaller(clientCount, timeForQuestion); // puts caller at front of line

	// log that shows the updates to the line for this event
	cout << "Client " << clientCount << " has called." << endl;
        cout << "The time is " << currentTime << " seconds." << endl;
        cout << "The line length is now " << line.lineLength() << "." << endl;
}

// process for when a question will be answered next
void answeredQuestionProcess() {
	int answeredClient = line.getIDofHead(); // gets the ID of the client who just finished
        currentTime += clientFinish; // update to the time it took to answer the question
        line.finished(); // removes client from front of line and "advances" the next client

	// log that shows the updates to the line for this event
        cout << "Client " << answeredClient << " had their question answered." << endl;
        cout << "The time is " << currentTime << " seconds." << endl;
        cout << "The line length is now " << line.lineLength() << "." << endl;
}

int main() {
cout << "The Secretary Simulator" << endl << endl;

// main loop of program, will begin another loop anytime one of the processes finishes
while (currentTime < 10) {
	nextClientEnter = randomValue(D); //computes time when next door arrival will be
	nextClientCall = randomValue(P); // computes time when next phone call happens

	// seperates processes by seeing if there is a line already in the office
	// first statement is for empty line, second is for existing line
	if (line.isEmpty() == true) {
		if (nextClientEnter < nextClientCall) { // if door arrival is first, runs the door process
			doorClientProcess();
		}
		else if (nextClientCall <= nextClientEnter) { // if someone calls first, runs call process
			callProcess();
		}		
	}
	else if(line.isEmpty() == false) {
		clientFinish = line.headQuestionTime(); // gets the question time of the first client in line for use in comparisons

		if (clientFinish < nextClientEnter && clientFinish < nextClientCall) { // if question time will happen first, answers the client's question
			answeredQuestionProcess();
		}
		else if (nextClientEnter < clientFinish && nextClientEnter < nextClientCall) { // if door arrival is first, runs tweaked door process
			/* block of code below is a tweaked doorClientProcess() that subtracts
			   the time needed for the client to walk in from the current question time */
			currentTime += nextClientEnter;
			line.subtractFromQuestionTime(nextClientEnter); // subtracts the time
			clientFinish = line.headQuestionTime(); // updates clientFinish only for consistency
			timeForQuestion = randomValue(Q);
			clientCount += 1;
			line.insert(clientCount, timeForQuestion);

			cout << "Client " << clientCount << " has walked in." << endl;
                        cout << "The time is " << currentTime << " seconds." << endl;
                        cout << "The line length is now " << line.lineLength() << "." << endl;
		}
		else if (nextClientCall <= clientFinish && nextClientCall <= nextClientEnter) { // if someone calls first, runs tweaked call process
			/* block of code below is a tweaked callProcess that subtracts the time
			   needed for the client to call from the current question time         */
			currentTime += nextClientCall;
			line.subtractFromQuestionTime(nextClientCall); // subtracts the time
			clientFinish = line.headQuestionTime(); // updates clientFinish only for consistency
			timeForQuestion = randomValue(Q);
			clientCount += 1;
			line.insertCaller(clientCount, timeForQuestion);

			cout << "Client " << clientCount << " has called." << endl;
                        cout << "The time is " << currentTime << " seconds." << endl;
                        cout << "The line length is now " << line.lineLength() << "." << endl;
		}
	}
cin.get(); // essentially pauses program so log can be read, advances when enter is pressed
}
cout << "End of simulation." << endl;
cin.get(); // pauses program again so it can be reviewed
return 0;
}
