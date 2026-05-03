#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono> // for determining the seconds
#include <thread> // for sleep_for (time delay)

#include "../header/general.h"
#include "../header/classes.h"
#include "../header/structs.h"

void General::wait(int n){
    std::this_thread::sleep_for(std::chrono::seconds(n));
}

Structs::Transaction* General::readTransactionFromRecord(Structs::Node *curr){
    Structs::Transaction* transaction_head = NULL; // creates a head for tranasction

    std::stringstream filename; // for filename
    filename << "../records/transaction_database/" << curr->data.getUsername() << ".csv"; // sets the filename to the directory of the specific transaction database

    std::string file_path = filename.str(); // converts the variable from a stringstream to string
    std::string line; // for stirubg each line

    std::ifstream file(file_path);

    while(std::getline(file, line)){
        Structs::Transaction* temp = new Structs::Transaction();
        temp->next = NULL;

        std::stringstream ss(line); // for storing the value in each line, with a delimiter
        std::string transaction_num, transaction_id, transaction_details, transaction_date, amount, new_balance; // variables to store the values

        // storing of values from the file t the variables above
        std::getline(ss, transaction_num, ',');
        std::getline(ss, transaction_id, ',');
        std::getline(ss, transaction_details, ',');
        std::getline(ss, transaction_date, ',');
        std::getline(ss, amount, ',');
        std::getline(ss, new_balance, ',');

        // storing value to the transaction struct's variables
        temp->transaction_num = std::stoi(transaction_num); // converts transaction_num from string to integer
        temp->amount = std::stod(amount); // converts amount from string to double
        temp->new_balance = std::stod(new_balance); // converts new_balance from string to double
        temp->transaction_id = transaction_id;
        temp->details = transaction_details;
        temp->date = transaction_date;

        // assigning of transaction_head

        if(transaction_head == NULL){
            transaction_head = temp; // if the list is empty, assigns head to the first temp
        } else{
            // if not empty,
            Structs::Transaction* point = transaction_head; // creates a point from the head
            while(point->next != NULL) point = point->next; // traverses through the lists until it finds a node with no link
            point->next = temp; // sets the link of that node to the temp
        }

        // will run until the EOF (end of file)
    }

    return transaction_head; 
}

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
        filename << "../records/user_database/" << username << ".txt";
        
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

        temp->transaction = readTransactionFromRecord(temp);

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

bool General::askToContinue(){
    char dec;
    bool cont;

    do{
        cont = false;
        std::cout << "Do you wish to continue (Y/n): ";
        std::cin >> dec;

        if(dec == 'Y' || dec == 'y') return true;
        else if(dec == 'N' || dec == 'n') return false;
        else cont = true;
    } while(cont);
}