#ifndef managerUI_h
#define managerUI_h

#include "../UserInterfaceLayer/UserInterface.h"
#include "../Model/Book.h"
#include "../Model/User.h"
#include "Customer.h"
#include "Functions.h"
#include "Staff.h"
#include <string>

class ManagerInterface
{

  public:
    virtual int AddBook(string name, string isbn, string author, string information, int count) = 0;
    virtual int AddStaff(string name, string username, string password) = 0;

};

// * This class implements methods from CustomerUI class.
// * It contains methods specific to the customer
class Manager : public ManagerUI,public ManagerInterface, public Staff, public Customer, public Functions
{
  public:
    virtual int AddBook(string name, string isbn, string author, string information, int count);
    virtual int AddStaff(string name, string username, string password);
};

#endif