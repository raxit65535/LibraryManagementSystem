#include <string>

class Customer
{

  public:
    void listbooks();              //list all the books
    void showdetails();            //show details of when the book is due
    int RequestBookLoan(std::string isbn); //just manage the request for the same customer who is loggedin --kind of session management, feel free to change method parameters.
    bool isAvailable(std::string isbn);
    bool isAlreadyissued(std::string isbn);
    void customerInterface();
};