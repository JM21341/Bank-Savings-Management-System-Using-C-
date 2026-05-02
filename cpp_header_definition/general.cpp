#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "../header/general.h"
#include "../header/classes.h"
#include "../header/structs.h"

Structs::Node* General::readDataFromFile(Structs::Node* head){
    if(head != NULL){
        std::cout << "Something went wrong. Data already pre-exists in the program before running." << std::endl;
        return NULL;
    }

    std::string line, line2;

    std::ifstream file("../records/user.csv"); // a bit dangerous of a directory

    // checks if file did not open
    if(!file.is_open()){
        std::cerr << "File did not open in readDataFromFile." << std::endl;
        return NULL;
    }

    while(std::getline(file, line)){
        std::stringstream ss(line);
        std::string ID, username, password, role;

        // stores the data from the file to a variable
        std::getline(ss, ID, ',');
        std::getline(ss, username, ',');
        std::getline(ss, password, ',');
        std::getline(ss, role, ',');

        Structs::Node* temp = new Structs::Node(); // creates a temp node
        temp->next = NULL; // more safer when it is put here than when it is put before the loop goes back

        temp->data.setLoginDetails(username, password, role, ID);

        // creates a second file
        std::stringstream filename; // for setting the filename
        filename << "../records/user_data/" << username << ".txt";
        
        std::string final_path = filename.str(); // type casts from string stream to an actual string
        // variables the details will be stored into
        std::string full_name, birthdate, email, contact_number, home_address, TIN_number, bank_number;
        std::string age_str, balance_str;
        
        std::ifstream file2(final_path);

        // checks if the file path is correct and is existing
        if(!file2.is_open()){
            std::cerr << "Something went wrong. Path does not exist for the user " << username << ".";
            break;
        }

        // for user personal details
        while(std::getline(file2, line2)){
            std::stringstream ss2(line2);

            std::getline(ss2, full_name, ',');
            std::getline(ss2, age_str, ',');
            std::getline(ss2, birthdate, ',');
            std::getline(ss2, balance_str, ',');
            std::getline(ss2, contact_number, ',');
            std::getline(ss2, email, ',');
            std::getline(ss2, home_address, ',');
            std::getline(ss2, TIN_number, ',');
            std::getline(ss2, bank_number, ',');
        }

        // handles the error in case it is empty
        int age = age_str.empty() ? 0 : std::stoi(age_str); // if the string is empty, age will be set to 0, else, type cast age into an integer
        double balance = balance_str.empty() ? 0.0 : std::stod(balance_str); //if the string is empty, balance will be set to 0.0, else, type cast balance into a double

        file2.close(); // closes the {username}.txt

        temp->data.setBalance(balance); // sets the balance for that user
        // sets all the personal details of the user
        temp->data.setPersonalDetails(full_name, age, birthdate, email, contact_number, home_address, TIN_number);

        // linking of the list
        if(head == NULL){
            head = temp; // sets the head ptr to the temp
        } else{
            Structs::Node* curr = head; // creates a temp ptr which traverses through each node
            while(curr->next != NULL) curr = curr->next; // search for a node which doesn't have a next link
            curr->next = temp; // sets the link of that node to the temp
        }
    }

    file.close(); // closes user.csv

    return head;
}

Structs::Node* General::login(Structs::Node* head){
    std::string username, password; // variables to store the username and password from user input
    bool found = false; 

    Structs::Node* curr = head; // create a temporary node

    do{
        // user login input
        std::cout << "Enter username: ";
        std::getline(std::cin, username);
        
        std::cout << std::endl << "Enter password: ";
        std::getline(std::cin, password);

        // traverse through every node in the linked lists
        while(curr != NULL){
            // if the username and password is correct, print a prompt, set found to true then break the loop
            if(username == curr->data.getUsername() && password == curr->data.getPassword()){
                std::cout << "You have successfully logged in." << std::endl;
                found = true;
                break;
            }

            curr = curr->next; // moves to the next node
        }

        if(!found){
            std::cout << "Incorrect username and/or password. Please try again." << std::endl;
            continue;
        }
    } while(!found);

    return curr;
}