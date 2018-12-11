#ifndef externalsystem_h
#define externalsystem_h
#include <string>

class ExternalSystem{

    public:

    virtual std::string ExternalBookRequest(std::string username,std::string isbn,std::string externalLibrary) = 0;


};


#endif