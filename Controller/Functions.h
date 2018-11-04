#ifndef functions_h
#define functions_h

#include "../Model/Book.h"
#include "../Model/User.h"
#include "../UserInterfaceLayer/UserInterface.h"
#include <vector>

// * This class implements methods that acts as starting point to the system.
class Functions : public systemUI
{
    public:
        int login(string username, string passwd);
        int registration(string name, string username, string password);
        bool isUserExist(string username);
};

#endif
