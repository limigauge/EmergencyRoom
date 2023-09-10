/*
 * NAME             : MICHELLE LI
 * STUDENT NUMBER   : 7866927
 * COURSE           : COMP 2150
 * INSTRUCTOR       : ALI NESHATI
 * ASSIGNMENT       : 2
 * QUESTION         : 1
 *
 * REMARKS: This program utilizes linked lists (stacks, queues, priority queues) to create a simulation of a restaurant. Keeping track of
 * times, it prints out messages of when set events, such as customer arrivals, food preparation, and serving food, happen when
 * only one chef is in the kitchen. It also keeps track of the number of orders and total revenue made by the input orders.
 * There are three versions: first come first serve, last come first serve, and price priority simulations.
 *
 * The input file parsing code is sourced from the assignment file reading example from UMLearn with some changes.
 */

#include <string>
#include <iostream>
using namespace std;

#include "ParseFile.h"

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		cout<<"USAGE: filename simulationType"<<endl;
		cout<<"where simulationType is either 1, 2 or 3."<<endl;
		return 0;
	}

	string fileName = argv[1];
	string version = argv[2];
	
	cout << "The filename is: " << fileName << endl;
	cout << "The version selected is: " << version <<endl;

    ParseFile* readFile = new ParseFile(fileName, version);

    readFile->read(); // read file

    free(readFile); //free allocated ParseFile

    cout << "End of Processing.\n" << endl;
}
