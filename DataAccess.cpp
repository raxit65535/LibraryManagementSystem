#include "DataAccess.h"
#include "BookDataDBA.h"
#include "UserDataDBA.h"
#include "User.h"
#include <vector>
#include "Book.h"
#include "Log.h"
#include <iostream>
#include <string>
#include <fstream>

BookDataDBA bDBA;
UserDataDBA uDBA;

extern vector<Book> Bookvector;
extern vector<Log> IssuedBookvector;
extern vector<User> Uservector;

vector<Book> Bookvector;
vector<User> Uservector;
vector<Log> IssuedBookvector;

void BookDataDBA::UpdateBookDataDBA()
{
    ofstream userFile("Books.txt");
    if (userFile.is_open())
    {
        for (auto i : Bookvector)
        {
            userFile << i.getName() + " " + i.getIsbn() + " " + i.getInformation() + " " + i.getInformation() + " " << i.getCount() << endl;
        }

        userFile.close();
    }
    else
    {
        cout << "Unable to open Books.txt file";
    }
}

void BookDataDBA::UpdateIssueBookDataDBA(){

    ofstream userFile("IssuedBook.txt");
    if (userFile.is_open())
    {
        for (auto i : IssuedBookvector)
        {
            userFile << i.getUsername() + ";" + i.getIsbn() + ";" + i.getBookname() + ";" + i.getIssueDate() + ";" << i.getReturnDate() +";"<< i.getstatus() << endl;
        }

        userFile.close();
    }
    else
    {
        cout << "Unable to open IssueBook.txt file";
    }


}

vector<Book> BookDataDBA :: LoadBookDataDBA()
{
Book oldbook;
    string str;

    ifstream fin("Books.txt"); // Open and read Book.txt
    if (!fin)
    { // If can't open
        cerr << "Books.txt can't open" << endl;
        abort(); // Exit
    }
    while (getline(fin, str))
    {
        size_t i = str.find(" ");          // Find fisrt spacebar
        oldbook.setName(str.substr(0, i)); // Divide str by spacebar and get bookname
        str = str.substr(i + 1);

        i = str.find(" ");                 // Find second spacebar
        oldbook.setIsbn(str.substr(0, i)); // Divide str by spacebar and get ISBN number
        str = str.substr(i + 1);

        i = str.find(" ");
        oldbook.setAuthor(str.substr(0, i)); // Divide str by spacebar and get author
        str = str.substr(i + 1);

        i = str.find(" ");
        oldbook.setInformation(str.substr(0, i)); // Divide str by spacebar and get Information
        str = str.substr(i + 1);

        i = str.find(" ");
        oldbook.setCount(stoi(str.substr(0, i))); // Divide str by spacebar and get count
        //cout << "Count of book is " << oldbook.getCount();
        Bookvector.push_back(oldbook); // Add to Bookvector
    }
    fin.close(); // Close Books.txt
    // cout << "printing the Bookvector from DBA\n\n";
    // for (auto i : Bookvector)
    // {
    //     int j = i.getCount();
    //     cout << i.getName() + "\t\t" + i.getIsbn() + "\t\t" + i.getAuthor() + "\t\t" + i.getInformation() + "\t\t" << j;
    //     cout << "\n";
    // }
    // cout << "end *************************\n\n";
    return Bookvector;
}

vector<Log> BookDataDBA :: LoadIssueBookDataDBA()
{
    Log oldlog;
    string str;

    ifstream fin("IssuedBook.txt"); // Open and read Book.txt
    if (!fin)
    { // If can't open
        cerr << ".txt can't open" << endl;
        abort(); // Exit
    }
    while (getline(fin, str))
    {
        size_t i = str.find(";");             // Find fisrt spacebar
        oldlog.setUsername(str.substr(0, i)); // Divide str by spacebar and get bookname
        str = str.substr(i + 1);

        i = str.find(";");                // Find second spacebar
        oldlog.setIsbn(str.substr(0, i)); // Divide str by spacebar and get ISBN number
        str = str.substr(i + 1);

        i = str.find(";");
        oldlog.setBookname(str.substr(0, i)); // Divide str by spacebar and get author
        str = str.substr(i + 1);

        i = str.find(";");
        oldlog.setIssueDate(str.substr(0, i)); // Divide str by spacebar and get Information
        str = str.substr(i + 1);

        i = str.find(";");
        oldlog.setReturnDate(str.substr(0, i)); // Divide str by spacebar and get Information
        str = str.substr(i + 1);

        i = str.find(";");
        oldlog.setstatus(str.substr(0, i)); // Divide str by spacebar and get count
        
        IssuedBookvector.push_back(oldlog); // Add to Bookvector
    }
    fin.close();

    // cout<<"printing the issuedbookvector";
    // for(auto i : IssuedBookvector){

    //     cout<< i.getBookname() << i.getIsbn() << i.getIssueDate() << i.getReturnDate() << i.getUsername()<<"\n";
    // }
    return IssuedBookvector;
}

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