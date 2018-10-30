#include <string>

class CustomerUI{

  public:
    void listbooks();
    void customerInterface();
    void showdetails();

};

class CustomerControllerLogic{

  public:
    void RequestBookLoan(std::string isbn);
    bool isAvailable(std::string isbn);
    bool isAlreadyissued(std::string isbn);

};

class Customer : public CustomerUI, public CustomerControllerLogic
{

public:
  void listbooks();                      //list all the books
  void showdetails();                    //show details of when the book is due
  int RequestBookLoan(std::string isbn); //just manage the request for the same customer who is loggedin --kind of session management, feel free to change method parameters.
  bool isAvailable(std::string isbn);
  bool isAlreadyissued(std::string isbn);
  void customerInterface();
};