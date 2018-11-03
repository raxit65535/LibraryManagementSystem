#ifndef service_h
#define service_h

#include <iostream>
#include "BookDataPersistance.h"
#include "Logging.h"
#include "Book.h"
#include "Log.h"
#include <vector>

using namespace std;
#include <string>

class DataAccess : public BookDataPersistance, public Logging {
    public:
        vector<User> LoadUserDataDBA();
        void AddUser(string name,string username, string password);
           
};
#endif

//service layer