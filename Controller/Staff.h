#ifndef staff_h
#define staff_h

#include "../UserInterfaceLayer/UserInterface.h"
#include <string>

class StaffInterface
{
  public:
    virtual int returnIssuedBook(std::string isbn, std::string username) = 0;
};

// * This class contains method specific to the functionality related to the staff
class Staff : public StaffInterface,public UILayer
{
  public:
    virtual int returnIssuedBook(std::string isbn, std::string username);
};

#endif