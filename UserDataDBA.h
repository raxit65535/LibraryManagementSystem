#ifndef userDataDBA_h
#define userDataDBA_h

#include <string>
#include "User.h"
#include <vector>
using namespace std;

class UserDataDBA
{
    public:
        vector<User> LoadUserDataDBA();
        void AddUser(string name,string username, string password);
};

#endif