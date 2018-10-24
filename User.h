#include <string>

class User
{

    //This header file defines getters and setters for a User <name, username, password, address>

  public:
    std::string getname() { return name; }
    void setname(std::string n) { name = n; }

    std::string getusername() { return usernme; }
    void setusername(std::string u) { usernme = u; }

    std::string getpasswd() { return password; }
    void setpassword(std::string pwd) { password = pwd; }

    std::string getStatus(){return status;}
    void setStatus(std::string sts) { status = sts;}

    std::string name;
    std::string usernme;
    std::string password;
    std::string status;
};