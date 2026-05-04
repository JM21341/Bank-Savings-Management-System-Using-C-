#include <iostream>
#include "../header/structs.h"
#include "../header/general.h"
#include "../header/client.h"

int main(){
    bool cont = true; // for the loop

    Structs::Node* head = NULL; // defines head locally in nmain

    head = General::readDataFromFile(head); // defines the list by reading the file

    do{
        Structs::Node* curr = General::login(head); // user login

        if(!cont) break;

        if(curr->data.getRole() == "Client"){ 
            cont = Client::clientControls(head); // for user controls such as transactions, edit personal info, etc.
        }
        else{
            std::cout << "An error occurred in determining the user role." << std::endl;
            break;
        }
    } while(cont);

    std::cout << "Exiting..." << std::endl;

    delete(head);

    return 0;
}