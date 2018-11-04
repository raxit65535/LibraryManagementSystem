#ifndef staff_h
#define staff_h

#include "../UserInterfaceLayer/UserInterface.h"
#include <string>

// * This class contains method specific to the functionality related to the staff
class Staff : public UILayer
{
    public:
        int returnIssuedBook(std::string isbn, std::string username);
};

#endif