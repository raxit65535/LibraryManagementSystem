#ifndef customerUI_h
#define customerUI_h

#include "../UserInterfaceLayer/UserInterface.h"
#include <string>

// * This class implements methods from CustomerUI class.
// * It contains methods specific to the customer
class Customer : public CustomerUI
{
    public:
        int RequestBookLoan(std::string isbn); 
        bool isAvailable(std::string isbn);
        bool isAlreadyissued(std::string isbn);
};

#endif