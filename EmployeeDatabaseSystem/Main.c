// Ross Byrne 2015
// The main class file

#include "Functions.h"

void main()
{
	// Variables
	int endProgram = 0, menuChoice = 0;

	// linked list of employees
	struct employeeList *head; // start of linked list
	head = (struct employeeList *)malloc(sizeof(struct employeeList)); // allocates memory for head;
	head->next = NULL; // no other node yet

	// initialise first employee
	head->employeeInfo.id = 1111;

	while (endProgram != 99) // main program loop
	{
		// To make sure the number input is in the right range
		do
		{
			printMainMenu(); // prints the main menu

			printf("\n\nEnter Option: ");

			fflush(stdin); // flush buffer
			scanf_s("%d", &menuChoice);

		} while (menuChoice < 1 || menuChoice > 2);

		switch (menuChoice)
		{
		case 1: // login
			//displayEmployees(head);
			addEmployee(head);
			displayEmployees(head);

			break;
		case 2: // exit
			endProgram = 99;
			break;
		} // switch
	} // while

	printf("\n\n\n");
	system("pause");
} // main()