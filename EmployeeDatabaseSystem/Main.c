// Ross Byrne 2015
// The main class file

#include "Functions.h"

void main()
{
	// Variables
	int endProgram, menuChoice, loginValid, i;

	// listed list of login users
	struct loginUsers *loginHead;
	loginHead = (struct loginUsers *)malloc(sizeof(struct loginUsers)); // allocates memory for head
	loginHead->next = NULL;

	// linked list of employees
	struct employeeList *employeeHead; // start of linked list
	employeeHead = (struct employeeList *)malloc(sizeof(struct employeeList)); // allocates memory for head;
	employeeHead->next = NULL; // no other node yet

	// initialise first employee
	employeeHead->employeeInfo.id = 1111;

	// initialise first login user
	strncpy_s(loginHead->username, 25, "default", 25);

	// Initialise Variables
	endProgram = menuChoice = loginValid = i = 0;

	loadUsers(loginHead);

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
	
			loginValid = login(loginHead);

			if (loginValid == 1) // if valid
			{
				printf("\nMove to database\n");
			} // if
			break;
		case 2: // exit
			endProgram = 99;
			break;
		} // switch
	} // while

	printf("\n\n\n");
	system("pause");
} // main()