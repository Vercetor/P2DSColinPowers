/**********************************************************
AUTHOR: Colin Powers
DATE:9/17/2017
CLASS: Data Structures
INSTRUCTOR: Dr. Woodcock
DESCRIPTION: A linked list that uses recursion to step through the program to find the number the user is searching for. The linked list will be filled
wil 500 random numbers
*************************************************************/

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


// Node Structure************************************************
struct node {

	int data;		// variable
	node *next;		// node pointer

};// END of Structs**********************************************


// Functions*****************************************************
void searchRecursive(node* Ptr, int searchValue);
// END Functions*************************************************



//MAIN***********************************************************
int main()
{	

	srand(time(0));		// For the random number genenrator

	// structs to
	node *n = new node;
	node *head = n;
	node *t = n;

	n->data = 1;

	// Random number generator to fill linked list.
	for (int ix = 0; ix <= 500; ix++) {

		n = new node;

		int randNumber = rand() % 500 + 1;
		n->data = randNumber;
		t->next = n;
		t = n;
	}

	n->next = NULL;


	int input;

	// ask user for input
	cout << "Please enter a number, and this program will check if the number is in the list." << endl;
	cout << "Enter 0 to exit the program" << endl;
	cin >> input;

	searchRecursive(head, input);


	return 0;
}// END of Main***************************************************************************************************



//Function to use recursion to search*****************************************************************************
void searchRecursive(node* Ptr, int searchValue)
{
	if (searchValue != 0)
	{
		if (Ptr == NULL)	// If statement to check if number selected by user is/isnt in the list.
		{
			cout << searchValue << " was not found in the list" << endl << endl;	// not in the list.
		}
		else if (Ptr->data == searchValue)
		{
			cout << searchValue << " is in the list" << endl << endl; // value is in the list.
		}
		else
		{
			searchRecursive(Ptr->next, searchValue);	// function calling itself to keep searching for value.
		}
	}
	else {

		cout << "Thank you!";
	}


} // END of searchRecursive****************************************************************************************