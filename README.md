# EmployeeDatabaseSystemC

This is a second year college project for Advanced Procedural Programming, written in C in Visual Studio 2013 

Employee database using a "Employees.txt" to hold all employee information.
When the program turns on, it loads employee information into a linked list.
When the user exits the program using the menu option 7 - exit,
The contents of the linked  list are saved to "Employees.txt", replace
previous content with the updated information.

To use the program the user requires a user login.
3 user logins can be found in "UserLogin.txt".
User logins are as follows:

Username: John_Smith 
Password: 123456  

Username: Sam_Jones 
Password: helloworld  

Username: Ross_Byrne 
Password: banana

#Program Features

After the user logs in, the main program menu is shown.
These menu options are as follows:

	1.) Add Employee.
	2.) Display Employee Details.
	3.) Update Employee.
	4.) Delete Employee.
	5.) Display All Employees By Department.
	6.) Employee Report.
	7.) Exit.

1.) Add Employees - This adds a new employee at the correct position 
		                based on their ID number into the linked list. 
		                The ID number must be unique.

2.) Display Employee Details - Allows the user to input either an Employee ID 
			                         or a name to display the details for that employee.

3.) Update Employee - Allows the user to update the address, 
		                  department or annual salary of an employee 
		                  based on either a name or ID being entered.

4.) Delete Employee - Allows the user to delete an employee from the list 
		                  by ID number or name.

5.) Display All Employees By Department - Displays all employees by department.

6.) Employee Report - Displays an employee report which outputs the following 
		                  information per department. This report is also written 
		                  out to a file called "EmployeeReport.txt" for future reading.

		                  
Contents Of Report:
- Department Name.
- Number of Employees.
- Total Salary Per Annum.
- Total Bonuses - this is paid to all employees based on their annual salary and is calculated as follows:
5% - for employees employed longer then 10 years.
4% - for employees employed between 5 and 10 years.
3% - for employees employed for less then 5 years.
- Total Financial Outlay Per Annum For That Department. 

7.) Exit - Saves the Employee linked list, with all of the
	         Employee information, to "Employees.txt" and then
	         exits the program.

#Other Features

- The hire date being set for employees must be a valid date.
- Employee E-mail addresses must contain a '.', '@' and must end with '.com'.
