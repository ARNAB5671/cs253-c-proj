# cs253-c-proj



Car Rental System README

Project Structure:

The Car Rental System is organized into a single C++ source file (CarRentalSystem.cpp). The program consists of three main classes: Customer_functions, Employee_functions, and Manager_functions. These classes represent different functionalities of the car rental system for customers, employees, and managers, respectively. Additionally, three data classes (CustomerDatas, EmployeeData, and CarData) are used to store information about customers, employees, and cars.

How to Run:
We have to ensure to  have a C++ compiler installed on our system.

Now we have to open a terminal or command prompt.

Then we navigate to the directory containing CarRentalSystem.cpp.

Then we compile the program using the following command:

bash
Copy code
g++ -o CarRentalSystem CarRentalSystem.cpp
(We replace g++ with our specific compiler command if needed)

we run the compiled executable:

bash
Copy code
./CarRentalSystem
Then we follow the on-screen instructions to interact with the Car Rental System.

Assumptions Made
DateScript Format: The program assumes that the user inputs the return date in the format ddmm. Invalid date inputs are handled with a re-entry request.

Password Handling: Passwords are assumed to be case-sensitive.

Manager's Code: A manager needs to input a manager's code (3112003) to access manager functionalities.

Rental Period Calculation: The number of days for calculating rental amounts is based on a predefined function (NumOfDays) and may not consider leap years or other date-specific factors.

Random Data Generation: Random car brand names are generated for demonstration purposes using a distribution of numbers between 1 and 10.

Additional Notes
The program includes sample data for customers, employees, and cars to demonstrate functionality.
Customers and employees can log in to view, rent, and manage cars based on their roles.
The manager has additional functionalities to manage the database, including adding, deleting, and updating customer, employee, and car information.
