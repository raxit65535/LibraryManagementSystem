#include "Staff.h"
#include "Customer.h"
#include "Functions.h"
#include <iostream>
#include <string>
#include <curses.h>

using namespace std;

void Staff::returnBookInterface()
{
    string username,isbn;

    int i, stauts;
    cout << "\n\t*********** LIBRARY MANAGEMENT SYSTEM - Staff Interface ***********\n";
    cout << "\n\t\t>>Return Book Interface \n";
    cout << "\n\t\tEnter ISBN number of Book : ";
    cin >> isbn;
    cout << "\n\t\tEnter Username of Book Borrower : ";
    cin >> username;

    system("clear");
    stauts = returnIssuedBook(isbn, username);

    cout << "\n\n\t\t 1.Return MoreBook \n\n\t\t 2.HomePage \n\n\t\t 3.Log out\n\n\t\t 4.Close Application";
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
        system("clear");
        returnBookInterface();
    }
    else if (i == 2)
    {
        system("clear");
        staffInterface();
    }

    else if (i == 3)
    {
        system("clear");
        Functions functions;
        functions.startup();
    }
    else
    {
        cout << "\n\t\tYou entered wrong choice, redirecting to the Book Return Interface :(";
        getch();
        system("clear");
        returnBookInterface();
    }
}

int Staff::returnIssuedBook(string isbn, string username)
{

    //write logic to retun the issued book here.
    int status = 1;
    cout << "Returning the issued Book";

    return status;
}

void Staff::staffInterface()
{
    int i;
    cout << "\n\t*********** LIBRARY MANAGEMENT SYSTEM - Staff Interface ***********\n";
    cout << "\n\t\t>>Please Choose Any Option \n";
    cout << "\n\t\t1.List Books\n\n\t\t2.Return Issued Book\n\n\t\t3.Log out\n\n\t\t4.Close Application\n";
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
        system("clear");
        //getch();
        Customer customer;
        customer.listbooks();
    }
    else if (i == 2)
    {
        int isbn;
        string username;
        system("clear");
        //getch();
        returnBookInterface();
    }

    else if (i == 3)
    {
        system("clear");
        Functions functions;
        functions.loginInterface();
    }
    else if (i == 4)
    {
        exit(0);
    }
    else
    {
        cout << "\n\t\tPlease enter correct option :(";
        getch();
        system("clear");
        staffInterface();
    }
}