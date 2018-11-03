#ifndef service_h
#define service_h

#include <iostream>
#include "BookDataDBA.h"
#include "Book.h"
#include "Log.h"
#include <vector>

using namespace std;
#include <string>

class DataAccess {
    public:
        void LoadBookData();
        void LoadIssueBookData();
        void UpdateBookData();
        void UpdateIssueBookData();  

        void LoadUserData();
        void AddUser(string name,string username, string password);      
};
#endif

//service layer