//======= Employee Payroll Management System ===========================

#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include <conio.h>
#include <graphics.h>

//==================================================================

class Employee // Main Class creation
{
private: char name[20], department[20], designation[20];
double basicPay; int employeeId;
public: // Constructor
Employee(const char *empName, const char *empDept, const char *empDesig,
double empPay, int empId)

{
strcpy(name, empName); strcpy(department, empDept);
strcpy(designation, empDesig);
basicPay = empPay; employeeId = empId;
}

// Getter methods

int getEmployeeId() { return employeeId; }
char *getName() { return name; }
char *getDepartment() { return department; }
char *getDesignation() { return designation; }
const double getBasicPay() { return basicPay; }

// Setter methods

void setEmployeeId(int empId) { employeeId = empId; }
void setBasicPay(double empPay) { basicPay = empPay; }
};
//=================================================================

// Function to get employee data from the user

void getEmployeeData(char *name, char *department, char *designation, double
&basicPay, int &employeeId)

{
clrscr(); clearviewport();
rectangle(1,1,639,479); rectangle(5,5,635,475);
outtextxy(50, 102,"Enter employee ID:"); gotoxy(35,8);
cin >>employeeId; cin.ignore();
outtextxy(50, 132,"Enter employee name:"); gotoxy(40,10);
cin.getline(name, 20);
setcolor(LIGHTRED);
outtextxy(50, 160, "Select department");
outtextxy(50, 192, "1. Finance, 2. Sales, 3. HR, 4. IT"); gotoxy(60,14);
int departmentChoice;
cin >>departmentChoice; cin.ignore(); // To clear the input buffer
switch (departmentChoice)

{
case 1: strcpy(department, "Finance"); break;
case 2: strcpy(department, "Sales"); break;
case 3: strcpy(department, "HR"); break;
case 4: strcpy(department, "IT"); break;
default: outtextxy(50, 190, "Invalid department choice");
outtextxy(50, 220, "Setting department to Unknown.");
strcpy(department, "Unknown"); break;
}

setcolor(LIGHTGREEN);
outtextxy(50, 220, "Select designation ");
outtextxy(50, 250, "1. Executive, 2. Manager");
outtextxy(50, 280, "3. Accountant, 4. Asst. Manager"); gotoxy(60,19);
int designationChoice;
cin >>designationChoice; cin.ignore(); // To clear the input buffer
switch (designationChoice)

{
case 1: strcpy(designation, "Executive"); break;
case 2: strcpy(designation, "Manager"); break;
case 3: strcpy(designation, "Accountant"); break;
case 4: strcpy(designation, "Asst. Manager"); break;
default: outtextxy(50, 190, "Invalid designation choice");
outtextxy(50, 220, "Setting designation to Unknown.");
strcpy(designation, "Unknown"); break;
}
setcolor(LIGHTBLUE); outtextxy(50, 310, "Enter Basic pay: "); gotoxy(32,21);
cin >>basicPay; cin.ignore(); // To clear the input buffer
}
//=================================================================
// Function to calculate salary details
void calculateSalary(Employee &employee, double &bp, double &da, double &hra,
double &grossPay, double &pf, double &pt, double &netPay)
{ bp = employee.getBasicPay(); // Get basic pay
da = employee.getBasicPay() * 0.1; // da = 10% of basic pay
hra = employee.getBasicPay() * 0.15; // hra = 15% of basic pay
grossPay = employee.getBasicPay() + da + hra; pt = 200;
pf = employee.getBasicPay() * 0.12; // pf = 12% of basic pay
netPay = grossPay - (pf + pt); // Net_pay = Gross_pay - Deductions
}




//=================================================================

// Function to display employee details

void displayEmployeeDetails(Employee &employee)
{
cout <<"=========================================="<<endl;
cout <<"n | Employee ID : "<<employee.getEmployeeId() <<endl;
cout <<"n | Name : "<<employee.getName() <<endl;
cout <<"n | Department : "<<employee.getDepartment() <<endl;
cout <<"n | Designation : "<<employee.getDesignation() <<endl;
cout <<"n | Basic Pay : "<<employee.getBasicPay() <<endl;
cout <<"=========================================="<<endl;
}
//=================================================================
// Function to display salary details
void displaySalaryDetails(double bp, double da, double hra, double grossPay, double pf,
double pt, double netPay)
{ clrscr(); clearviewport();
rectangle(1,1,639,479); rectangle(5,5,635,475);
cout <<"n ============== Salary Details =============== "<<endl;
cout <<"n ============================================= "<<endl;
cout <<"n | Basic Pay of Salary (BP) : "<<bp <<endl;
cout <<"n | Dearness Allowance (DA=>10% of BP) : "<<da <<endl;
cout <<"n | HR Allowance (HRA=>15% of BP) : "<<hra <<endl;
cout <<"n | Gross Pay (GP = BP+DA+HRA) : "<<grossPay <<endl;
cout <<"n | Provident Fund (PF=>12% of BP) : "<<pf <<endl;
cout <<"n | Professional Tax (PT = 200) : "<<pt <<endl;
cout <<"n | Net Salary Pay (NP = GP-(PF+PT)) : "<<netPay <<endl;
cout <<"n ============================================= "<<endl;
}
//=================================================================
// Function to load employee data from a file
void loadEmployeeData(Employee *employees[], int &employeeCount)
{
ifstream inFile("employee.txt");
if (inFile.fail())
{ cout <<"Unable to open the file."<<endl;
 }
else
{
int employeeId; double basicPay;
char name[20], department[20], designation[20];
while (inFile >>employeeId)
{
inFile.ignore();
inFile.getline(name, 20);
inFile.getline(department, 20);
inFile.getline(designation, 20);
inFile >>basicPay; inFile.ignore();
employees[employeeCount++] = new Employee(name, department, designation,
basicPay, employeeId);
}
inFile.close(); cout <<"Employee records loaded Successfully!"<<endl;
}
}

//=================================================================

// Function to save employee data to a file

void saveEmployeeData(Employee &employee)
{
ofstream outFile("employee.txt", ios::app);
if (outFile.fail())
{ outtextxy(100, 150, "Unable to open the file."); }
else {
outFile <<employee.getEmployeeId() <<endl;
outFile <<employee.getName() <<endl;
outFile <<employee.getDepartment() <<endl;
outFile <<employee.getDesignation() <<endl;
outFile <<employee.getBasicPay() <<endl;
outFile.close();
outtextxy(80,360, "Employee record saved successfully!");
}
}

//=================================================================

// Function to calculate and display salary details for an employee

void calculateAndDisplaySalary(Employee &employee)
{
double bp, da, hra, grossPay, pf, pt, netPay;
calculateSalary(employee, bp, da, hra, grossPay, pf, pt, netPay);
displaySalaryDetails(bp, da, hra, grossPay, pf, pt, netPay);
}
//=================================================================

// Function for Menu Driven using switch case with options

void MenuFunction()
{
Employee *employees[50];
int employeeCount = 0, choice;
loadEmployeeData(employees, employeeCount);
do {
clrscr(); clearviewport();
rectangle(1,1,639,479); rectangle(5,5,635,475);
setcolor(YELLOW); settextstyle(7,0,2);
outtextxy(50, 50, "=========================");
outtextxy(100, 75,"MENU DRIVEN ");
outtextxy(50, 100, "=========================");
setcolor(LIGHTGREEN);
outtextxy(50, 130, "1. Create Employee Record");
outtextxy(50, 160, "2. Alter Existing Record");
outtextxy(50, 190, "3. View Existing Records");
outtextxy(50, 220, "4. Calculate the Salary ");
outtextxy(50, 250, "5. Exit the Program ");
setcolor(YELLOW);
outtextxy(50, 280, "=========================");
setcolor(CYAN); outtextxy(50, 312, "Enter your choice: ");
gotoxy(34,21); cin >>choice; cin.ignore(); // To clear the input buffer
switch (choice)
{
case 1: { char name[100], department[100], designation[100];
double basicPay; int employeeId; clrscr(); clearviewport();
getEmployeeData(name, department, designation, basicPay, employeeId);
employees[employeeCount++] = new Employee(name, department,
designation, basicPay, employeeId);
saveEmployeeData(*employees[employeeCount - 1]); break; }
case 2: { clrscr(); int recordIndex, alterChoice; clearviewport();
rectangle(1,1,639,479); rectangle(5,5,635,475);
cout <<"n Enter the index of the record to alter (0-"<<employeeCount - 1
<<"): ";
cin >>recordIndex; cin.ignore(); // To clear the input buffer
if (recordIndex >= 0 && recordIndex < employeeCount)
{
clrscr(); clearviewport(); setcolor(LIGHTGREEN);
rectangle(1,1,639,479); rectangle(5,5,635,475);
outtextxy(50, 80, "Alter Existing Record ");
outtextxy(50, 110, "============================");
outtextxy(50, 140, "1. Promote Employee");
outtextxy(50, 170,"2. Demote Employee");
outtextxy(50, 200, "3. Change Name");
outtextxy(50, 230, "4. Change Employee ID");
outtextxy(50, 260, "5. Change Basic Pay"); setcolor(CYAN);
outtextxy(50, 350, "Enter choice: "); gotoxy(40,20); cin >>alterChoice;
clearviewport(); cin.ignore(); // To clear the input buffer
switch (alterChoice)
{
case 1:
{
 // Promote Employee designation

char designation[20]; int newDesignChoice;
outtextxy(50, 50, "Enter new designation ");
outtextxy(50, 80, "==========================");
outtextxy(50, 110, "1. Executive ");
outtextxy(50, 140, "2. Manager ");
outtextxy(50, 170, "3. Accountant ");
outtextxy(50, 210, "4. Asst. Manager ");
outtextxy(50, 240, "=========================");
outtextxy(50, 270, "Choose one option "); gotoxy(35,20);
cin >>newDesignChoice;
cin.ignore(); // To clear the input buffer
switch (newDesignChoice)
{
case 1: strcpy(designation, "Executive"); break;
case 2: strcpy(designation, "Manager"); break;
case 3: strcpy(designation, "Accountant"); break;
case 4: strcpy(designation, "Asst. Manager"); break;
default: outtextxy(50, 300, "Invalid designation choice.");
outtextxy(50, 330, "Keeping the existing designation.");
strcpy(designation, employees[recordIndex]->getDesignation()); break;
}
strcpy(employees[recordIndex]->getDesignation(), designation);
outtextxy(50, 300, "Employee promoted successfully!"); break;
}
case 2:
{
 // Demote Employee designation
char designation[20]; int newDesignationChoice;
outtextxy(50, 50, "Enter new designation ");
outtextxy(50, 80, "===========================");
outtextxy(50, 110, "1. Executive ");
outtextxy(50, 140, "2. Manager ");
outtextxy(50, 170, "3. Accountant ");
outtextxy(50, 200, "4. Asst. Manager ");
outtextxy(50, 230, "===========================");
outtextxy(50, 270, "Choose one option "); gotoxy(30,20);
cin >>newDesignationChoice;
cin.ignore(); // To clear the input buffer
switch (newDesignationChoice)
{
case 1: strcpy(designation, "Executive"); break;
case 2: strcpy(designation, "Manager"); break;
case 3: strcpy(designation, "Accountant"); break;
case 4: strcpy(designation, "Asst. Manager"); break;
default: outtextxy(50, 300, "Invalid designation choice.");
outtextxy(50, 330, "Keeping the existing designation.");
strcpy(designation, employees[recordIndex]->getDesignation()); break;
}
strcpy(employees[recordIndex]->getDesignation(), designation);
outtextxy(50, 300, "Employee demoted successfully!"); break;
}
case 3:
{
 // Change of Employee Name
char name[20]; setcolor(CYAN);
outtextxy(50, 102, "Enter new name: "); gotoxy(32,8);
cin.getline(name, 20);
strcpy(employees[recordIndex]->getName(), name); setcolor(YELLOW);
outtextxy(50, 150, "Name is been Altered!"); break;
}
case 4:
{
 // Change of Employee ID
int employeeId; setcolor(CYAN);
outtextxy(50, 102, "Enter new employee ID: "); gotoxy(42,8);
cin >>employeeId; cin.ignore(); // To clear the input buffer
employees[recordIndex]->setEmployeeId(employeeId); setcolor(YELLOW);
outtextxy(50, 150, "employee ID been Altered!"); break;
}
case 5:
{ 
// Change of Basic Pay
double basicPay; setcolor(CYAN);
outtextxy(50, 102, "Enter new basic pay: "); gotoxy(42,8);
cin >>basicPay; cin.ignore(); // To clear the input buffer
employees[recordIndex]->setBasicPay(basicPay); setcolor(YELLOW);
outtextxy(50, 150, "Basic pay been Altered!"); break;
}
default: outtextxy(50, 150, "Invalid alter choice!"); break;
}
ofstream outFile("employee.txt");
if (outFile.fail()) { outtextxy(50, 100, "Unable to open the file."); }
else
{
for (int i = 0; i < employeeCount; i++)
{
outFile <<employees[i] -> getEmployeeId() <<endl;
outFile <<employees[i] -> getName() <<endl;
outFile <<employees[i] -> getDepartment() <<endl;
outFile <<employees[i] -> getDesignation() <<endl;
outFile <<employees[i] -> getBasicPay() <<endl;
}
outFile.close();
outtextxy(50, 200, "Record altered and saved successfully!");
}
} else { cout <<"Invalid record index!"<<endl; } break;
}
case 3: clrscr(); clearviewport();
cout <<"\n Existing Records:\n";
cout <<"-------------------------------------------"<<endl;
cout <<"| Index | Employee Details |"<<endl;
cout <<"-------------------------------------------"<<endl;
for (int i = 0; i < employeeCount; i++)
{
cout <<"| "<<i <<"|"<<endl;
displayEmployeeDetails(*employees[i]);
cout <<"-------------------------------------------"<<endl;
getch();
} break;
case 4: clrscr(); clearviewport();
int recordIndex; rectangle(1,1,639,479); rectangle(5,5,635,475);
cout <<"\n Enter the index of the record to calculate salary for (0-"<<
employeeCount - 1 <<"): ";
cin >>recordIndex;
cin.ignore(); // To clear the input buffer
if (recordIndex >= 0 &&recordIndex < employeeCount)
{ calculateAndDisplaySalary(*employees[recordIndex]); }
else { cout <<"Invalid record index!"<<endl; } break;
case 5: clrscr(); clearviewport();
rectangle(1,1,639,479); rectangle(5,5,635,475);
outtextxy(50, 60, "==============**(o)**================ "); setcolor(WHITE);
outtextxy(50, 90, "=> ===== (o) ==== (.) ==== (o) ===== "); outtextxy(460, 90, "<=");
outtextxy(50, 120, "=> ==>>THANK YOU <<== "); outtextxy(460, 120, "<=");
setcolor(MAGENTA); outtextxy(50, 150, "=> "); outtextxy(460, 150, "<=");
outtextxy(50, 180, "=> ==> VISIT AGAIN <== "); outtextxy(460, 180, "<=");
setcolor(YELLOW); outtextxy(50, 210, "=> "); outtextxy(460, 210, "<=");
outtextxy(50, 240, "=> ===== HAVE A NICE DAY ===="); outtextxy(460, 240, "<=");
setcolor(CYAN); outtextxy(50, 270, "==============**(o)**================ ");
outtextxy(50, 340, "Exiting the program..."); getch(); break;
default: outtextxy(50, 340, "Invalid choice!"); break;
}
outtextxy(200, 400, "Press any key to Continue..."); setcolor(YELLOW);
settextstyle(4,0,3); outtextxy(300,360,"See You Again"); getch();
} while (choice != 5);

// Free memory allocated for employee objects

for (int i = 0; i < employeeCount; i++) { delete employees[i]; }

}

//=================================================================
void login() // Function login to the program
{
 char ch; char uname[12]; clrscr();
z: settextstyle(8,0,1); clearviewport();
rectangle(1,1,639,479); rectangle(5,5,635,475); setcolor(LIGHTCYAN);
outtextxy(50, 80,"=== Enter Login Credentials ===");
outtextxy(50, 110, "======================================");
outtextxy(50, 132,"Enter 1 for User-1, 2 for User-2");
gotoxy(60,10); cin >>ch;
switch(ch)
{
case '1': cin.ignore(); // To clear the input buffer
outtextxy(50, 164, "Enter username: "); gotoxy(32,12);
cin.getline(uname, 12);
char *pass1 = "1969", *ppass1;
outtextxy(50, 196, "Enter password: ");
ppass1 = getpass("\n"); gotoxy(32,14); cout <<"*******";
if (strcmp(uname, "kushal") == 0 &&strcmp(pass1, ppass1) == 0)
{ setcolor(LIGHTGREEN); outtextxy(50, 240, "Login Successfull ");
getch(); MenuFunction(); break; }
outtextxy(50, 240, "Wrong Credentials"); break;
case '2': cin.ignore(); // To clear the input buffer
outtextxy(50, 164, "Enter username: "); gotoxy(32,12);
cin.getline(uname, 12);
char *pass2 = "2004", *ppass2;
outtextxy(50, 196, "Enter password: ");
ppass2 = getpass("\n"); gotoxy(32,14); cout <<"*******";
if (strcmp(uname, "abhishek") == 0 &&strcmp(pass2, ppass2) == 0)
{ setcolor(LIGHTGREEN); outtextxy(50, 240, "Login Successfull ");
getch(); MenuFunction(); break; }
outtextxy(50, 240, "Wrong Credentials"); break;
default: outtextxy(50, 250, "Invalid User selection. Try Again !!");
getch(); goto z;
}
}
//=================================================================
void build_1() //Buidling-1 design
{
setfillstyle(5, LIGHTBLUE); outtextxy(64,208,"BUILDING-1");
rectangle(59, 196, 152, 475);
rectangle(79, 217, 132, 454); floodfill(80,215,WHITE);
rectangle(79, 270, 132, 280); floodfill(80,279,WHITE);
rectangle(79, 330, 132, 340); floodfill(80,339,WHITE);
rectangle(79, 390, 132, 400); floodfill(80,399,WHITE);
line(152, 196, 168, 203); line(168, 203, 168, 475);
}
//=================================================================
void build_2() //Building-2 design
{
setfillstyle(8, LIGHTGREEN); outtextxy(191,130,"BUILDING-2");
rectangle(186, 117, 296, 475);
rectangle(206, 150, 276, 454); floodfill(207,149,WHITE);
rectangle(206, 210, 276, 220); floodfill(207,219,WHITE);
rectangle(206, 270, 276, 280); floodfill(207,279,WHITE);
rectangle(206, 330, 276, 340); floodfill(207,339,WHITE);
rectangle(206, 390, 276, 400); floodfill(207,399,WHITE);
line(296, 117, 315, 126); line(315, 126, 315, 475);
}
//=================================================================
void star() //Drawing ninja star:
{
line(547,29,557,69); line(557,69,597,79);line(597,79,557,89);
line(557,89,547,129); line(547,129,537,89);line(537,89,497,79);
line(497,79,537,69);line(537,69,547,29);line(547,29,547,129);line(497,79,597,79);
line(557,69,537,89);line(537,69,557,89);
rectangle(330,300,635,475);
circle(547,79,50);setfillstyle(SOLID_FILL,LIGHTGRAY); floodfill(547,97,WHITE);
circle(547,79,60);setfillstyle(SOLID_FILL,LIGHTGRAY); floodfill(597,97,WHITE);
}

//=================================================================

void InitialFrame()
{
//Adding Initial frame Information
line(0,479,637,479); settextstyle(10,0,2);
rectangle(1,1,639,479); rectangle(5,5,635,475);
outtextxy(15,10, "SRINIVAS UNIVERSITY..."); settextstyle(1,0,1);
outtextxy(120,60, "BENGALURU CAMPUS");
settextstyle(2,1,4); build_1(); build_2(); star();
settextstyle(1,0,5); setcolor(CYAN);
outtextxy(350, 150, "Welcome to");
outtextxy(350, 210, "PROJECT");

//Drawing AK logo
{
circle(400,400,50);setcolor(LIGHTGRAY);
circle(400,400,45);

settextstyle(10,0,4);outtextxy(365,360,"AK");
settextstyle(1,0,3); setcolor(YELLOW);
outtextxy(470,315, "Prepared by");
}
{
setcolor(WHITE);
outtextxy(470,317,"_____________");
}
settextstyle(2,0,6);setcolor(WHITE);
outtextxy(470,353, "Kushal "); outtextxy(490,370,"SU23BC003");
outtextxy(470,400, "Abhishek "); outtextxy(490,420,"SU23BC001"); getch();
}

//=================================================================

void main() // Main function declaration
{

clrscr(); /* request auto detection */
int gdriver = DETECT, gmode, errorcode;
/* initialize graphics mode */
initgraph(&gdriver, &gmode, "C:\\TurboC3\\BGI");
/* read result of initialization */
errorcode = graphresult();
if (errorcode != grOk) /* an error occurred */

{
cout <<"Graphics error: "; grapherrormsg(errorcode);
cout <<"\n Press any key to halt:";
}

InitialFrame(); // To display start Frame
// DFunction to login
login(); getch();

}
