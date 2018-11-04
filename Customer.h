#ifndef customerUI_h
#define customerUI_h

#include <string>

// * This class contains abstract method to specific for Customer's user interface
class CustomerUI
{
    public:    
        virtual void customerInterface();
        virtual void listbooks();
        virtual void showdetails();
};

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