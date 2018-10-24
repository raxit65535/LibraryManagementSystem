#include "Functions.h"
#include "Staff.h"
#include "Customer.h"
#include <stdio.h>
#include <iostream>
#include <curses.h>

using namespace std;

 



int main()
{

    //try get the same vector from the return of this method, try not to duplicate a vector
    Functions fun;
    fun.LoadUserData(); //it will creat Uservector to use for login
    //fun.LoadBookData(); //it will create Bookvector for future use (listbook(), requestbookloan()).

    fun.startup();
}