#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "../header/general.h"
#include "../header/classes.h"
#include "../header/structs.h"

Structs::Node* General::readDataFromFile(Structs::Node* head){
    if(head != NULL){
        std::cout << "Something went wrong. Data already pre-exists in the program before running." << std::endl;
        return NULL;
    }

    std::string line;

    std::ifstream file("../records/user.csv"); // a bit dangerous of a directory

    // checks if file did not open
    if(!file.is_open()){
        std::cerr << "File did not open in readDataFromFile." << std::endl;
        return NULL;
    }

    while(std::getline(file, line)){

    }

    file.close();

    return head;
}

std::string General::login(Structs::Node* head);