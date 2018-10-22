#include <vector>
#include "User.h"
#include "Book.h"

namespace Globaldata{

    extern std::vector<User> Uservector;
    extern std::vector<Book> Bookvector;
    extern std::vector<string> IssuedBookvector;
}

class Functions
{


  public:
    void loginInterface();        //will just provide login console interface, from there we will call Login Method,
    int login();                  // this method will authenticate the user and return the status 1,2,3 (1=admin,2=staff, 3=customer)
    void registrationInterface(); //will open console interfcae for registration (it will ask Name, Username, Password, Address)
    int registration();           //By default the status Flag is set to 3, because only customers can register through our system

    void LoadUserData(); //it will load all the data available in user.txt where the status tag is = customer (3) into UserVector
    void LoadBookData(); //it will load all the data available in the Book.txt into BookVector (defined below)
    void issuedBook(); //it will load all the data available in IssuedBook.txt and put it in the IssuedBook Vector
};