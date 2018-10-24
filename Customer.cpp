
#include "Customer.h"
#include "Functions.h"
#include <iostream>
#include <curses.h>

using namespace std;

Functions functions;

extern vector<Book> Bookvector;
extern vector<User> Uservector;

int Customer::RequestBookLoan(std::string isbn)
{

    return 0;
}

void Customer::showdetails()
{
    cout << "shwing the details";
}

bool Customer::isAvailable(std::string isbn)
{
}

void Customer::listbooks()
{
    
    cout << "Listing the Books\n\n";
    
    
    //Functions functions;
     cout << "printing the BookVector\n\n";
    for (auto i :  Bookvector)
    {

        int j = i.getCount();
        cout << i.getName() + "\t\t" + i.getIsbn() + "\t\t" + i.getAuthor() + "\t\t" + i.getInformation() + "\t\t" << j;
        cout << "\n";
    }

}

bool Customer::isAlreadyissued(std::string isbn)
{
}

void Customer::customerInterface()
{

    

    int i;
    cout << "\n\t*********** LIBRARY MANAGEMENT SYSTEM - Customer Interface ***********\n";
    cout << "\n\t\t>>Please Choose Any Option \n";
    cout << "\n\t\t1.List Books\n\n\t\t2.Show Details\n\n\t\t3.Log out\n\n\t\t4.Close Application\n";
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
        listbooks();
    }
    else if (i == 2)
    {
        system("clear");
        //getch();
        showdetails();
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
        cout << "\n\t\tPlease enter correct option :(";
        getch();
        system("clear");
        customerInterface();
    }
}