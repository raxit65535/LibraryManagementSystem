#ifndef userDataDBA_h
#define userDataDBA_h

#include <string>
#include "User.h"
#include <vector>
using namespace std;

class UserDataDBA
{
    public:
        virtual vector<User> LoadUserDataDBA();
        virtual void AddUser(string name,string username, string password);
};

#endif

//this is abstract class that defines methods. this class is inherited by DataAccess class
// in DataAccess class, these methods are implemented