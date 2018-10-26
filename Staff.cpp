#include "Staff.h"
#include "Customer.h"
#include "Functions.h"
#include "Log.h"
#include <iostream>
#include <string>
#include <curses.h>
#include <iomanip>

using namespace std;

extern vector<Book> Bookvector;
extern vector<User> Uservector;
extern vector<Log> IssuedBookvector;
extern string loggedinUser;

void Staff::returnBookInterface()
{
    string username, isbn;

    int i, retbook;
    cout << "\n\t*********** LIBRARY MANAGEMENT SYSTEM - Staff Interface ***********\n";
    cout << "\n\t\t>>Return Book Interface \n";
    cout << "\n\t\tEnter ISBN number of Book : ";
    cin >> isbn;
    cout << "\n\t\tEnter Username of Book Borrower : ";
    cin >> username;

    //system("clear");
    retbook = returnIssuedBook(isbn, username);

    if (retbook == 1)
    {
        cout << "\t\tBook Returned Successfully: :)\n\n";
    }
    else
    {

        cout << "\t\tThe book you are trying to return is not found in log :(\n\n";
    }

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
    else if (i == 4)
    {
        exit(0);
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
    int ret = 0;

    for (int i = 0; i < IssuedBookvector.size(); i++)
    {

        if (IssuedBookvector[i].getIsbn() == isbn && IssuedBookvector[i].getUsername() == username && IssuedBookvector[i].getstatus() == "checked-out")
        {

            IssuedBookvector[i].setstatus("returned");
            ret = 1;
            return ret;
        }
    }

    return ret;
}

void Staff::staffInterface()
{
    int i;
    cout << "\n\t*********** LIBRARY MANAGEMENT SYSTEM - Staff Interface ***********\n";
    cout << "\n\t\t>>Please Choose Any Option \n";
    cout << "\n\t\t1.Books Availability\n\n\t\t2.Return Issued Book\n\n\t\t3.View Checkout Log\n\n\t\t4.Log out\n\n\t\t5.Close Application\n";
    cout << "\n\t\tEnter your choice : ";
    cin >> i;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "................";
        cin >> i;
    }

    if (i == 1)
    {
        system("clear");
        //getch();
        viewBooksAvailability();
    }
    else if (i == 2)
    {
        system("clear");
        //getch();
        returnBookInterface();
    }
    else if (i == 3)
    {
        system("clear");
        viewlog();
    }
    else if (i == 4)
    {
        system("clear");
        Functions functions;
        functions.loginInterface();
    }
    else if (i == 5)
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

void Staff::viewBooksAvailability()
{

    int i;
    //Functions functions;
    cout << "Books Availability in the System:" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|       ISBN       |             Name            |      Author      |           Information           |   Availability    |" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
    for (auto i : Bookvector)
    {

        cout << "|" << setw(18) << i.getIsbn() << "|" << setw(29) << i.getName() << "|"
             << setw(18) << i.getAuthor() << "|" << setw(33) << i.getInformation() << "|" << setw(19) << i.getCount() << "|" << endl;
    }
    cout << "--------------------------------------------------------------------------------------------------------------------------\n\n"
         << endl;

    cout << "1.Staff Home Interface\t\t\t 2. Log out\t\t\t3. Close Application\n\n";
    cout << "Choose the option: ";
    cin >> i;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << ".........";
        cin >> i;
    }

    if (i == 1)
    {
        system("clear");
        //getch();
        staffInterface();
    }

    else if (i == 2)
    {
        system("clear");
        Functions functions;
        functions.startup();
    }
    else if (i == 3)
    {
        exit(0);
    }
    else
    {
        cout << "\n\t\tPlease enter correct option :(\n";
        getch();
        system("clear");
        viewBooksAvailability();
    }
}

void Staff::viewlog()
{

    int i;
    cout << "This is the details:" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|     Username     |       ISBN       |             BookName            |      IssueDate      |        ReturnDate       |      Status      |" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (auto i : IssuedBookvector)
    {

        cout << "|" << setw(18) << i.getUsername() << "|" << setw(18) << i.getIsbn() << "|" << setw(33) << i.getBookname() << "|"
             << setw(21) << i.getIssueDate() << "|" << setw(25) << i.getReturnDate() << "|" << setw(18) << i.getstatus() << "|" << endl;
    }
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------\n\n"
         << endl;

    cout << "1..Staff Interface\t\t\t 2. Log out\t\t\t3. Close Application\n\n";
    cout << "Choose the option: ";
    cin >> i;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << ".........";
        cin >> i;
    }
    if (i == 1)
    {
        system("clear");
        //getch();
        staffInterface();
    }

    else if (i == 2)
    {
        system("clear");
        Functions functions;
        functions.startup();
    }
    else if (i == 3)
    {
        exit(0);
    }
    else
    {
        cout << "\n\t\tPlease enter correct option :(\n";
        getch();
        system("clear");
        viewlog();
    }
}