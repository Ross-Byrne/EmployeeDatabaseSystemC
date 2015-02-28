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
	initialiseFirstEmployee(employeeHead);

	// initialise first login user
	strncpy_s(loginHead->username, 25, "default", 25);

	// Initialise Variables
	endProgram = menuChoice = loginValid = i = 0;

	// loads the user login details into the program
	loadUsers(loginHead);

	while (endProgram != 99) // Login loop
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
	
			// handles user login - makes sure login is valid
			// returns 1 if valid, returns 0 is invalid
			loginValid = login(loginHead);

			if (loginValid == 1) // if valid
			{
				printf("\n. . . Moving to database . . .\n");
				menuChoice = 50; // means login was valid
				endProgram = 99; // to exit while
			} // if
			break;
		case 2: // exit
			endProgram = 99;
			break;
		} // switch
	} // while

	if (menuChoice == 50) // login was valid
	{
		endProgram = 0; // so main program loop isn't skipped
	} // if

	while (endProgram != 99) // main program loop
	{
		// To make sure the number input is in the right range
		do
		{
			printMainEmployeeMenu(); // prints the employee menu

			printf("\n\nEnter Option: ");

			fflush(stdin); // flush buffer
			scanf_s("%d", &menuChoice);

		} while (menuChoice < 1 || menuChoice > 7);

		switch (menuChoice)
		{
		case 1: // add employee
			printf("\nAdd Employee.\n");

			addEmployee(employeeHead);
			break;
		case 2: // display employee details
			printf("\nDisplay Employee Details.\n");
			break;
		case 3: // update employee
			printf("\nUpdate Employee.\n");
			break;
		case 4: // delete employee
			printf("\nDelete Employee.\n");
			break;
		case 5: // display employees by department
			printf("\nDisplay Employees by Department.\n");
			displayEmployees(employeeHead);
			break;
		case 6: // employee report
			printf("\nEmployee Report.\n");
			break;
		case 7: // exit
			printf("\n. . . Exiting . . .\n");
			endProgram = 99;
			break;
		} // switch
	} // while

	printf("\n\nProgram ended.\n\n");
	system("pause");
} // main()