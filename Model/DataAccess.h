#ifndef service_h
#define service_h

#include "BookDataPersistance.h"
#include "Book.h"
#include "Log.h"
#include "Logging.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// * This class acts as a DataAccess Layer.
// * This is a bridge between the Database and the business login of the application
// * It contains methods to Log user data and add new user in the account
class DataAccess : public BookDataPersistance, public Logging
{
  public:
    vector<User> LoadUserData();
    void AddUser(string name, string username, string password);
};

#endif
