// Ross Byrne 2015
// Functions Header File

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures

// date strucure 31/12/1999 format
typedef struct
{
	int day;
	int month;
	int year;
}DATE;

// Employee Structure
typedef struct
{
	int id; // must be unique
	char name[25];
	char address[45];
	char department[25];
	DATE dateJoined;
	float annualSalary;
	char email[25]; // must contain '.', '@' and '.com'
}EMPLOYEE;

// EMPLOYEE linked list node structure
struct employeeList
{
	EMPLOYEE employeeInfo;
	struct employeeList *next;
};

// Functions

// Menu Fuctions
void printMainMenu();
void printMainEmployeeMenu();

// linked list Functions
void addEmployee(struct employeeList *head);
void displayEmployees(struct employeeList *head);
void deleteEmployee(struct employeeList *head);

// login validation
int login(char username[25], char password[25]);
