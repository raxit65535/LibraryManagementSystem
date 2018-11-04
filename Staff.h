#ifndef staff_h
#define staff_h

#include <string>

// * This class contains abstract methods for Staff's UI
class UILayer
{
    public:
        virtual void staffInterface();
        virtual void viewlog();
        virtual void viewBooksAvailability();
        virtual void returnBookInterface();
};

// * This class contains method specific to the functionality related to the staff
class Staff : public UILayer
{
    public:
        int returnIssuedBook(std::string isbn, std::string username);
};

#endif