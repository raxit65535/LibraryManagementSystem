#include "Customer.h"
#include "DataAccess.h"
#include "Functions.h"
#include "Log.h"
#include "Staff.h"

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

string loggedinUser;
Functions fun;
DataAccess dAccess;

int main()
{
    dAccess.LoadUserDataDBA();
    dAccess.LoadBookDataDBA();
    dAccess.LoadIssueBookDataDBA();
    fun.startup();    
}