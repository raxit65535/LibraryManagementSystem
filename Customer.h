#include <string>

class CustomerUI
{

public:
  void listbooks();
  void customerInterface();
  void showdetails();
};

class Customer : public CustomerUI
{

public:
  int RequestBookLoan(std::string isbn); //just manage the request for the same customer who is loggedin --kind of session management, feel free to change method parameters.
  bool isAvailable(std::string isbn);
  bool isAlreadyissued(std::string isbn);
};