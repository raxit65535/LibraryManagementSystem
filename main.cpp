#include "Functions.h"
#include "Staff.h"
#include "Log.h"
#include "Customer.h"
#include "DataAccess.h"
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

string loggedinUser;
Functions fun;
DataAccess dAccess;

int main()
{
    //try get the same vector from the return of this method, try not to duplicate a vector
    //loading the data into vectors....
    dAccess.LoadUserData();
    dAccess.LoadBookData();
    dAccess.LoadIssueBookData();
    fun.startup();    
}