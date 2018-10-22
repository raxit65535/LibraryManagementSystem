#include "Functions.h"

#include <stdio.h>
#include <iostream>
#include <curses.h>

using namespace std;

Functions fun;

void startup()
{

    int i;
    cout << "\n\t*********** LIBRARY MANAGEMENT SYSTEM ***********\n";
    cout << "\n\t\t>>Please Choose Any Option To login \n";
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
        clear();
        fun.loginInterface();
    }
    else if (i == 2)
    {
        clear();
        fun.registrationInterface();
    }

    else if (i == 3)
    {
        exit(0);
    }
    else
    {
        cout << "\n\t\tPlease enter correct option :(";
        getch();
        //system("CLS");
        clear();
        startup();
    }
}

int main()
{

    //try get the same vector from the return of this method, try not to duplicate a vector
    
    //fun.LoadUserData(); //it will creat Uservector to use for login
    //fun.LoadBookData(); //it will create Bookvector for future use (listbook(), requestbookloan()).
}