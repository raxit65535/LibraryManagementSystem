//database specific. can be changed
//if t here is any new database implementations

#ifndef BookDataDBA_h
#define BookDataDBA_h

#include <string>
using namespace std;

#include "Book.h"
#include "Log.h"
#include <vector>


class BookDataDBA{
    public:
        virtual vector<Book> LoadBookDataDBA();
        virtual vector<Log> LoadIssueBookDataDBA();
        virtual void UpdateBookDataDBA();
        virtual void UpdateIssueBookDataDBA();

};

#endif

//this is abstract class that defines methods. this class is inherited by DataAccess class
// in DataAccess class, these methods are implemented