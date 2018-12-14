#include "../Model/DataAccess.h"
#include "ExternalSystem.h"
#include <fstream>
#include <iostream>
#include <string>

class PollakLibrary : public ExternalSystem
{

  public:
    virtual string ExternalBookRequest(string username, string isbn, string libraryname)
    {

        int random = rand() % 2;

        if (random == 1)
        {

            ofstream userFile("DataFiles/ExternalInterfaceLogs.txt", std::ofstream::out | std::ofstream::app);
            if (userFile.is_open())
            {
                userFile << username + ";" + isbn + ";" + libraryname << endl;
                userFile.close();
                return "YES";
            }
            else
            {
                cout << "Unable to open Books.txt file";
                return "NO";
            }
        }
        else
        {
            //\n\t\t Requested Book is not Available at: " + externallibrary
            return "NO";
        }

        //return "YES";
    }
};

class HopeInternational : public ExternalSystem
{
  public:
    virtual string ExternalBookRequest(string username, string isbn, string libraryname)
    {

        int random = rand() % 2;

        if (random == 1)
        {

            ofstream userFile("DataFiles/ExternalInterfaceLogs.txt", std::ofstream::out | std::ofstream::app);
            if (userFile.is_open())
            {
                userFile << username + ";" + isbn + ";" + libraryname << endl;
                userFile.close();
                return "YES";
            }
            else
            {
                cout << "Unable to open Books.txt file";
                return "NO";
            }
        }
        else
        {
            //\n\t\t Requested Book is not Available at: " + externallibrary
            return "NO";
        }
    }
};