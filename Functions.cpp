#include "Functions.h"
#include "Staff.h"
#include "Customer.h"

#include <iostream>
#include <string>
#include <curses.h>

using namespace std;

Staff staff;
Customer customer;

int Functions::login(string username, string passwd){

    
    return 10;

}

int Functions::registration(){




}

void Functions::LoadUserData(){


    
    //Uservector is defined globally, and we will try to use that same vetor all the time.
    //Globaldata::Uservector;


    
}

void Functions::LoadBookData(){

    //Bookvector is also a global variable and this method will add the information in the Bookvector, latter we will use these two vectors as and when required
    //Globaldata::Bookvector;

}

void Functions::loginInterface(){

    //this is login Interface for all the entity of system
    string username;
    string passwd;
    int status;

    cout << "\n\t*********** LIBRARY MANAGEMENT SYSTEM ***********\n";
    //cout << "\n\t\t>>This is Login Interface \n";
    cout << "\n\t\tUsername:";
    cin >> username;
    cout << "\n\t\tPassword:";
    cin >> passwd;

    status = login(username,passwd);

    status = 9;
    if(status == 1){
            //only one Manager, there is no interface for manager at this moment.
            //manager's login information will be there in the User.txt

    }
    if (status ==2){

        system("clear");
        staff.staffInterface();
    }

    if(status = 3){

        system("clear");
        customer.customerInterface();
    }
    else{

        system("clear");
        cout << "The identity of user is not defined";
        loginInterface();

    }





}

void Functions::registrationInterface(){


}

void Functions::startup(){

    int i;
    cout << "\n\t*********** LIBRARY MANAGEMENT SYSTEM ***********\n";
    cout << "\n\t\t>>Please Choose Any Option \n";
    cout << "\n\t\t1.Login\n\n\t\t2.Register\n\n\t\t3.Close Application\n";
    cout << "\n\t\tEnter your choice : ";
    cin >> i;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "\n\t\tPlease enter correct option :(";
        cin >> i;
    }

    if (i == 1)
    {
        //system("cls");
        //clear();
        system("clear");
        //getch();
        loginInterface();
    }
    else if (i == 2)
    {
        system("clear");
        //getch();
        registrationInterface();
    }

    else if (i == 3)
    {
        exit(0);
    }
    else
    {
        cout << "\n\t\tPlease enter correct option :(";
        getch();
        system("clear");
        startup();
    }

}

