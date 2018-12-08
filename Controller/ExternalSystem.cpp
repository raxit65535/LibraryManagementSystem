#include "ExternalSystem.h"
#include <iostream>
#include <string>

std::string ExternalSystem::BookRequestProcess(std::string externalLibrary){

    int random = rand()%2;

    if(random == 1){

        return "\n\t\tRequested Book is Available at: "+externalLibrary+ ". We will inform you once available for loan at our Library....";

    }else{

        return "\n\t\t Requested Book is not Available at: " +externalLibrary;
    }
}