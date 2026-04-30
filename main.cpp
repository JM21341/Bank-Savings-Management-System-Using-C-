#include <iostream>
#include <string>
#include "header/structs.h"
#include "header/general.h"
#include "header/admin.h"
#include "header/client.h"

int main(){
    bool cont = true; // for the loop

    Structs::Node* head = NULL; // defines head locally in nmain

    head = General::readDataFromFile(head); // defines the list by reading the file

    do{
        std::string role = General::login(head); // user login

        if(!cont) break;

        if(role == "Admin"){ 
            cont = Admin::adminControls(head);
        }
        else if(role == "Client"){ 
            Client::clientControls(head);
        }
        else{
            std::cout << "An error occurred in determining the user role." << std::endl;
            break;
        }
    } while(cont);

    std::cout << "Exiting..." << std::endl;

    return 0;
}