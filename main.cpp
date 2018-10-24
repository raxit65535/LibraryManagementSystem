#include "Functions.h"
#include "Staff.h"
#include "Customer.h"
#include <stdio.h>
#include <iostream>
#include <curses.h>
#include <vector>

using namespace std;

vector<User> Uservector;
vector<Book> Bookvector;
vector<string> IssuedBookvector;

//extern vector<User> Uservector;

int main()
{

    //try get the same vector from the return of this method, try not to duplicate a vector
     //loading the data into vectors....
    Functions fun;
    fun.LoadUserData(); //it will creat Uservector to use for login
    fun.LoadBookData(); //it will create Bookvector for future use (listbook(), requestbookloan()).

    
    fun.startup();
}