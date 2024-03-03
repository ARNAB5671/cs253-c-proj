
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <random>
#include <bits/stdc++.h>
#define ll long long

#define push_back push_back
using namespace std;
class CustomerDatas{
 public:
 int customerID;
 string name;
 string password;
 vector<pair<int,string>> RentedCars;
 int FinesDue;
 int Customerinput1;
};
class EmployeeData{
 public:
 int employeeID;
 string name;
 string password;
 vector<pair<int,string>> RentedCars;
 float FinesDue;
 int employeeinput1;
};
class CarData{
 public:
 int CarID;
 string name;
 int DailyRent;
 bool IsAvailable;
 string Brand;
};
vector<CustomerDatas> customers;
vector<CarData> cars;
vector<EmployeeData> employees;
int NumOfDays(string DateScript1,string DateScript2){
 int num;
 int day1=stoi(DateScript1.substr(0,2));
 int day2=stoi(DateScript2.substr(0,2));
 int month1=stoi(DateScript1.substr(2,4));
 int month2=stoi(DateScript2.substr(2,4));
 int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 int num1=0,num2=0;
 for (int i = 0; i < month1; i++) {
    num1 += daysInMonth[i];
}
for (int i = 0; i < month2; i++) {
    num2 += daysInMonth[i];
}
 num1+=day1;
 num2+=day2;
 num=num2-num1;
 return num;
 }
int CalcuatemaxCars(int input1){
 int MaxnoOfCars=input1/5;
 if(MaxnoOfCars==0) MaxnoOfCars=1;
 return MaxnoOfCars;
 }
class Customer_functions:public CustomerDatas, public CarData{
 private:
 int id;
 void DisplayCars(){
 cout<<"Car ID\tName\t\t\tBrand\tDaily Rental Cost\tAvailability\n";
 f(0,cars.size()){
 string s;
 s=cars[i].IsAvailable?"true":"false";
 cout<<cars[i].CarID<<"\t"<<cars[i].name<<"\t"<<cars[i].Brand<<"\t"<<cars[i].DailyRent<<"\t"<<s<<"\n";
 }
 Proceed();
 }
 void DisplayChoice(){
 int choice;
 cout<<"Make your selection by pressing:\n";
 cout<<"1 :Observe your leased vehicles"<<"\n";
 cout<<"2 : Know your rented Cars and maximum number of cars rentable"<<"\n";
 cout<<"3 : Inquire about your overdue penalty\n";
 cout<<"Any other key to go back\n";
 cin>>choice;
 if(choice==1){
 if(customers[id].RentedCars.size()==0){
 cout<<"--------------Currently, there are no vehicles under rental at the moment--------------\n";
 return Proceed();
 }
 cout<<"Car id\t"<<"Name\t\t\t"<<"Brand\t"<<"Return Date"<<"\n";
 f(0,customers[id].RentedCars.size()){
 int j=customers[id].RentedCars[i].first;
 cout<<cars[j].CarID<<"\t"<<cars[j].name<<"\t"<<cars[j].Brand<<"\t"<<customers[id].RentedCars[i].second<<"\n";
 }
 }
 else if(choice==2){
 cout<<"Your customer ID value is : "<<customers[id].Customerinput1<<"\n";
 int MaxCarPerCustomer=0;
 MaxCarPerCustomer=CalcuatemaxCars(customers[id].Customerinput1);
 cout<<"The maximum quantity of cars permissible for rental concurrently : "<<MaxCarPerCustomer<<"\n";
 }
 else if(choice==3){
 cout<<"The amount of penalty you owe is : Rs "<<customers[id].FinesDue<<"\n";
 }
 Proceed();
 }
 void RentCar(){
 int MaxCarPerCustomer=CalcuatemaxCars(customers[id].Customerinput1);
 cout<<"--------------Checking your ID--------------\n\n";
 if(MaxCarPerCustomer<=customers[id].RentedCars.size()){
 cout<<"You have reached the maximum allowed car rentals. Please return a vehicle or consider enhancing your ID to increase the number of cars available for simultaneous rental..\n";
 return Proceed();
 }
 cout<<"Feel free to lease a vehicle! Kindly proceed by entering the ID of the desired car for rental:\n";
 int CarID;
 cin>>CarID;
 if(CarID<cars.size()){
 if(cars[CarID].IsAvailable==true){
 string DateScript;
 cout<<"Input the date in ddmm format for the planned return of the vehicle. :"<<"\n";
 cin>>DateScript;
 if(DateScript.size()!=4 || stoi(DateScript.substr(0,2))>31 || stoi(DateScript.substr(2,4))>12){
 cout<<"Input a valid date in the specified ddmm format, please. :"<<"\n";
 cin>>DateScript;
 if(DateScript.size()!=4 || stoi(DateScript.substr(0,2))>31 || stoi(DateScript.substr(2,4))>12){
 cout<<"--------------Too many wrong attempts--------------"<<"\n";
 return Proceed();
 }
 }
 int num_of_days=NumOfDays("0303",DateScript);
 cout<<"Total amount payable : Rs "<<cars[CarID].DailyRent*num_of_days<<"\n";
 cars[CarID].IsAvailable=false;
 (customers[id].RentedCars).push_back({CarID,DateScript});
 customers[id].FinesDue+=cars[CarID].DailyRent*num_of_days;
 cout<<"Return DateScript is "<<DateScript.substr(0,2)<<"/"<<DateScript.substr(2,4)<<"\n";
 cout<<"--------------"<<cars[CarID].name<<" has been rented successfully--------------\n";
 }
 else cout<<"--------------The specified vehicle ID is currently unavailable.--------------\n";
 }
 else cout<<"--------------Invalid car id entered--------------\n";
 Proceed();
 }
 public:
 int GEtIdentity(){
 cout<<"Enter your customerID:\n";
 cin>>id;
 if(id<customers.size()&&id>=0){
 cout<<"--------------Welcome "<<customers[id].name<<"--------------\n";
 return 1;
 }
 else{
 cout<<"--------------Invalid customer id entered--------------\n";
 return 0;
 }
 }
 int verify(){
 string password;
 cout<<"Enter your password:\n";
 cin>>password;
 if(password==customers[id].password) return 1;
 cout<<"--------------Wrong password entered--------------\n";
 return 0;
 }
 void Proceed(){
 cout<<"What would you like to do:\n";
 cout<<"1 : View the cars available in our inventory\n";
 cout<<"2 : View your personal Details and profile\n";
 cout<<"3 : Rent a car\n";
 cout<<"Any other key to exit\n";
 int choicea;
 cin>>choicea;
 if(choicea==1) DisplayCars();
 else if(choicea==2) DisplayChoice();
 else if(choicea==3) RentCar();
 else return;
 }
};
class Employee_functions:public EmployeeData, public CarData{
 private:
 int id;
 void DisplayCars(){
 cout<<"Car id\tName\t\t\tBrand\tDaily Rent\tAvailability\n";
 for (int i = 0; i < cars.size(); i++) {
    string s = cars[i].IsAvailable ? "true" : "false";
    cout << cars[i].CarID << "\t" << cars[i].name << "\t" << cars[i].Brand << "\t" << cars[i].DailyRent << "\t" << s << "\n";
}

 Proceed();
 }
 void DisplayChoice(){
 int choice;
 cout<<"Enter your choice, Press:-\n";
 cout<<"1 : To check the cars currently under your rental."<<"\n";
 cout<<"2 : To know your details and maximum number of cars rentable"<<"\n";
 cout<<"3 : inquire about the penalty amount you owe\n";
 cout<<"Any other key to go back\n";
 cin>>choice;
 if(choice==1){
 if(employees[id].RentedCars.size()==0){
 cout<<"--------------No cars rented right now--------------\n";
 return Proceed();
 }
 cout<<"Car id\t"<<"Name\t\t\t"<<"Brand\t"<<"Return Date"<<"\n";
 for (int i = 0; i < employees[id].RentedCars.size(); i++) {
    int j = employees[id].RentedCars[i].first;
    cout << cars[j].CarID << "\t" << cars[j].name << "\t" << cars[j].Brand << "\t" << employees[id].RentedCars[i].second << "\n";
}

 }
 else if(choice==2){
 cout<<"Your employee ID value is : "<<employees[id].employeeinput1<<"\n";
 int MaxCarPerCustomer=0;
 MaxCarPerCustomer=CalcuatemaxCars(employees[id].employeeinput1);
 cout<<"Maximum number of cars you can rent at a time is "<<MaxCarPerCustomer<<"\n";
 }
 else if(choice==3){
 cout<<"Your penalty amount is : Rs "<<employees[id].FinesDue<<"\n";
 }
 Proceed();
 }
 void RentCar(){
 int MaxCarPerCustomer=CalcuatemaxCars(employees[id].employeeinput1);
 if(MaxCarPerCustomer<=employees[id].RentedCars.size()){
 cout<<"You have reached the maximum cap for car rentals. Please return a vehicle or consider enhancing your ID to increase the number of cars available for simultaneous rental..\n";
 return Proceed();
 }
 cout<<"--------------Checking your input1--------------\n\n";
 cout<<"Feel free to lease a car! Kindly proceed by entering the ID of the desired vehicle for rental.:-\n";
 int CarID;
 cin>>CarID;
for (int i = 0; i < cars.size(); i++) {
    if (cars[i].CarID == CarID) {
        if (cars[i].IsAvailable == true) {
            string DateScript;
            cout << "Input the return date for this car in ddmm format, please.: \n";
            cin >> DateScript;

            if (DateScript.size() != 4 || stoi(DateScript.substr(0, 2)) > 31 || stoi(DateScript.substr(2, 4)) > 12) {
                cout << "Enter a valid DateScript in the specified ddmm format : \n";
                cin >> DateScript;

                if (DateScript.size() != 4 || stoi(DateScript.substr(0, 2)) > 31 || stoi(DateScript.substr(2, 4)) > 12) {
                    cout << "--------------Too many wrong attempts--------------\n";
                    return Proceed();
                }
            }

            int num_of_days = NumOfDays("0303", DateScript);
            cout << "Total amount payable : Rs " << cars[i].DailyRent * num_of_days * 0.85 << "\n";
            cars[i].IsAvailable = false;
            employees[id].RentedCars.push_back({CarID, DateScript});
            employees[id].FinesDue += cars[i].DailyRent * num_of_days * 0.85;
            cout << "Return DateScript is " << DateScript.substr(0, 2) << "/" << DateScript.substr(2, 4) << "\n";
            cout << "--------------" << cars[i].name << " has been rented successfully--------------\n";
        } else {
            cout << "--------------The specified vehicle ID is currently unavailable.--------------\n";
        }
        break;
    }
}

 Proceed();
 }
 public:
 int GEtIdentity(){
 cout<<"Enter your employeeID:\n";
 cin>>id;
 if(id<employees.size()&&id>=0){
 cout<<"--------------"<<"Welcome "<<employees[id].name<<"--------------\n";
 return 1;
 }
 else{
 cout<<"--------------Employee id entered is Invalid--------------\n";
 return 0;
 }
 }
 int verify(){
 string password;
 cout<<"Enter your password:\n";
 cin>>password;
 if(password==employees[id].password) return 1;
 cout<<"--------------Wrong password entered--------------\n";
 return 0;
 }
 void Proceed(){
 cout<<"What would you like to do:\n";
 cout<<"1 : View the cars in our store\n";
 cout<<"2 : View your personal details and profile\n";
 cout<<"3 : Rent a car\n";
 cout<<"Any other key to exit\n";
 int choicea;
 cin>>choicea;
 if(choicea==1) DisplayCars();
 else if(choicea==2) DisplayChoice();
 else if(choicea==3) RentCar();
 else return;
 }
};
class Manager_functions: public CustomerDatas,public EmployeeData,public CarData{
 public:
 int verify(){
 cout<<"Enter the Manager password: \n";
 cin>>managers_code;
 if(managers_code==3112003) return 1;
 return 0;
 }
 void Proceed(){
 cout<<"What action would you prefer to take?:\n";
 cout<<"1 : Manage customers' database\n2 : Manage employees' database\n3 : Manage cars' database\nAny other key to exit\n";
 int ch;
 cin>>ch;
 if(ch==1){
 int choicea;
 cout<<"1 : Add a new customer\n2 : Delete a customer's data\n3 : Update customer details\nAny other key to exit\n";
 cin>>choicea;
 if(choicea==1) AddCustomer();
 else if(choicea==2) RemoveCustomer();
 else if(choicea==3) UpdateCustomerDetails();
 }
 else if(ch==2){
 int choicea;
 cout<<"1 : Add a new employee\n2 : Delete a employee's data\n3 : To update employee details\nAny other key to exit\n";
 cin>>choicea;
 if(choicea==1) AddEmployee();
 else if(choicea==2) DeleteEmployee();
 else if(choicea==3) UpdateEmployeeDetails();
 }
 else if(ch==3){
 int choicea;
 cout<<"1 : View all cars' details\n2 : To add a new car\n3 : To delete a car's data\n4 : To upDateScript details of a car\nAny other key to exit\n";
 cin>>choicea;
 if(choicea==1) DisplayCars();
 if(choicea==2) AddCars();
 else if(choicea==3) RemoveCar();
 else if(choicea==4) UpdateCarDetails();
 }
 }
 private:
 int managers_code;
 void AddCustomer(){
 string name;
 string password;
 cout<<"Enter the name of the new customer to be added\n";
 cin>>name;
 cout<<"Enter the password of the new customer profile to be added\n";
 cin>>password;
 CustomerDatas new_cust;
 new_cust.customerID=customers.size();
 new_cust.password=password;
 new_cust.Customerinput1=10;
 new_cust.FinesDue=0;
 new_cust.RentedCars={};
 customers.push_back(new_cust);
 cout<<"--------------The new customer profile has been created successfully--------------\n";
 Proceed();
 }
 void RemoveCustomer(){
 int id;
 cout<<"Enter the ID of the customer, whose profile has to be deleted\n";
 cin>>id;
 int j=-1;
 for(int i=0;i<customers.size();i++){
 if(customers[i].customerID==id){
 j=i;
 break;
 }
 }
 if(j==-1){
 cout<<"--------------No customer exists with the entered ID--------------\n";
 return Proceed();
 }
 customers.erase(customers.begin()+j);
 cout<<"--------------The customer profile has been deleted successfully--------------\n";
 Proceed();
 }
 void UpdateCustomerDetails(){
 int id;
 cout<<"Enter the ID of the customer, whose profile has to be updated\n";
 cin>>id;
 int j=-1;
 for(int i=0;i<customers.size();i++){
 if(customers[i].customerID==id){
 j=i;
 break;
 }
 }
 if(j==-1){
 cout<<"--------------No customer exists with the entered ID--------------\n";
 return Proceed();
 }
 int ch;
 cout<<"Enter a choice:-"<<"\n";
 cout<<"1 : password\n2 : Customerinput1\n3 : FinesDue\n4 : Name\nAny other key to go back\n";
 cin>>ch;
 if(ch==1){
 string password;
 cout<<"Enter the new password\n";
 cin>>password;
 customers[id].password=password;
 cout<<"--------------Password changed successfully--------------\n";
 }
 else if(ch==2){
 int CarID;
 cout<<"Enter the ID of the car returned:\n";
 cin>>CarID;
 int j=-1;
for (int i = 0; i < customers[id].RentedCars.size(); i++) {
    if (customers[id].RentedCars[i].first == CarID) {
        j = i;
        break;
    }
}

 if(j==-1){
 cout<<"--------------The entered car id was not rented by this customer--------------\n";
 return Proceed();
 }
 string ReturnDAtedetail;
 int Rateofcondition;
 cout<<"Enter the DateScript when it was returned:\n";
 cin>>ReturnDAtedetail;
 cout<<"Rate the condition of the car returned on a scale of 1 to 10:\n";
 cin>>Rateofcondition;
 int change=0;
 int m=NumOfDays(customers[id].RentedCars[j].second,ReturnDAtedetail);
 change+=m>0?(-5*m):10;
 change+=Rateofcondition>6?Rateofcondition:(Rateofcondition-7);
 customers[id].Customerinput1+=change;
 cout<<"--------------The customer details has been updated successfully--------------\n";
 }
 else if(ch==3){
 int FineforOneday=300;
 int PaidAmount1;
 int CarID;
 string ReturnDAtedetail;
 cout<<"Enter the ID of the car returned:\n";
 cin>>CarID;
 int j=-1;
 f(0,customers[id].RentedCars.size()){
 if(customers[id].RentedCars[i].first==CarID){
 j=i;
 break;
 }
 }
 if(j==-1){
 cout<<"--------------The entered car id was not rented by this customer--------------\n";
 return Proceed();
 }
 cout<<"Enter the DateScript when it was returned\n";
 cin>>ReturnDAtedetail;
 cout<<"Enter the amount paid on return\n";
 cin>>PaidAmount1;
 int m=NumOfDays(customers[id].RentedCars[j].second,ReturnDAtedetail);
 customers[id].FinesDue+=m>0?m*FineforOneday:0;
 customers[id].FinesDue-=PaidAmount1;
 cout<<"--------------Due fine of the specified customer upDateScriptd successfully--------------\n";
 }
 else if(ch==4){
 string name;
 cout<<"Enter the name to be set\n";
 cin>>name;
 customers[id].name=name;
 cout<<"--------------Customer name upDateScriptd successfully--------------\n";
 }
 else return Proceed();
 Proceed();
 }
 void AddEmployee(){
 string password;
 string name;
 cout<<"Enter the name of the new employee to be added\n";
 cin>>name;
 cout<<"Enter the password of the new employee profile to be added\n";
 cin>>password;
 EmployeeData new_empl;
 new_empl.employeeID=employees.size();
 new_empl.password=password;
 new_empl.employeeinput1=10;
 new_empl.FinesDue=0;
 new_empl.RentedCars={};
 employees.push_back(new_empl);
 cout<<"--------------The new employee has been successfully added--------------\n";
 Proceed();
 }
 void DeleteEmployee(){
 int id;
 cout<<"Enter the ID of the employee, whose profile has to be deleted\n";
 cin>>id;
 int j=-1;
 for(int i=0;i<employees.size();i++){
 if(employees[i].employeeID==id){
 j=i;
 break;
 }
 }
 if(j==-1){
 cout<<"--------------No employee exists with the entered ID--------------\n";
 return Proceed();
 }
 employees.erase(employees.begin()+j);
 cout<<"--------------The employee profile has been deleted successfully--------------\n";
 Proceed();
 }
 void UpdateEmployeeDetails(){
 int id;
 cout<<"Enter the ID of the employee, whose profile needs to be upDateScriptd : \n";
 cin>>id;
 int j=-1;
 for(int i=0;i<employees.size();i++){
 if(employees[i].employeeID==id){
 j=i;
 break;
 }
 }
 if(j==-1){
 cout<<"--------------No employee exists with the entered ID--------------\n";
 return Proceed();
 }
 int ch;
 cout<<"Enter a choice:-\n";
 cout<<"1 : password\n2 : employeeinput1\n3 : FinesDue\n4 : name\nAny other key to go back\n";
 cin>>ch;
 if(ch==1){
 string password;
 cout<<"Enter the new password\n";
 cin>>password;
 employees[id].password=password;
 cout<<"--------------Password changed successfully--------------\n";
 }
 else if(ch==2){
 int CarID;
 cout<<"Enter the ID of the car returned:\n";
 cin>>CarID;
 int j=-1;
for (int i = 0; i < employees[id].RentedCars.size(); i++) {
    if (employees[id].RentedCars[i].first == CarID) {
        j = i;
        break;
    }
}

 if(j==-1){
 cout<<"--------------The entered car id was not rented by this employee--------------\n";
 return Proceed();
 }
 string ReturnDAtedetail;
 int Rateofcondition;
 cout<<"Enter the DateScript when it was returned:\n";
 cin>>ReturnDAtedetail;
 cout<<"Rate the condition of the car returned on a scale of 1 to 10:\n";
 cin>>Rateofcondition;
 int change=0;
 int m=NumOfDays(employees[id].RentedCars[j].second,ReturnDAtedetail);
 change+=m>0?(-5*m):10;
 change+=Rateofcondition>6?Rateofcondition:(Rateofcondition-7);
 employees[id].employeeinput1+=change;
 cout<<"--------------The employee details has been updated successfully--------------\n";
 }
 else if(ch==3){
 int FineforOneday=500;
 int PaidAmount1;
 int CarID;
 string ReturnDAtedetail;
 cout<<"Enter the ID of the car returned:\n";
 cin>>CarID;
 int j=-1;
for (int i = 0; i < employees[id].RentedCars.size(); i++) {
    if (employees[id].RentedCars[i].first == CarID) {
        j = i;
        break;
    }
}

 if(j==-1){
 cout<<"--------------The entered car id was not rented by this employee--------------\n";
 return Proceed();
 }
 cout<<"Enter the DateScript when it was returned\n";
 cin>>ReturnDAtedetail;
 cout<<"Enter the amount paid on return\n";
 cin>>PaidAmount1;
 int m=NumOfDays(employees[id].RentedCars[j].second,ReturnDAtedetail);
 employees[id].FinesDue+=m>0?m*FineforOneday:0;
 employees[id].FinesDue-=PaidAmount1;
 cout<<"--------------The penalty amount for the employee has been updated--------------\n";
 }
 else if(ch==4){
 string name;
 cout<<"Enter the name to be set\n";
 cin>>name;
 employees[id].name=name;
 cout<<"--------------Employee name upDated successfully--------------\n";
 }
 else return Proceed();
 Proceed();
 }
 void DisplayCars(){
 cout<<"Car id\tName\t\t\tBrand\tRent Per Day\tAvailability\n";
for (int i = 0; i < cars.size(); i++) {
    string s = cars[i].IsAvailable ? "true" : "false";
    cout << cars[i].CarID << "\t" << cars[i].name << "\t" << cars[i].Brand << "\t" << cars[i].DailyRent << "\t" << s << "\n";
}

 Proceed();
 }
 void AddCars(){
 int CarID;
 string name;
 int DailyRent;
 bool IsAvailable;
 string Brand;
 CarID=cars.size();
 cout<<"Input the car's name:-\n";
 cin>>name;
 cout<<"Input Brand name of the car:-\n";
 cin>>Brand;
 cout<<"Input Daily Rent of the car:-\n";
 cin>>DailyRent;
 cout<<"Enter the current availability status of the car.(1 for true or 0 for false):-\n";
 cin>>IsAvailable;
 CarData new_car;
 new_car.CarID=CarID;
 new_car.name=name;
 new_car.DailyRent=DailyRent;
 new_car.IsAvailable=IsAvailable;
 new_car.Brand=Brand;
 cars.push_back(new_car);
 cout<<"--------------The new car, "<<name<<" has been successfully added to the system:)--------------\n";
 Proceed();
 }
 void RemoveCar(){
 int CarID;
 cout<<"Enter the id of the car you want to delete\n";
 cin>>CarID;
 int j=-1;
 for (int i = 0; i < cars.size(); i++) {
    if (cars[i].CarID == CarID) {
        j = i;
        break;
    }
}

 if(j==-1){
 cout<<"--------------The provided car ID does not exist in the database--------------\n";
 return Proceed();
 }
 cars.erase(cars.begin()+j);
 cout<<"--------------The information for the designated car has been successfully removed.--------------\n";
 Proceed();
 }
 void UpdateCarDetails(){
 int CarID;
 cout<<"Enter the ID of the car, that you want to update\n";
 cin>>CarID;
 int j=-1;
 f(0,cars.size()){
 if(cars[i].CarID==CarID){
 j=i;
 break;
 }
 }
 if(j==-1){
 cout<<"--------------The entered car id does not exist--------------\n";
 return Proceed();
 }
 int ch;
 cout<<"What would you like to update:-\n";
 cout<<"1 : Name\n2 : Brand\n3 : Daily Rent\n4 : availability status\nAny other key to go back\n";
 cin>>ch;
 if(ch==1){
 cout<<"Enter the new name to be updated without spaces:-\n";
 string name;
 cin>>name;
 cars[j].name=name;
 cout<<"--------------The name has been updated--------------\n";
 }
 else if(ch==2){
 cout<<"Enter the new Brand name to be updated without spaces:-\n";
 string Brand;
 cin>>Brand;
 cars[j].Brand=Brand;
 cout<<"--------------The Brand name has been updated--------------\n";
 }
 else if(ch==3){
 cout<<"Enter the new value for Daily Rent:-\n";
 int DailyRent;
 cin>>DailyRent;
 cars[j].DailyRent=DailyRent;
 cout<<"--------------The rent per day has been updated--------------\n";
 }
 else if(ch==4){
 cout<<"Enter the new availability status(1 for true or 0 for false):-\n";
 int IsAvailable;
 cin>>IsAvailable;
 if(IsAvailable!=0 && IsAvailable!=1){
 cout<<"--------------Invalid availability entered--------------\n";
 return Proceed();
 }
 cars[j].IsAvailable=IsAvailable;
 cout<<"--------------The availability status has been changed--------------\n";
 }
 Proceed();
 }
};
int main(){
 for(int i = 0; i < 20; i++){
 CustomerDatas customer;
 customer.customerID = i;
 customer.name = "Customer"+to_string(i);
 customer.password = "password"+to_string(i);
 customer.RentedCars={};
 if(i>11 && i%2!=0 && i<18) customer.RentedCars.push_back({i,"0"+to_string(i+1)+"03"});
 customer.FinesDue = 500+10*i;
 customer.Customerinput1 = 10;
 customers.push_back(customer);
 }
for (int i = 0; i < 20; i++) {
    EmployeeData employee;
    employee.employeeID = i;
    employee.name = "employee" + to_string(i);
    employee.password = "password" + to_string(i);
    employee.RentedCars = {};

    if (i < 5 && i % 2 == 0)
        employee.RentedCars.push_back({i, "0" + to_string(i + 1) + "03"});

    employee.FinesDue = 300 + 10 * i;
    employee.FinesDue = 0;
    employee.employeeinput1 = 15;
    employees.push_back(employee);
}

 random_device rd;
 mt19937 gen(rd());
 uniform_int_distribution<int> distribution(1,10);
 for (int i=0;i<20;++i) {
 CarData car;
 car.CarID=i;
 switch (i) {
 case 0: car.name = "Bugatti Veyron"; car.IsAvailable = true; break;
 case 1: car.name = "Hyundai Tucson"; car.IsAvailable = true; break;
 case 2: car.name = "Audi Q7"; car.IsAvailable = false; break;
 case 3: car.name = "Tesla Cybertruck"; car.IsAvailable = true; break;
 case 4: car.name = "Mercedes-Benz GLE"; car.IsAvailable = false; break;
 case 5: car.name = "Volkswagen Jetta"; car.IsAvailable = true; break;
 case 6: car.name = "BMW 3Series\t"; car.IsAvailable = true; break;
 case 7: car.name = "Chevrolet Equinox"; car.IsAvailable = true; break;
 case 8: car.name = "Ford Mustang"; car.IsAvailable = true; break;
 case 9: car.name = "Toyota RAV4"; car.IsAvailable = true; break;
case 10: car.name = "Bugatti Chiron"; car.IsAvailable = true; break;
 case 11: car.name = "Hyundai Elantra"; car.IsAvailable = true; break;
 case 12: car.name = "Audi R8\t"; car.IsAvailable = true; break;
 case 13: car.name = "Tesla Model S"; car.IsAvailable = false; break;
 case 14: car.name = "Mercedes-Benz GLC"; car.IsAvailable = true; break;
 case 15: car.name = "Volkswagen Atlas"; car.IsAvailable = false; break;
 case 16: car.name = "BMW 7Series\t"; car.IsAvailable = true; break;
 case 17: car.name = "Chevrolet Cavaro"; car.IsAvailable = false; break;
 case 18: car.name = "Ford F-150"; car.IsAvailable = true; break;
 case 19: car.name = "Toyota Prius"; car.IsAvailable = true; break;
 default: car.name = "Unknown Car";
 }
 car.DailyRent = 400 + ((i%2+1)*i*40)-((i%2)*i*15);
 car.Brand = "Brand" + to_string(distribution(gen));
 cars.push_back(car);
 }
 cout<<"--------------Welcome to Car Rental System :)--------------\n\n";
 cout<<"Please enter your designation:\n1 : Manager\n2 : Customer\n3 : Employee\n";
 int des;
 cin>>des;
 if(des==1){
 Manager_functions man;
 if(man.verify()==1) cout<<"--------------Welcome dear Manager--------------\n";
 else{
 cout<<"--------------Wrong manager's code entered--------------\n";
 return 0;
 }
 man.Proceed();
 }
 else if(des==2){
 Customer_functions cus;
 int choice3;
 cout<<"1 : Create a new profile\n2 : Login to your account\n";
 cin>>choice3;
 if(choice3==1){
 string name;
 string password;
 cout<<"Enter your first name\n";
 cin>>name;
 cout<<"Create a password\n";
 cin>>password;
 CustomerDatas new_cust;
 new_cust.customerID=customers.size();
 new_cust.password=password;
 new_cust.Customerinput1=10;
 new_cust.FinesDue=0;
 new_cust.RentedCars={};
 customers.push_back(new_cust);
 cout<<"--------------Your profile has been created successfully--------------\n\n";
 cout<<"Your customerID is : "<<customers.size()-1;
 cout<<"\nPlease login with the provided details\n\n";
 }
 if(cus.GEtIdentity()==0) return 0;
 if(cus.verify()==0) return 0;
 cus.Proceed();
 }
 else if(des==3){
 Employee_functions emp;
 int choice3;
 cout<<"1 : Create a new profile\n2 : Login to your account\n";
 cin>>choice3;
 if(choice3==1){
 string name;
 string password;
 cout<<"Enter your first name\n";
 cin>>name;
 cout<<"Create a password\n";
 cin>>password;
 EmployeeData new_empl;
 new_empl.employeeID=employees.size();
 new_empl.password=password;
 new_empl.employeeinput1=10;
 new_empl.FinesDue=0;
 new_empl.RentedCars={};
 employees.push_back(new_empl);
 cout<<"--------------Your profile has been created successfully--------------\n\n";
 cout<<"Your employeeID is : "<<employees.size()-1;
 cout<<"\nPlease login with the provided details\n\n";
 }
 if(emp.GEtIdentity()==0) return 0;
 if(emp.verify()==0) return 0;
 emp.Proceed();
}
else cout<<"--------------Invalid designation entered--------------\n";
}