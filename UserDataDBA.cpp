#include <string>
#include "User.h"
#include "UserDataDBA.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

vector<User> Uservector;

vector<User> UserDataDBA :: LoadUserDataDBA()
{
    User olduser;
    string str;

    ifstream fin("User.txt"); // Open and read User.txt
    if (!fin)
    { // If can't open
        cerr << "User.txt can't open" << endl;
        abort(); // Exit
    }
    while (getline(fin, str))
    {
        size_t i = str.find(" ");          // Find fisrt spacebar
        olduser.setname(str.substr(0, i)); // Divide str by spacebar and get username
        str = str.substr(i + 1);

        i = str.find(" ");                     // Find second spacebar
        olduser.setusername(str.substr(0, i)); // Divide str by spacebar and get password
        str = str.substr(i + 1);

        i = str.find(" ");                     // Find second spacebar
        olduser.setpassword(str.substr(0, i)); // Divide str by spacebar and get password

        olduser.setStatus(str.substr(i + 1)); // Divide str by spacebar and get status

        Uservector.push_back(olduser); // Add to lib.UserArray
    }
    fin.close(); // Close User.txt

    // cout << "printing the Uservector\n\n";
    // for (auto i : Uservector)
    // {

    //     cout << i.getname() + "\t\t" + i.getusername() + "\t\t" + i.getpasswd() + "\t\t" + i.getStatus() + "\n\n";
    // }
    return Uservector;
}


void UserDataDBA::AddUser(string name,string username, string password)
{
    User olduser;
    olduser.setname(name);
    olduser.setusername(username);
    olduser.setpassword(password);
    olduser.setStatus("3");
    Uservector.push_back(olduser);

    ofstream userFile("User.txt", std::ofstream::out | std::ofstream::app);
    if (userFile.is_open())
    {
        userFile << name + " " + username + " " + password + " 3"
                 << "\n";

        userFile.close();
    }
    else
    {
        cout << "Unable to open User.txt file";
    }
}