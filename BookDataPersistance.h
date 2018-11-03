//database specific. can be changed
//if t here is any new database implementations

#ifndef BookDataPersistance_h
#define BookDataPersistance_h

#include <string>
using namespace std;

#include "Book.h"
#include <vector>


class BookDataPersistance{
    public:
        virtual vector<Book> LoadBookDataDBA();
        virtual void UpdateBookDataDBA();
        

};

#endif

//this is abstract class that defines methods. this class is inherited by DataAccess class
// in DataAccess class, these methods are implemented