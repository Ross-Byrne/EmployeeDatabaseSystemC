// Ross Byrne 2015

#include "Functions.h"

// All of the functions are here

// main menu for program
void printMainMenu()
{
	printf("\nWelcome To The Employee Database.\n");
	printf("\n1.) Login To Employee Database.");
	printf("\n2.) Exit.");
} // printMainMenu()

// main menu for the Database
void printMainEmployeeMenu()
{
	printf("\nEmployee Database\n");
	printf("\n1.) Add Employee.");
	printf("\n2.) Display Employee Details.");
	printf("\n3.) Update Employee.");
	printf("\n4.) Delete Employee.");
	printf("\n5.) Display All Employees By Department.");
	printf("\n6.) Employee Report.");
	printf("\n7.) Exit.\n");
} // printMainEmployeeMenu()

// gets rid of '\n' newline char at end of string after using fgets()
void cleanString(char *temp)
{
	// checks for '\n' newline char that gets added to end of string with fgets()
	// and then removes it
	if (temp[strlen(temp) - 1] == '\n')
	{
		temp[strlen(temp) - 1] = '\0';
	} // if
} // cleanString()

// replaces space char with underscore char to make
// reading from text file easier
// enter 1 to replace spaces and 0 to replace underscores
void editString(char *temp, int num)
{
	int i = 0;

	if (num == 1)
	{
		// checks for space char and replaces with '_' underscore char
		for (i = 0; i < strlen(temp) - 1; i++)
		{
			if (temp[i] == ' ')
			{
				temp[i] = '_';
			} // if
		} // for
	}
	else
	{
		// checks for underscore char and replaces with ' ' space char
		for (i = 0; i < strlen(temp) - 1; i++)
		{
			if (temp[i] == '_')
			{
				temp[i] = ' ';
			} // if
		} // for
	}
} // editString()

// adds values for first employee to initialise the linked list
void initialiseFirstEmployee(struct employeeList *temp)
{
	temp->employeeInfo.id = 1111;
	strncpy_s(temp->employeeInfo.name, 25, "Mike Sullivan", 25);
	strncpy_s(temp->employeeInfo.address, 45, "Galway, Ireland", 45);
	strncpy_s(temp->employeeInfo.department, 25, "Sales & Marketing", 25);
	temp->employeeInfo.dateJoined.day = 25;
	temp->employeeInfo.dateJoined.month = 03;
	temp->employeeInfo.dateJoined.year = 2000;
	temp->employeeInfo.annualSalary = 38000.00;
	strncpy_s(temp->employeeInfo.email, 35, "mike.sullivan@gmail.com", 35);
} // initialiseFirstEmployee()

void addEmployee(struct employeeList **employeeHeadPtr, struct employeeList *employeeHead)
{
	char tempChar[45];
	int tempInt = 0, firstEmployee = 0; // 1 = first employee in list, 0 = not first
	float tempFloat = 0.0;

	// make a temp node
	struct employeeList *temp;
	struct employeeList *oldTemp;

	temp = (struct employeeList*)malloc(sizeof(struct employeeList));
	oldTemp = (struct employeeList*)malloc(sizeof(struct employeeList));

	oldTemp = NULL;
	temp = employeeHead; // make it point at start of linked list
	
	if (employeeHead == NULL) // if list is empty
	{
		// flag employee as being first in list
		firstEmployee = 1;
	}
	else // if list isn't empty
	{
		// flag employee as not being first in empty list
		firstEmployee = 0;
	} // if

	// make the new employee & allocate memory for it
	struct employeeList *newEmployee;
	newEmployee = (struct employeeList*)malloc(sizeof(struct employeeList));

	// enter data
	printf("\nEnter New Employee's Details.\n");

	printf("\nEnter ID (Must Be Unique Number): ");
	fflush(stdin);
	scanf("%d", &tempInt);
	newEmployee->employeeInfo.id = tempInt;

	printf("\nEnter Name: ");
	fflush(stdin);
	fgets(tempChar, 25, stdin);
	cleanString(tempChar);
	strncpy_s(newEmployee->employeeInfo.name, 25, tempChar, 25);

	printf("\nEnter Address: ");
	fflush(stdin);
	fgets(tempChar, 45, stdin);
	cleanString(tempChar);
	strncpy_s(newEmployee->employeeInfo.address, 45, tempChar, 45);

	printf("\nEnter Department: ");
	fflush(stdin);
	fgets(tempChar, 25, stdin);
	cleanString(tempChar);
	strncpy_s(newEmployee->employeeInfo.department, 25, tempChar, 25);

	printf("\nEnter Date Joined\n");
	printf("\nEnter Year (eg 1999): ");
	fflush(stdin);
	scanf("%d", &tempInt);
	newEmployee->employeeInfo.dateJoined.year = tempInt;

	printf("Enter Month (eg 03): ");
	fflush(stdin);
	scanf("%d", &tempInt);
	newEmployee->employeeInfo.dateJoined.month = tempInt;

	printf("Enter Day (eg 28): ");
	fflush(stdin);
	scanf("%d", &tempInt);
	newEmployee->employeeInfo.dateJoined.day = tempInt;
	
	printf("\nEnter Annual Salary: ");
	fflush(stdin);
	scanf("%f", &tempFloat);
	newEmployee->employeeInfo.annualSalary = tempFloat;

	printf("\nEnter E-mail Address: ");
	fflush(stdin);
	fgets(tempChar, 35, stdin);
	cleanString(tempChar);
	strncpy_s(newEmployee->employeeInfo.email, 35, tempChar, 35);

	printf("\nEmployee Added.\n");
	printEmployeeDetails(newEmployee);

	if (firstEmployee == 1) // if employee is first in empty list
	{
		// make the new employee the head
		newEmployee->next = NULL; // new employee doesn't point to anything
		*employeeHeadPtr = newEmployee; // makes this employee the start of linked list
	}
	else // if firstEmployee == 0 - is't first
	{
		// adds employees into list in ascending order by id
		// checks for employee id bigger then one entered
		// and adds employee into list before it - keeping list ordered
		while (temp->next != NULL)
		{
			// if temp is head
			if (temp->employeeInfo.id > newEmployee->employeeInfo.id && oldTemp == NULL)
			{
				*employeeHeadPtr = newEmployee;
				newEmployee->next = temp;
				return;
			} // if

			// if temp is not head
			if (temp->employeeInfo.id > newEmployee->employeeInfo.id && oldTemp != NULL)
			{
				oldTemp->next = newEmployee;
				newEmployee->next = temp;
				return;
			} // if

			oldTemp = temp;
			temp = temp->next;
		} // while

		// Adding newEmployee before last item in linked list
		if (temp->employeeInfo.id > newEmployee->employeeInfo.id)
		{
			oldTemp->next = newEmployee;
			newEmployee->next = temp;
			return;
		}
		else // if last item isn't bigger, just add to end of linked list
		{
			newEmployee->next = NULL; // new employee doesn't point to anything
			temp->next = newEmployee; // adds new employee to end of linked list
		} // if	
	} // if
} // addEmployee()

// finds an employee based on employee ID or name
void displayEmployeeDetails(struct employeeList *employeeHead)
{
	int employeeId = 0, menuChoice = 0;
	char employeeName[25] = "name";

	struct employeeList *temp;
	temp = (struct employeeList*)malloc(sizeof(struct employeeList));
	temp = employeeHead;

	switch (searchEmployeeByIdOrName())
	{
	case 1: // search by id
		printf("\nEnter Employee's ID: ");
		fflush(stdin);
		scanf("%d", &employeeId);
		break;
	case 2: // search by name
		printf("\nEnter Employee's Name: ");
		fflush(stdin);
		fgets(employeeName, 25, stdin);
		cleanString(employeeName);
		break;
	case 3: // exit
		return;
	} // switch

	while (temp != NULL)
	{
		if (temp->employeeInfo.id == employeeId || strncmp(temp->employeeInfo.name, employeeName, 25) == 0)
		{
			printf("\nEmployee Found.\n");
			printEmployeeDetails(temp);
			return;
		} // if

		temp = temp->next;
	} // while

	printf("\nEmployee Not Found!\n");
} // displayEmployeeDetails()

void updateEmployeeDetails(struct employeeList *employeeHead)
{
	int employeeId = 0, menuChoice = 0;
	char employeeName[25] = "name";
	char tempChar[45] = "temp";
	float tempFloat = 0.0;

	struct employeeList *temp;
	temp = (struct employeeList*)malloc(sizeof(struct employeeList));
	temp = employeeHead;

	switch (searchEmployeeByIdOrName())
	{
	case 1: // search by id
		printf("\nEnter Employee's ID: ");
		fflush(stdin);
		scanf("%d", &employeeId);
		break;
	case 2: // search by name
		printf("\nEnter Employee's Name: ");
		fflush(stdin);
		fgets(employeeName, 25, stdin);
		cleanString(employeeName);
		break;
	case 3: // exit
		return;
	} // switch

	while (temp != NULL)
	{
		menuChoice = 0;

		// if either employee id or name is equal
		if (temp->employeeInfo.id == employeeId || strncmp(temp->employeeInfo.name, employeeName, 25) == 0)
		{
			printf("\nEmployee Found.\n");
			printEmployeeDetails(temp);

			do{
				printf("\nWhich Details Would You Like To Update?\n");
				printf("\n1.) Employee's Address.");
				printf("\n2.) Employee's Department.");
				printf("\n3.) Annual Salary.");
				printf("\n4.) Exit\n");

				printf("\nEnter Option: ");
				fflush(stdin);
				scanf("%d", &menuChoice);

			} while (menuChoice < 1 || menuChoice > 4);

			switch (menuChoice)
			{
			case 1: // change address
				printf("\nUpdate Address\n");
				printf("\nEmployee's Current Address Is: %s.\n", temp->employeeInfo.address);

				printf("\nEnter Employee's New Address: ");
				fflush(stdin);
				fgets(tempChar, 45, stdin);
				cleanString(tempChar);

				strncpy_s(temp->employeeInfo.address, 45, tempChar, 45);
				printf("\nEmployee's Address Updated.\n");
				printEmployeeDetails(temp);
				break;
			case 2: // change department
				printf("\nUpdate Department\n");
				printf("\nEmployee's Current Department Is: %s.\n", temp->employeeInfo.department);

				printf("\nEnter Employee's New Department: ");
				fflush(stdin);
				fgets(tempChar, 25, stdin);
				cleanString(tempChar);

				strncpy_s(temp->employeeInfo.department, 25, tempChar, 25);
				printf("\nEmployee's Department Updated.\n");
				printEmployeeDetails(temp);
				break;
			case 3: // change annual salary
				printf("\nUpdate Annual Salary\n");
				printf("\nEmployee's Current Annual Salary Is: %.2f.\n", temp->employeeInfo.annualSalary);

				printf("\nEnter Employee's New Annual Salary: ");
				fflush(stdin);
				scanf("%f", &temp->employeeInfo.annualSalary);

				printf("\nEmployee's Annual Salary Updated.\n");
				printEmployeeDetails(temp);
				break;
			case 4: // exit
				return;
				break;
			} // switch

			return;
		} // if

		temp = temp->next;
	} // while

	printf("\nEmployee Not Found!\n");
} // updateEmployeeDetails()

// search for the employee by their id num or name and then delete them
void deleteEmployee(struct employeeList **employeeHeadPtr, struct employeeList *employeeHead)
{
	if (employeeHead == NULL) // if linked list of employees is empty
	{
		printf("\nCannot Delete Employee. No Employees in List!\n");
	}
	else // if it isn't empty
	{
		int employeeId = 0, menuChoice = 0;
		char employeeName[25] = "name";

		struct employeeList *temp;
		struct employeeList *oldTemp;

		temp = (struct employeeList*)malloc(sizeof(struct employeeList));
		oldTemp = (struct employeeList*)malloc(sizeof(struct employeeList));

		oldTemp = NULL; // doesn't point at anything yet
		temp = employeeHead; // point temp at start of linked list

		switch (searchEmployeeByIdOrName())
		{
		case 1: // search by id
			printf("\nEnter Employee's ID: ");
			fflush(stdin);
			scanf("%d", &employeeId);
			break;
		case 2: // search by name
			printf("\nEnter Employee's Name: ");
			fflush(stdin);
			fgets(employeeName, 25, stdin);
			cleanString(employeeName);
			break;
		case 3: // exit
			return;
		} // switch

		// if it's the first item
		if ((temp->employeeInfo.id == employeeId || strncmp(temp->employeeInfo.name, employeeName, 25) == 0) && oldTemp == NULL)
		{
			// code to confirm if you want to delete the employee
			// returns 1 if yes - 0 if no
			if (confirmEmployeeDelete(temp) == 1) // if yes
			{
				// point temp at the start of the list
				temp = *employeeHeadPtr;

				// point the start of the list pointer to the next item in the list
				// because that will now be the start of the list
				*employeeHeadPtr = temp->next;
				free(temp);

				printf("\nEmployee Deleted.\n");
				return;
			}
			else // if no
			{
				printf("\nEmployee Not Deleted.\n");
				return;
			} // if
		} // if

		// goes to the last employee
		// while keeping track of the second last employee
		while (temp->next != NULL)
		{
			// if not the first or last employee in list
			if ((temp->employeeInfo.id == employeeId || strncmp(temp->employeeInfo.name, employeeName, 25) == 0) && oldTemp != NULL)
			{
				// code to confirm if you want to delete the employee
				// returns 1 if yes - 0 if no
				if (confirmEmployeeDelete(temp) == 1) // if yes
				{
					// point employee that is before the employee being deleted
					// to the employee after it, keeping the linked list linked
					oldTemp->next = temp->next;
					free(temp);

					printf("\nEmployee Deleted.\n");
					return;
				}
				else // if no
				{
					printf("\nEmployee Not Deleted.\n");
					return;
				} // if
			} // if

			// moving to next item in list
			oldTemp = temp; // the current item is now oldTemp
			temp = temp->next; // the next item in list is now the current item
		} // while

		// if last employee in list
		if ((temp->employeeInfo.id == employeeId || strncmp(temp->employeeInfo.name, employeeName, 25) == 0) && temp->next == NULL)
		{
			// code to confirm if you want to delete the employee
			// returns 1 if yes - 0 if no
			if (confirmEmployeeDelete(temp) == 1) // if yes
			{
				// tell the item before current item not to point to anything
				oldTemp->next = NULL; 
				free(temp); // delete employee

				printf("\nEmployee Deleted.\n");
				return;
			}
			else // if no
			{
				printf("\nEmployee Not Deleted.\n");
				return;
			} // if
		} // if

		printf("\nEmployee Not Found!\n");
	} // if
} // deleteEmployee()

int confirmEmployeeDelete(struct employeeList *temp)
{
	int menuChoice = 0;

	printf("\nEmployee Found.\n");
	printEmployeeDetails(temp);
	printf("\nAre You Sure You Want To Delete This Employee?\n");

	printf("\n1.) Yes.");
	printf("\n2.) No.\n");

	do{
		printf("\nEnter Option: ");

		scanf("%d", &menuChoice);
	} while (menuChoice < 1 || menuChoice > 2);

	return menuChoice;
} // confirmEmployeeDelete()

// code to decide whether to search for employee
// by ID number or name. Returns 1 for id, 2 for name and 3 for exit
int searchEmployeeByIdOrName()
{
	int menuChoice = 0;

	do{
		printf("\nHow Would You Like To Search For The Employee?\n");
		printf("\n1.) Search By ID.");
		printf("\n2.) Search By Name.");
		printf("\n3.) Exit.\n");

		printf("\nEnter Option: ");
		fflush(stdin);
		scanf("%d", &menuChoice);

	} while (menuChoice < 1 || menuChoice > 3);

	return menuChoice;
} // searchEmployeeByIdOrName()

// the code that prints the employee's details
// just pass in the pointer that is pointing to 
// a particular employee structure in the linked list
void printEmployeeDetails(struct employeeList *temp)
{
	// display employee details
	printf("\nID: %d.", temp->employeeInfo.id);
	printf("\nName: %s.", temp->employeeInfo.name);
	printf("\nAddress: %s.", temp->employeeInfo.address);
	printf("\nDepartment: %s.", temp->employeeInfo.department);
	printf("\nDate Joined: %d/%d/%d.", temp->employeeInfo.dateJoined.day,
		temp->employeeInfo.dateJoined.month,
		temp->employeeInfo.dateJoined.year);
	printf("\nAnnual Salary: $%.2f.", temp->employeeInfo.annualSalary);
	printf("\nE-mail: %s.\n", temp->employeeInfo.email);
} // printEmployeeDetails()

// displays all of the employees in list by department
void displayAllEmployees(struct employeeList *employeeHead)
{
	int employeeCount, i, j, exists;
	struct employeeList *temp;
	char tempString1[25], tempString2[25];
	temp = (struct employeeList*)malloc(sizeof(struct employeeList));
	temp = employeeHead; // points temp at start of linked list

	// count the num of employees
	employeeCount = 0;
	while (temp != NULL)
	{
		employeeCount++;
		// move to next employee in list
		temp = temp->next;
	} // while

	// array of pointers, pointing to employees in linkedlist
	struct employeeList **orderedEmpArr = malloc(employeeCount * sizeof(struct employeeList *));
	struct employeeList **orderedEmpTemp = malloc(sizeof(struct employeeList *));

	i = 0;
	do {
		// reset temp to start of linked list
		temp = employeeHead;
		strncpy(tempString1, "zzzzzzzzzzzzzzzzzzzzzzzzz", 25);

		while (temp != NULL)
		{
			exists = 0;
			// check if current employee is in array
			for (j = 0; j < employeeCount; j++){
				if (temp == orderedEmpArr[j]){
					exists = 1;
					break;
				} // if
			} // for

			// if current emp isnt in array, continue
			if (exists == 0){
				strncpy(tempString2, temp->employeeInfo.department, 25);
				_strlwr(tempString2);

				if (strncmp(tempString1, tempString2, 25) > 0){
					orderedEmpTemp = temp;
					strncpy(tempString1, tempString2, 25);
				} // if
			} // if
	
			// move to next employee in list
			temp = temp->next;
		} // while
		
		// add pointer to array of pointers
		orderedEmpArr[i] = orderedEmpTemp;
		i++;
	} while (i != employeeCount);

	// print employees based on department
	for (i = 0; i < employeeCount; i++){
		printEmployeeDetails(orderedEmpArr[i]);
	} // for

	free(orderedEmpArr);
} // displayAllEmployees()

void employeeReport(struct employeeList *employeeHead)
{
	int employeeCount, i, j;
	struct employeeList *temp;
	char tempString1[25], tempString2[25];
	temp = (struct employeeList*)malloc(sizeof(struct employeeList));
	temp = employeeHead; // points temp at start of linked list

	// count the num of employees
	employeeCount = 0;
	while (temp != NULL)
	{
		employeeCount++;
		// move to next employee in list
		temp = temp->next;
	} // while

	// array of pointers, pointing to employees in linkedlist
	struct employeeList **orderedEmpArr = malloc(employeeCount * sizeof(struct employeeList *));
	struct employeeList **orderedEmpTemp = malloc(sizeof(struct employeeList *));

	i = 0;
	do {
		// reset temp to start of linked list
		temp = employeeHead;
		strncpy(tempString1, "zzzzzzzzzzzzzzzzzzzzzzzzz", 25);

		while (temp != NULL)
		{
			exists = 0;
			// check if current employee is in array
			for (j = 0; j < employeeCount; j++){
				if (temp == orderedEmpArr[j]){
					exists = 1;
					break;
				} // if
			} // for

			// if current emp isnt in array, continue
			if (exists == 0){
				strncpy(tempString2, temp->employeeInfo.department, 25);
				_strlwr(tempString2);

				if (strncmp(tempString1, tempString2, 25) > 0){
					orderedEmpTemp = temp;
					strncpy(tempString1, tempString2, 25);
				} // if
			} // if

			// move to next employee in list
			temp = temp->next;
		} // while

		// add pointer to array of pointers
		orderedEmpArr[i] = orderedEmpTemp;
		i++;
	} while (i != employeeCount);

	// print employees based on department
	for (i = 0; i < employeeCount; i++){
		printEmployeeDetails(orderedEmpArr[i]);
	} // for

	free(orderedEmpArr);
} // employeeReport()

// to handle users logining in
// returns 1 if details are correct, 0 if uncorrect
int login(struct loginUsers *loginHead)
{
	char user[25] = "user", pass[25] = "pass";
	struct loginUsers *temp;
	temp = (struct loginUsers*)malloc(sizeof(struct loginUsers));
	temp = loginHead;

	printf("\nEnter Your Login Details.\n");
	printf("\nEnter Your Username: ");
	fflush(stdin);
	fgets(user, 25, stdin);
	cleanString(user);

	printf("Enter Your Password: ");
	fflush(stdin);
	fgets(pass, 25, stdin);
	cleanString(pass);

	while (temp != NULL)
	{
		if (strncmp(temp->username, user, 25) == 0 && strncmp(temp->password, pass, 25) == 0) // if they are equal
		{
			printf("\nLogin Successful!\n"); // valid login
			return 1;
		} // if

		temp = temp->next;
	} // while

	printf("\nLogin Unsuccessful!\n"); // invalid login
	return 0;
} // login()

// adds a login user to the login user linked list
void addLoginUser(struct loginUsers *loginHead, char user[25], char pass[25])
{
	// make a temp node
	struct loginUsers *temp;
	temp = (struct loginUsers*)malloc(sizeof(struct loginUsers));
	temp = loginHead; // make it point at start of linked list

	// if first login user is default, override it 
	if (strncmp(temp->username, "default", 25) == 0)
	{
		// overrides default
		strncpy_s(temp->username, 25, user, 25);
		strncpy_s(temp->password, 25, pass, 25);
	}
	else
	{
		// go to the last item in list
		while (temp->next != NULL)
		{
			temp = temp->next;
		} // while

		// make the new user & allocate memory for it
		struct loginUsers *newUser;
		newUser = (struct loginUsers*)malloc(sizeof(struct loginUsers));

		// adds user details
		strncpy_s(newUser->username, 25, user, 25);
		strncpy_s(newUser->password, 25, pass, 25);

		newUser->next = NULL; // new user doesn't point to anything
		temp->next = newUser; // adds new user to end of linked list
	} // if
} // addLoginUser()

// displays all of the users in list
void displayUsers(struct loginUsers *loginHead)
{
	struct loginUsers *temp;
	temp = (struct loginUsers*)malloc(sizeof(struct loginUsers));
	temp = loginHead;

	while (temp != NULL)
	{
		printf("\nUser Name: %s Pass: %s\n", temp->username, temp->password); // show data
		temp = temp->next;
	} // while
} // displayUsers()

// reads usernames and passwords of login users from a file
void loadUsers(struct loginUsers *loginHead)
{
	/*// for testing
	printf("\nStarting to load users...\n");*/

	FILE *fPtr = NULL;
	int i = 0;
	char user[25] = "EOF", pass[25] = "pass";

	fPtr = fopen(USER_LOGIN, READMODE);
	if (fPtr == NULL)
	{
		printf("\n\nCould Not open file '%s'.\n", USER_LOGIN);
	}
	else
	{
		// save values from text file to variables
		// initial read
		fscanf(fPtr, "%s", user);

		// keeps reading until end of file
		while (strncmp(user, "EOF", 25) != 0) 
		{
			fscanf(fPtr, "%s", pass);

			// adds a login user to linked list
			addLoginUser(loginHead, user, pass);

			fscanf(fPtr, "%s", user);
		} // while
		
		//then close the file
		fclose(fPtr);

		/*// for testing
		printf("\nUser login details loaded correctly!\n");
		displayUsers(loginHead);*/
	} // if
} // loadUsers()

// loads employees from file and into employee linked list
void loadEmployees(struct employeeList *loginHead)
{
	// EOF marker is 0
	FILE *fPtr = NULL;
	int i = 0;

	// make a temp node
	struct employeeList *temp;
	temp = (struct employeeList*)malloc(sizeof(struct employeeList));
	temp = loginHead; // make it point at start of linked list

	fPtr = fopen(EMPLOYEE_DATA, READMODE);
	if (fPtr == NULL)
	{
		printf("\n\nCould Not open file '%s'.\n", EMPLOYEE_DATA);
	}
	else
	{
		// save values from text file to variables
		// initial read
		fscanf(fPtr, "%d", &i);

		// keeps reading until end of file
		while (i != 0)
		{
			// if first employee is default, override it 
			if (strncmp(temp->employeeInfo.name, "default", 25) == 0)
			{
				// overrides default
				temp->employeeInfo.id = i;
				fscanf(fPtr, "%s", temp->employeeInfo.name);
				fscanf(fPtr, "%s", temp->employeeInfo.address);
				fscanf(fPtr, "%s", temp->employeeInfo.department);
				fscanf(fPtr, "%d %d %d", &temp->employeeInfo.dateJoined.day,
					&temp->employeeInfo.dateJoined.month,
					&temp->employeeInfo.dateJoined.year);
				fscanf(fPtr, "%f", &temp->employeeInfo.annualSalary);
				fscanf(fPtr, "%s", temp->employeeInfo.email);

				// make the strings look nice again :P
				editString(temp->employeeInfo.name, 0); // 0 to replace underscores
				editString(temp->employeeInfo.address, 0);
				editString(temp->employeeInfo.department, 0);
			}
			else // add to end of list
			{
				// go to the last item in list
				while (temp->next != NULL)
				{
					temp = temp->next;
				} // while

				// make the new user & allocate memory for it
				struct employeeList *newUser;
				newUser = (struct employeeList*)malloc(sizeof(struct employeeList));

				// adds employee details
				newUser->employeeInfo.id = i;
				fscanf(fPtr, "%s", newUser->employeeInfo.name);
				fscanf(fPtr, "%s", newUser->employeeInfo.address);
				fscanf(fPtr, "%s", newUser->employeeInfo.department);
				fscanf(fPtr, "%d %d %d", &newUser->employeeInfo.dateJoined.day,
					&newUser->employeeInfo.dateJoined.month,
					&newUser->employeeInfo.dateJoined.year);
				fscanf(fPtr, "%f", &newUser->employeeInfo.annualSalary);
				fscanf(fPtr, "%s", newUser->employeeInfo.email);

				newUser->next = NULL; // new employee doesn't point to anything
				temp->next = newUser; // adds new employee to end of linked list

				// make the strings look nice again :P
				editString(newUser->employeeInfo.name, 0); // 0 to replace underscores
				editString(newUser->employeeInfo.address, 0);
				editString(newUser->employeeInfo.department, 0);
			} // if

			// checks again for eof
			fscanf(fPtr, "%d", &i);
		} // while

		//then close the file
		fclose(fPtr);
	} // if
	return 0;
} // loadEmployees()

// saves employees from employee linked list to a file
void saveEmployees(struct employeeList *employeeHead)
{
	printf("\nSaving Employees to file\n");

	FILE *fPtr = NULL;

	// open file
	fPtr = fopen(EMPLOYEE_DATA, WRITEMODE);
	if (fPtr == NULL)
	{
		printf("\n\n\tCould Not open file\n");
	}
	else
	{
		struct employeeList *temp;
		temp = (struct employeeList*)malloc(sizeof(struct employeeList));
		temp = employeeHead; // points temp at start of linked list

		while (temp != NULL)
		{
			// edit strings by replacing spaces with underscores
			// so they can be read from file easier
			editString(temp->employeeInfo.name, 1); // 1 to replace spaces
			editString(temp->employeeInfo.address, 1);
			editString(temp->employeeInfo.department, 1);

			// Saves employee details to file
			fprintf(fPtr, "%d\n", temp->employeeInfo.id);
			fprintf(fPtr, "%s\n", temp->employeeInfo.name);
			fprintf(fPtr, "%s\n", temp->employeeInfo.address);
			fprintf(fPtr, "%s\n", temp->employeeInfo.department);
			fprintf(fPtr, "%d %d %d\n", temp->employeeInfo.dateJoined.day,
				temp->employeeInfo.dateJoined.month,
				temp->employeeInfo.dateJoined.year);
			fprintf(fPtr, "%.2f\n", temp->employeeInfo.annualSalary);
			fprintf(fPtr, "%s\n", temp->employeeInfo.email);

			// move to next employee in list
			temp = temp->next;
		} // while

		// print eof at end of the file. EOF = 0
		fprintf(fPtr, "%d\n", 0);

		// close the file
		fclose(fPtr);
	} // if
} // saveEmployees()


