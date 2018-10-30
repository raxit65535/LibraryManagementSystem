#include <string>

class staffUI
{

  public:
    void staffInterface();
    void viewlog();
    void viewBooksAvailability();
    void returnBookInterface();
};

class StaffControllerLogic
{
        public:
        int returnIssuedBook();
};

class Staff : public staffUI, public StaffControllerLogic
{

  public:
    void viewBooksAvailability();
    void returnBookInterface();
    void viewlog();
    int returnIssuedBook(std::string isbn, std::string username);
    void staffInterface();
};