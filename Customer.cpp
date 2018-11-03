#include "Customer.h"
#include "Functions.h"
#include "Log.h"
#include "DataAccess.h"
#include <iostream>
#include <iomanip>

using namespace std;

Functions functions;

extern vector<Book> Bookvector;
extern vector<User> Uservector;
extern vector<Log> IssuedBookvector;
extern string loggedinUser;
DataAccess dataAccessC;

int Customer::RequestBookLoan(std::string isbn)
{
    int bookloan = 0;
    bool isavailable = isAvailable(isbn);
    bool alreadyissued = isAlreadyissued(isbn);
    if (isavailable && !alreadyissued)
    {
        for (int i = 0; i < Bookvector.size(); i++)
        {
            if (Bookvector[i].getIsbn() == isbn)
            {
                Log newlog;
                time_t rawtime;
                struct tm *timeinfo;
                char buffer[80];

                time(&rawtime);

                timeinfo = localtime(&rawtime);

                strftime(buffer, sizeof(buffer), "%d-%m-%Y", timeinfo);
                std::string idate(buffer);

                rawtime +=60*60*24*40;

                timeinfo = localtime(&rawtime);

                strftime(buffer, sizeof(buffer), "%d-%m-%Y", timeinfo);
                std::string rdate(buffer);

                newlog.setUsername(loggedinUser);
                newlog.setBookname(Bookvector[i].getName());
                newlog.setIsbn(isbn);
                newlog.setstatus("checked-out");
                newlog.setIssueDate(idate);
                newlog.setReturnDate(rdate);
                IssuedBookvector.push_back(newlog);

                Functions f;
                dataAccessC.UpdateIssueBookDataDBA();

                Bookvector[i].setCount(Bookvector[i].getCount() - 1);
                bookloan = 1;
                return bookloan;
            }
        }
    }

    return bookloan;
}

void CustomerUI::showdetails()
{
    int i;
    cout << "This is the details:" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|       ISBN       |             BookName            |      IssueDate      |        ReturnDate       |      Status      |" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
    for (auto i : IssuedBookvector)
    {
        if (i.getUsername() == loggedinUser)
        {

            cout << "|" << setw(18) << i.getIsbn() << "|" << setw(33) << i.getBookname() << "|"
                 << setw(21) << i.getIssueDate() << "|" << setw(25) << i.getReturnDate() << "|" << setw(18) << i.getstatus() << "|" << endl;
        }
    }
    cout << "--------------------------------------------------------------------------------------------------------------------------\n\n"<< endl;

    cout << "1..Home Interface\t\t\t 2. Log out\t\t\t3. Close Application\n\n";
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
        customerInterface();
    }

    else if (i == 2)
    {
        Functions functions;
        functions.startup();
    }
    else if (i == 3)
    {
        exit(0);
    }
    else
    {
        cout << "\n\t*****************************************************************************************\n";
        cout << "\n\t\tPlease enter correct option :(\n";
        showdetails();
        cout << "\n\t*****************************************************************************************\n";
    }


}

bool Customer::isAvailable(std::string isbn)
{
    bool availability = false;

    for (auto i : Bookvector)
    {

        if (i.getIsbn() == isbn)
        {

            if (i.getCount() > 0)
            {
                bool availability = true;
                return availability;
            }
        }
    }

    return availability;
}

void CustomerUI::listbooks()
{
    int i;
    //Functions functions;
    cout << "This is the list of all the book:" << endl;
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

    cout << "1. Request Book Loan\t\t\t2.Home Interface\t\t\t 3. Log out\t\t\t4. Close Application\n\n";
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
        string isbn, username;
        cout << "\n Please Enter the ISBN number of the Book :";
        cin >> isbn;
        Customer c;
        int status = c.RequestBookLoan(isbn);

        if (status == 1)
        {
            cout << "\n\t*****************************************************************************************\n";
            cout << "\t\tBook is issued to you successfully...Happy Reading :)\n\n";
            cout << "\n\t*****************************************************************************************\n";
            dataAccessC.UpdateBookDataDBA();
            customerInterface();
        }
        else
        {
            cout << "\n\t*****************************************************************************************\n";
            cout << "\t\tThe book you are requesting is not available or already checked out to you: :(\n\n";
            cout << "\n\t*****************************************************************************************\n";
            listbooks();
        }
    }
    else if (i == 2)
    {
        customerInterface();
    }

    else if (i == 3)
    {
        Functions functions;
        functions.startup();
    }
    else if (i == 4)
    {
        exit(0);
    }
    else
    {
        cout << "\n\t*****************************************************************************************\n";
        cout << "\n\t\tPlease enter correct option :(\n";
        cout << "\n\t*****************************************************************************************\n";
        listbooks();
    }
}

bool Customer::isAlreadyissued(std::string isbn)
{
    bool issuestatus = false;

    for (auto i : IssuedBookvector)
    {

        if (i.getIsbn() == isbn && i.getUsername() == loggedinUser && i.getstatus() == "checked-out")
        {
            bool issuestatus = true;
            return issuestatus;
        }
    }
    return issuestatus;
}

void CustomerUI::customerInterface()
{

    int i;
    cout << "\n\t*********** LIBRARY MANAGEMENT SYSTEM - Customer Interface ***********\n";
    cout << "\n\t\t Hello :" << loggedinUser << "\t Welocme to the System\n";
    cout << "\n\t\t>>Please Choose Any Option \n";
    cout << "\n\t\t1.List Books\n\n\t\t2.Show Details\n\n\t\t3.Log out\n\n\t\t4.Close Application\n";
    cout << "\n\t\tEnter your choice : ";
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
        listbooks();
    }
    else if (i == 2)
    {
        showdetails();
    }

    else if (i == 3)
    {
        Functions functions;
        functions.startup();
    }
    else if (i == 4)
    {
        exit(0);
    }
    else
    {
        cout << "\n\t*****************************************************************************************\n";
        cout << "\n\t\tPlease enter correct option :(\n";
        cout << "\n\t*****************************************************************************************\n";
        customerInterface();
    }
}