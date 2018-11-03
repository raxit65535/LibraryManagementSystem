#ifndef service_h
#define service_h

#include <iostream>
#include "BookDataDBA.h"
#include "UserDataDBA.h"
#include "Book.h"
#include "Log.h"
#include <vector>

using namespace std;
#include <string>

class DataAccess : public UserDataDBA , public BookDataDBA {
    public:
           
};
#endif

//service layer