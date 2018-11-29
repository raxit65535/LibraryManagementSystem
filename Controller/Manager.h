#ifndef managerUI_h
#define managerUI_h

#include "../UserInterfaceLayer/UserInterface.h"
#include "../Model/Book.h"
#include "../Model/User.h"
#include "Customer.h"
#include "Functions.h"
#include "Staff.h"
#include <string>

// * This class implements methods from CustomerUI class.
// * It contains methods specific to the customer
class Manager : public ManagerUI, public Staff, public Customer, public Functions
{
    public:
        int AddBook(string name, string isbn, string author, string information, int count);
        int AddStaff(string name, string username, string password);
};

#endif