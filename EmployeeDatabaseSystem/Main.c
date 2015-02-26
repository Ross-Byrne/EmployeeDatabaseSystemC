// Ross Byrne 2015
// The main class file

#include "Functions.h"

void main()
{
	// Variables
	int endProgram = 0, menuChoice = 0, loginValid = 0;
	char username[25] = "user", password[25] = "pass";

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
			
			printf("\nEnter Your Login Details.\n");
			printf("\nEnter Your Username: ");
			fflush(stdin);
			fgets(username, 24, stdin);
			printf("\nEnter Your Password: ");
			fflush(stdin);
			fgets(password, 24, stdin);

			// checks for '\n' newline char that gets added to end of string with fgets
			// and then removes it
			if (username[strlen(username) - 1] == '\n') 
			{
				username[strlen(username) - 1] = '\0';
			} // if
			if (password[strlen(password) - 1] == '\n')
			{
				password[strlen(password) - 1] = '\0';
			} // if

			loginValid = login(username, password);

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