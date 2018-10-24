#include "Functions.h"
#include "Staff.h"
#include "Customer.h"

#include <iostream>
#include <string>
#include <curses.h>
#include <fstream>

using namespace std;

Staff staff;
Customer customer;

int Functions::login(string username, string passwd)
{

    //by default transferring to the customer interface
    int status = 3;

    return status;
}

int Functions::registration(string name, string username, string password)
{

    //just checking if the username is not available then it should redirect to registrationInterface()
    int i = 0;

    return i;
}

void Functions::LoadUserData()
{

    //Uservector is defined globally, and we will try to use that same vetor all the time.
    //Globaldata::Uservector;
    User olduser;
    string str;

    vector<User> Uservector;

    ifstream fin("User.txt"); // Open and read User.txt
    if (!fin)
    { // If can't open
        cerr << "User.txt can't open" << endl;
        abort(); // Exit
    }
    while (getline(fin, str))
    {
        size_t i = str.find(" ");          // Find fisrt spacebar
        olduser.setname(str.substr(0, i)); // Divide str by spacebar and get username
        str = str.substr(i + 1);

        i = str.find(" ");                     // Find second spacebar
        olduser.setusername(str.substr(0, i)); // Divide str by spacebar and get password
        str = str.substr(i + 1);

        i = str.find(" ");                     // Find second spacebar
        olduser.setpassword(str.substr(0, i)); // Divide str by spacebar and get password

        olduser.setStatus(str.substr(i+1)); // Divide str by spacebar and get status

        Uservector.push_back(olduser); // Add to lib.UserArray
    }
    fin.close(); // Close User.txt

    cout << "printing the Uservector\n\n";
    for (auto i : Uservector)
    {

        cout << i.getname() + "\t\t" + i.getusername() + "\t\t" + i.getpasswd() + "\t\t" + i.getStatus() +"\n\n";
    }
}

void Functions::LoadBookData()
{

    //Bookvector is also a global variable and this method will add the information in the Bookvector, latter we will use these two vectors as and when required
    //Globaldata::Bookvector;
}

void Functions::loginInterface()
{

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

    status = login(username, passwd);

    //status = 9;
    if (status == 1)
    {
        //only one Manager, there is no interface for manager at this moment.
        //manager's login information will be there in the User.txt
    }
    if (status == 2)
    {

        system("clear");
        staff.staffInterface();
    }

    if (status = 3)
    {

        system("clear");
        customer.customerInterface();
    }
    else
    {

        system("clear");
        cout << "The identity of user is not defined";
        loginInterface();
    }
}

void Functions::registrationInterface()
{

    int registerstatus;
    string userID, password, name;
    cout << "\n\t*********** NEW  USER  REGISTERATION  ***********\n";
    cout << "\n\t\t>>Please provide the following details to Register \n";
    cout << "\n\t\tName:";
    cin >> name;
    cout << "\n\t\tEnter desired User ID:";
    cin >> userID;
    cout << "\n\t\tEnter password:";
    cin >> password;

    registerstatus = registration(name, userID, password);

    if (registerstatus == 1)
    {
        system("clear");
        cout << "\n\t\tThank you for registering, Please login into the system\n";
        loginInterface();
    }
    else
    {
        system("clear");
        cout << "\n\t\tRequested Username is not available in the system, please try again... :(\n";
        getch();
        //system("CLS");
        //clear();
        registrationInterface();
    }
}

void Functions::startup()
{

    int i;
    cout << "\n\t*********** LIBRARY MANAGEMENT SYSTEM - Startup Interface ***********\n";
    cout << "\n\t\t>>Please Choose Any Option \n";
    cout << "\n\t\t1.Login\n\n\t\t2.Register\n\n\t\t3.Close Application\n";
    cout << "\n\t\tEnter your choice : ";
    cin >> i;
    while (cin.fail())
    {
        cout << "\n\t\tEnter your choice :";
        cin.clear();
        cin.ignore();
        //getch();
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
