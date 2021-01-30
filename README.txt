Author: Noah Cribelar
Date Completed: 1/30/19

PROGRAM SUMMARY

This program is intended to simulate a queue at an office where clients can either call in or walk in. If a client walks in, they are placed at the end of the queue; should a client call in, they will placed at the head of the queue and be dealt with immediately. A client will only leave the queue once their question has been dealt with.

The time needed to answer a question and the times the clients will walk or call in have been randomly generated using the rand() routine. However, each time the program is run should produce the exact same times due to the nature of rand(). Because I did not choose to include srand(), the seed for rand() will be the same each time the program is run. That is what causes the output to never change.


INVOKING THE PROGRAM

After downloading the zip file and using the unzip command in the MultiLab, the program can be run with the help of the makefile included within it.

To run the program, simply enter "make" into the command line and press enter to let make compile the program. After the program has been compiled, use "make run" to run the program. 

After "make run" has been used, the program will begin its execution. To progress from event to event within the program, simply hit enter each time. The program will progress until it has reached its end, which is after 10 simulated seconds. An end of simulation notice will appear so the user can review the program output, and to fully end the program, hit enter once more.

There is also a "make clean" command included to remove the object files after the program has executed. If you want to run the program after using "make", DO NOT run "make clean" before using "make run". That will destroy the object files that were made and the program will not execute. Should you use "make clean" and want to still run the program, simply run "make" again to compile and restore the object files.


PROGRAM INPUT

There is no input necessary to run this program unless using enter to advance the program counts as input.


PROGRAM OUTPUT

Output will come in one of three forms.

The first is the program title, seen at the beginning when it is run.

The second form is the notice at the end saying the program is finished.

The third form is the running log output whenever one of three events happens: a client calling, a client walking in, and a client getting their question answered. This running log will detail the client the event happened to, the current time in the simulation, and the length of the line at the time.

A sample of this output can be found in the output.txt file included with this program.


ADDITIONAL NOTES

The idea to seperate the processes in my while loop into whether the line was empty or not was born from a conversation with fellow classmate Jackson Danna. We were discussing how to avoid recursion within the assignment seeing as we had both encountered issues in constructing the while loop that would have caused a multitude of either phone or door clients to keep coming in without resetting the loop. Should our implementations of the while loop look similar, that is the reason why. If you have any further questions or notice other incidental similarities, I would be happy to discuss them and I'm assuming Jack would be as well.
