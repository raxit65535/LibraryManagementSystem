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

class Persistance{

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
  void loginInterface();
  int login(string username, string passwd);
  void registrationInterface();
  int registration(string name, string username, string password);
  void LoadUserData();
  void LoadBookData();
  void IssuedBookData();
  void startup();
  void UpdateBookData();
  void UpdateIssueBookData();
  void UpdateUserData();
};