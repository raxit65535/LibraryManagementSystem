#include "Controller/Customer.h"
#include "Model/DataAccess.h"
#include "Controller/Functions.h"
#include "Model/Log.h"
#include "Controller/Staff.h"

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