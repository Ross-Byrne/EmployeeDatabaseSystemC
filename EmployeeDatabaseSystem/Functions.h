// Ross Byrne 2015
// Functions Header File
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<conio.h>

// File Reading and Writing
#define USER_LOGIN "UserLogin.txt"
#define EMPLOYEE_DATA "Employees.txt"
#define EMPLOYEE_REPORT "EmployeeReport.txt"
#define WRITEMODE "w"
#define READMODE "r"
#define APPENDMODE "a"

#define MAX_COUNT 200 

// Structures
//======================================================================================//

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
	char email[35]; // must contain '.', '@' and '.com'
}EMPLOYEE;

// EMPLOYEE linked list node structure
struct employeeList
{
	EMPLOYEE employeeInfo;
	struct employeeList *next;
};

// login users linked list
struct loginUsers
{
	char username[25];
	char password[25];
	struct loginUsers *next;
};

// department information structure
typedef struct 
{
	char departmentName[25];
	int employeeCount;
	float totalAnnualSal;
	float totalBonus;
	float totalFinancialOutlay;
}DEPARTMENT_INFO;

// linked list of departments info for employee report
struct employeeReport
{
	DEPARTMENT_INFO departmentInfo;
	struct employeeReport *next;
};

// Functions
//======================================================================================//

// Menu Fuctions
void printMainMenu();
void printMainEmployeeMenu();

// employee linked list Functions
void initialiseFirstEmployee(struct employeeList *employeeHead);
void addEmployee(struct employeeList **employeeHeadPtr, struct employeeList *employeeHead);
void displayEmployeeDetails(struct employeeList *employeeHead);
void updateEmployeeDetails(struct employeeList *employeeHead);
void deleteEmployee(struct employeeList **employeeHeadPtr, struct employeeList *employeeHead);
void displayAllEmployees(struct employeeList *employeeHead);
void employeeReport(struct employeeList *employeeHead, struct employeeReport *reportHead);

// loading employees to and from file
void loadEmployees(struct employeeList *loginHead);
void saveEmployees(struct employeeList *employeeHead);

// loading users from file
void loadUsers(struct loginUsers *loginHead);
void addLoginUser(struct loginUsers *loginHead, char user[25], char pass[25]);
void displayUsers(struct loginUsers *loginHead);

// login validation
int login(struct loginUsers *loginHead);

// time validation
int daysInMonth(int month, int year);
int validateDate(int day, int month, int year);

// Other time functions
time_t getEmployeeTime(struct employeeList *temp);

// email Validation
int emailValidation(char *email);

// Other Functions
void cleanString(char *temp);
int confirmEmployeeDelete(struct employeeList *temp);
int searchEmployeeByIdOrName();
void printEmployeeDetails(struct employeeList *temp);
void editString(char *temp, int num);
void addReportDepartment(struct employeeList *temp, struct employeeReport *newDepartment);
void updateReportDepartment(struct employeeList *temp, struct employeeReport *reportTemp);
void printEmployeeReport(struct employeeReport *reportHead);