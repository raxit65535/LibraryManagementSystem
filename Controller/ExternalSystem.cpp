#include "ExternalSystem.h"
#include <iostream>
#include <string>

std::string ExternalSystem::BookRequestProcess(std::string externalLibrary){

    int random = rand()%2;

    if(random == 1){

        return "\n\t\tRequested Book is Available at: "+externalLibrary+ ". Please Contact Library to issue the book....";

    }else{

        return "\n\t\t Requested Book is not Available at: " +externalLibrary;
    }
}