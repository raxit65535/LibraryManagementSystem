#ifndef Logging_h
#define Logging_h

#include <string>
#include "User.h"
#include "Log.h"
#include <vector>
using namespace std;

class Logging
{

    public:
        virtual vector<Log> LoadIssueBookDataDBA();
        virtual void UpdateIssueBookDataDBA();


};

#endif

//this is abstract class that defines methods. this class is inherited by DataAccess class
// in DataAccess class, these methods are implemented