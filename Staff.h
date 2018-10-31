#include <string>

class UILayer
{
public:
  void staffInterface();
  void viewlog();
  void viewBooksAvailability();
  void returnBookInterface();
};

class Staff : public UILayer
{

public:
  int returnIssuedBook(std::string isbn, std::string username);
};