//database specific. can be changed
//if t here is any new database implementations

#ifndef BookDataDBA_h
#define BookDataDBA_h

#include <string>
using namespace std;

#include "BookData.h"
#include "Book.h"
#include "Log.h"
#include <vector>


class BookDataDBA{
    public:
        vector<Book> LoadBookDataDBA();
        vector<Log> LoadIssueBookDataDBA();
        void UpdateBookDataDBA();
        void UpdateIssueBookDataDBA();

};

#endif
