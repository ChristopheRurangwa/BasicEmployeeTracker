/*
Name: Christophe Rurangwa
Date: 7/26/2020
Program Name: Employee TRACKER
Description of what the program does: The employee TRACKER tracks the employee performance monthly.
It allows the employer to give feedback of employee performance. It list task of employee day-to-day, and
it list hours to work and allows to view employee request.
*/

#include<iostream>
#include<string>
#include<math.h>
#include<stdlib.h>
#include <fstream>


using namespace std;

const int ROW=2;

const int COL=3;


int menu();

int person_Information(string name);

int performanceReport(double hours, string employeNam, double rating, int days);

int taskListAndHoursWorked(string line);

int employRequetS(string req[][COL] );

int giveFeedBack(string message);




int main() {
    string name;
    string message;
    cout << "PLEASE ENTER FULL NAME TO VERIFY IDENTITY.\n";

    getline(cin, name);

    cout << "Welcome to Employee TRACKER " + name << "\n\n";
    int numb;

    string req[ROW][COL]={{"Increase break time.", "Fresh water in the office.","Coffe machine."},
                   {"New computers.", "More vision boards.","More vacation days."}
    };

    string lastName;
    char charr;
    do{
    menu();
    string line;


    double hours,rating;
    int days;
    string employeNam;
    cin>>numb;
    switch (numb) {
        case 1:
            cout<<"Enter Last name of employee.\n\n";
            cin>>lastName;
            person_Information( lastName);
            break;
        case 2:
            cout<<"Enter employee LAST NAME. \n";

            cin>>employeNam;

            cout<<"Enter hours worked per day.\n";
            cin>>hours;

            cout<<"Enter rating range(between 1 to 5).\n";
            cin>>rating;

            cout<<"How many days did "<<employeNam<< " work? \n";
            cin>>days;

            performanceReport( hours, employeNam, rating,days);

            break;

        case 3:

            taskListAndHoursWorked( line);
            break;

        case 4:




            employRequetS(req);
            break;
        case 5:

            giveFeedBack(message);
            break;
        case 6:

            system(EXIT_SUCCESS);
            break;
        default:

            cout<<"Please select the approriate choice from the menu.\n\n";


            break;


    }

    cout<<"Enter 'y' to continue or press other to exit.\n";
        cin>>charr;
        if (charr!='y'||charr!='Y'){
            system(EXIT_SUCCESS);
        }
    }while(charr=='y'||charr=='Y');

    return 0;
}
// prints out menu
int menu(){

    cout << "1. Employee Personal Information. "
            "\n2. Employee Perfomance. "
            "\n3. Tasks-list And Hours worked . "
            "\n4. Employee Requests. "
            "\n5. Give Feedback "
            "\n6. Press 6 to EXIT.\n";
    return 0;
}
// this function tell the employer all he needs to know about the employee, from name to DOB
int person_Information(string lastName){
    string firstName= "John";
    int yearBorn=1991;
    string dateOfBirth="4/January/1991";
    int currentyear=2020;
    int age=currentyear-yearBorn;
    string department="IT";
    string ssc="231-388-0000";
    string background="clean";
    cout<<"FULLNAME: "<<firstName<<" "<<lastName<<"\n";
    cout<<"Age: "<<age<<"\n";
    cout<< "Date of birth: "<<dateOfBirth<<"\n";
    cout<<"Social security: "<< ssc<<"\n";
    cout<<"Background: "<<background<<"\n";
    cout<<"Department: "<<department<<endl;



    return 0;
}
// this function give a report of employee performance and rating.
int performanceReport(double hours, string employeNam, double rating, int days){
    string good="****";
    string excellent="*****";
    string horrible="*";
    string bad="**";
    string unavalbl="Unavailable.\n";
    if(rating<=1){
        cout<<"RATINGS: Probation\n";
        cout<<employeNam<<" : "<<horrible<<"\n";

    }
    else if(rating>1&&rating<=2){
        cout<<"RATINGS: Needs improvement.\n";
        cout<<employeNam<<" : "<<bad<<"\n";

    }
    else if(rating>2&&rating<=4){
        cout<<" RATINGS: Goodstanding\n";
        cout<<employeNam<<" : "<<good<<"\n";

    }
    else if(rating>4 && rating<=5){
        cout<<"RATINGS: EXCELLENT\n";
        cout<<employeNam<<": "<<excellent<<"\n";

    }
    else cout<<employeNam<<" : "<<unavalbl;
    double maxHrs=10;
    double hrsPerWk=days*hours;
    if(hours<11){

    cout<<"\nThe hours worked weekly: "<<hrsPerWk<<" hours.\n";}
    else{cout<<"The maximum hours to work per day is "<<maxHrs<<" hours.\n";
    }

    if (hrsPerWk==50){cout<<employeNam<<" has satisfied the hours requirement, "<< hrsPerWk<<"hours\n";
            if(rating==5){
                cout<<employeNam<<" meets all requirements to be promoted.\n";
            }
            else{cout<<"Continue to motivate and encourage "<<employeNam<<".\n ";}
    }
    else if(hrsPerWk<=20&& rating<=1){
        cout<<"Give 3 verbal warnigs to "<<employeNam<< "if no change of hours, consider looking for another employee.\n";
    }
    else if (hrsPerWk<11)cout<<"Fire "<<employeNam<<" immediately!!!\n";


    return 0;

}
// gives a list of task and hours worked of employee.
int taskListAndHoursWorked(string line){
ifstream task("tasks.txt");
if(task.is_open()){
    while(getline(task,line)){
        cout<<line<<"\n\n";
    }

}
else cout<<"Sorry, the file did not open.";

    return 0;

}
// saved request list from employee
int employRequetS(string req[][COL]){
cout<<"\t\tHere is the Employees requests list:\n\n";

       for(int i=0;i<ROW;i++){
           for (int j=0;j<COL;j++) {
               cout<< req[i][j]<< " \n";
           }
       }

    return 0;

}
// Employer give feedback
int giveFeedBack(string message){

    cout<<"Give your feedback in a sentence, WHEN DONE PRESS ENTER."<<endl;

    cin>>message;

    getline(cin,message);

ofstream file("feedback.txt");
if(file.is_open()){

    file<<message;

    file.close();
    cout<<" Feedback saved. \n";
}
else cout<<"File did not open";




    return 0;

}


