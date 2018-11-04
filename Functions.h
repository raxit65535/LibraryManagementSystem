#ifndef functions_h
#define functions_h

#include "Book.h"
#include "User.h"

#include <vector>

// * This class contains abstract method which is implemented by the system
//   to display the UI to any user that starts the application
class systemUI
{
    public:
        virtual void loginInterface();
        virtual void registrationInterface();
        virtual void startup();
};

// * This class contains abstract methods which deals with creation of account in the system
class systemEntry
{
    public:
        virtual int login(string username, string password);
        virtual int registration(string name, string username, string password);
};

// * This class implements methods that acts as starting point to the system.
class Functions : public systemUI, public systemEntry
{
    public:
        int login(string username, string passwd);
        int registration(string name, string username, string password);
        bool isUserExist(string username);
};

#endif
