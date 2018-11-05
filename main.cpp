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
    dAccess.LoadUserData();
    dAccess.LoadBookData();
    dAccess.LoadIssueBookData();
    fun.startup();    
}