#include "UserDataDBA.h"
#include "UserData.h"
#include "User.h"
#include <vector>

extern vector<User> Uservector;
UserDataDBA uDBA;

void UserData :: LoadData()
{
    Uservector = uDBA.LoadUserDataDBA();
}

void UserData :: AddUser(string name,string username, string password)
{
    uDBA.AddUser(name, username, password);
}