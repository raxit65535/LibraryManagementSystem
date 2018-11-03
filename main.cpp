// #include "UserData.h"
#include "BookData.h"
#include "UserData.h"
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
BookData bD;
UserData uD;

int main()
{
    //try get the same vector from the return of this method, try not to duplicate a vector
    //loading the data into vectors....
    uD.LoadData();
    bD.LoadData();
    bD.LoadIssueBookData();
    fun.startup();    
}