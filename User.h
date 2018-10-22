#include <string>

using namespace std;

class User
{

    //This header file defines getters and setters for a User <name, username, password, address>

  public:
    string getname() { return name; }
    void setname(string n) { name = n; }

    string getusername() { return usernme; }
    void setusername(string u) { usernme = u; }

    string getpasswd() { return password; }
    void setpassword(string pwd) { password = pwd; }

    string getaddress() { return address; }
    void setaddress(string addr) { address = addr; }

  private:
    string name;
    string usernme;
    string password;
    string address;
};