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
	printf("\n6.) Employee Report.\n");
} // printMainEmployeeMenu()

void addEmployee(struct employeeList *employeeHead)
{
	// make a temp node
	struct employeeList *temp;
	temp = (struct employeeList*)malloc(sizeof(struct employeeList));
	temp = employeeHead; // make it point at start of linked list

	while (temp->next != NULL) // go to the last node
	{
		temp = temp->next;
	} // while

	// make the new employee & allocate memory for it
	struct employeeList *newEmployee;
	newEmployee = (struct employeeList*)malloc(sizeof(struct employeeList));

	// enter data
	newEmployee->employeeInfo.id = 12345;

	newEmployee->next = NULL; // new employee doesn't point to anything
	temp->next = newEmployee; // adds new employee to end of linked list
} // addEmployee()

void deleteEmployee(struct employeeList *employeeHead) // deletes last employee in list
{
	struct employeeList *temp;
	struct employeeList *oldTemp;
	temp = (struct employeeList*)malloc(sizeof(struct employeeList));
	oldTemp = (struct employeeList*)malloc(sizeof(struct employeeList));
	temp = employeeHead;

	while (temp->next != NULL)  // goes to the last employee
	{							// while keeping track of the second last employee
		oldTemp = temp;
		temp = temp->next;
	} // while

	oldTemp->next = NULL;
	free(temp);
	printf("\nLast Employee Deleted!\n");
} // deleteEmployee()

// displays all of the employees in list
void displayEmployees(struct employeeList *employeeHead)
{
	struct employeeList *temp;
	temp = (struct employeeList*)malloc(sizeof(struct employeeList));
	temp = employeeHead;

	while (temp != NULL)
	{
		printf("\nEmployee ID: %d", temp->employeeInfo.id); // show data
		temp = temp->next;
	} // while
} // displayEmployees()

// finds an employee based on employee ID
void searchEmployeeId(struct employeeList *employeeHead, int employeeId)
{
	struct employeeList *temp;
	temp = (struct employeeList*)malloc(sizeof(struct employeeList));
	temp = employeeHead;

	while (temp != NULL)
	{
		if (temp->employeeInfo.id == employeeId)
		{
			printf("\nEmployee Found!\n");
			return;
		} // if

		temp = temp->next;
	} // while

	printf("\nData Not Found!\n");
} // searchEmployeeId()

// finds an employee based on employee name
void searchEmployeeName(struct employeeList *employeeHead, char employeeName[25])
{
	struct employeeList *temp;
	temp = (struct employeeList*)malloc(sizeof(struct employeeList));
	temp = employeeHead;

	while (temp != NULL)
	{
		if (strcmp(temp->employeeInfo.name, employeeName) == 0) // if they are equal
		{
			printf("\nEmployee Found!\n");
			return;
		} // if

		temp = temp->next;
	} // while

	printf("\nEmployee Not Found!\n");
} // searchEmployeeName()

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
	fgets(user, 24, stdin);
	printf("iEnter Your Password: ");
	fflush(stdin);
	fgets(pass, 24, stdin);

	// checks for '\n' newline char that gets added to end of string with fgets
	// and then removes it
	if (user[strlen(user) - 1] == '\n')
	{
		user[strlen(user) - 1] = '\0';
	} // if
	if (pass[strlen(pass) - 1] == '\n')
	{
		pass[strlen(pass) - 1] = '\0';
	} // if

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
} // searchLoginUser()

// add first user to linked list
void addFirstUser(struct loginUsers *loginHead, char user[25], char pass[25])
{
	// make a temp node
	struct loginUsers *temp;
	temp = (struct loginUsers*)malloc(sizeof(struct loginUsers));
	temp = loginHead; // make it point at start of linked list

	strncpy_s(temp->username, 25, user, 25);
	strncpy_s(temp->password, 25, pass, 25);
} // addFirstUser()

// adds a login user to the login user linked list
void addUser(struct loginUsers *loginHead, char user[25], char pass[25])
{
	// make a temp node
	struct loginUsers *temp;
	temp = (struct loginUsers*)malloc(sizeof(struct loginUsers));
	temp = loginHead; // make it point at start of linked list

	while (temp->next != NULL) // go to the last node
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
} // addUser()

// displays all of the users in list
void displayUsers(struct loginUsers *loginHead)
{
	struct loginUsers *temp;
	temp = (struct loginUsers*)malloc(sizeof(struct loginUsers));
	temp = loginHead;

	while (temp != NULL)
	{
		printf("\nUser Name: %s Pass: %s", temp->username, temp->password); // show data
		temp = temp->next;
	} // while
} // displayUsers()

// reads usernames and passwords of login users from a file
void loadUsers(struct loginUsers *loginHead)
{
	printf("\nStarting to load users...\n");
	FILE *fPtr = NULL;
	int i = 0;
	char user[25] = "user", pass[25] = "pass";

	fPtr = fopen(USER_LOGIN, READMODE);
	if (fPtr == NULL)
	{
		printf("\n\nCould Not open file '%s'.\n", USER_LOGIN);
	}
	else
	{
		// save values from text file to variables

		// add first user to the linked list
		fscanf(fPtr, "%s %s", user, pass);
		addFirstUser(loginHead, user, pass);
		
		// add the rest
		fscanf(fPtr, "%s %s", user, pass);
		addUser(loginHead, user, pass);
		
		fscanf(fPtr, "%s %s", user, pass);
		addUser(loginHead, user, pass);
		
		//then close the file
		fclose(fPtr);
		printf("\nUser login details loaded correctly!\n");
		displayUsers(loginHead);
	} // if
	
} // loadUsers()



