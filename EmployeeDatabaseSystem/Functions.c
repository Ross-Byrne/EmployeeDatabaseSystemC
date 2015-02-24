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

void addEmployee(struct employeeList *head)
{
	// make a temp node
	struct employeeList *temp;
	temp = (struct employeeList*)malloc(sizeof(struct employeeList));
	temp = head; // make it point at start of linked list

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

void deleteEmployee(struct employeeList *head) // deletes last employee in list
{
	struct employeeList *temp;
	struct employeeList *oldTemp;
	temp = (struct employeeList*)malloc(sizeof(struct employeeList));
	oldTemp = (struct employeeList*)malloc(sizeof(struct employeeList));
	temp = head;

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
void displayEmployees(struct employeeList *head)
{
	struct employeeList *temp;
	temp = (struct employeeList*)malloc(sizeof(struct employeeList));
	temp = head;

	while (temp != NULL)
	{
		printf("\nEmployee ID: %d", temp->employeeInfo.id); // show data
		temp = temp->next;
	} // while
} // displayEmployees()

