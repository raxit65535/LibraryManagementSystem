#include "DataAccess.h"
#include "BookDataDBA.h"
#include "UserDataDBA.h"
#include "User.h"
#include <vector>

BookDataDBA bDBA;
UserDataDBA uDBA;

extern vector<Book> Bookvector;
extern vector<Log> IssuedBookvector;
extern vector<User> Uservector;

void DataAccess::LoadBookData()
{
    Bookvector = bDBA.LoadBookDataDBA();
}

void DataAccess :: LoadIssueBookData()
{
    IssuedBookvector = bDBA.LoadIssueBookDataDBA();
}

void DataAccess::UpdateBookData()
{
    bDBA.UpdateBookDataDBA();
}

void DataAccess :: UpdateIssueBookData()
{
    bDBA.UpdateIssueBookDataDBA();
}

void DataAccess :: LoadUserData()
{
    Uservector = uDBA.LoadUserDataDBA();
}

void DataAccess :: AddUser(string name,string username, string password)
{
    uDBA.AddUser(name, username, password);
}