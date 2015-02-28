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

// adds values for first employee to initialise the linked list
void initialiseFirstEmployee(struct employeeList *employeeHead)
{
	employeeHead->employeeInfo.id = 1111;
	strncpy_s(employeeHead->employeeInfo.name, 25, "Mike Sullivan", 25);
	strncpy_s(employeeHead->employeeInfo.address, 45, "Galway, Ireland", 45);
	strncpy_s(employeeHead->employeeInfo.department, 25, "Sales & Marketing", 25);
	employeeHead->employeeInfo.dateJoined.day = 25;
	employeeHead->employeeInfo.dateJoined.month = 03;
	employeeHead->employeeInfo.dateJoined.year = 2000;
	employeeHead->employeeInfo.annualSalary = 38000.00;
	strncpy_s(employeeHead->employeeInfo.email, 35, "mike.sullivan@gmail.com", 35);
} // initialiseFirstEmployee()

void addEmployee(struct employeeList *employeeHead)
{
	char tempChar[45] = "temp";
	int tempInt = 0;
	float tempFloat = 0.0;

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
	printf("\nEnter New Employee's Details.\n");

	printf("\nEnter ID (Must Be Unique Number): ");
	fflush(stdin);
	scanf("%d", &tempInt);
	newEmployee->employeeInfo.id = tempInt;

	printf("\nEnter Name: ");
	fflush(stdin);
	gets(tempChar);
	strncpy_s(newEmployee->employeeInfo.name, 25, tempChar, 25);

	printf("\nEnter Address: ");
	fflush(stdin);
	gets(tempChar);
	strncpy_s(newEmployee->employeeInfo.address, 25, tempChar, 25);

	printf("\nEnter Department: ");
	fflush(stdin);
	gets(tempChar);
	strncpy_s(newEmployee->employeeInfo.department, 25, tempChar, 25);

	printf("\nEnter Date Joined: ");
	printf("\nEnter Year (eg 1999): ");
	fflush(stdin);
	scanf("%d", &tempInt);
	newEmployee->employeeInfo.dateJoined.year = tempInt;

	printf("\nEnter Month (eg 03): ");
	fflush(stdin);
	scanf("%d", &tempInt);
	newEmployee->employeeInfo.dateJoined.month = tempInt;

	printf("\nEnter Day (eg 28): ");
	fflush(stdin);
	scanf("%d", &tempInt);
	newEmployee->employeeInfo.dateJoined.day = tempInt;
	
	printf("\nEnter Annual Salary: ");
	fflush(stdin);
	scanf("%f", &tempFloat);
	newEmployee->employeeInfo.annualSalary = tempFloat;

	printf("\nEnter E-mail Address: ");
	fflush(stdin);
	gets(tempChar);
	strncpy_s(newEmployee->employeeInfo.email, 35, tempChar, 35);

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
		
		// move to next employee in list
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
	gets(user);
	printf("Enter Your Password: ");
	fflush(stdin);
	gets(pass);

	/*// checks for '\n' newline char that gets added to end of string with fgets
	// and then removes it
	if (user[strlen(user) - 1] == '\n')
	{
		user[strlen(user) - 1] = '\0';
	} // if
	if (pass[strlen(pass) - 1] == '\n')
	{
		pass[strlen(pass) - 1] = '\0';
	} // if*/

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

		/*// for testing
		printf("\nUser login details loaded correctly!\n");
		displayUsers(loginHead);*/
	} // if
} // loadUsers()



