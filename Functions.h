#include <vector>
#include "User.h"
#include "Book.h"

class systemUI
{

public:
  void loginInterface();
  void registrationInterface();
  void startup();
};

class systemEntry
{
public:
  int login(string username, string password);
  int registration(string name, string username, string password);
};

class Persistance
{

public:
  void LoadBookData();
  void LoadUserData();
  void LoadIssueBookData();
  void UpdateBookData();
  void UpdateIssueBookData();
  void UpdateUserData();
};

class Functions : public systemUI, public systemEntry, public Persistance
{

public:
  int login(string username, string passwd);
  int registration(string name, string username, string password);
};

