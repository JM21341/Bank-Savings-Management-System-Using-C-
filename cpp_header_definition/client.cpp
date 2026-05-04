#include <iostream>
#include <cstdlib> // for system("cls")
#include <filesystem> // for rename() and delete()
#include <fstream> // for ofstream
#include <sstream> // for stringstream
#include <iomanip> // for setprecision()

#include "../header/client.h"
#include "../header/general.h"

void Client::updateTransactionFile(Structs::Node* curr){
    std::filesystem::path dir = "C:\\C++ Projects\\Projects\\Console-Based_Bank_Savings_Management_System\\records\\transaction_database";
    std::filesystem::path file_path = dir / (curr->data.getUsername() + ".csv");
    std::filesystem::path temp_path = dir / "temp.csv";

    std::ofstream file(temp_path); // opens the directory

    // checks if file is open
    if(!file.is_open()){
        std::cerr << "File was not created in updateFile" << std::endl;
        return;
    }

    Structs::Transaction* current = curr->transaction; // creates a temporary current pointer

    // writes to that file until the current transaction in the history is NULL
    // traverses through each node and writes the data from it to the file
    while(current != NULL){
        file << current->transaction_num << "," << 
            current->transaction_id << "," << 
            current->details << "," << 
            current->date << "," << 
            current->amount << "," << 
            current->new_balance << "," << 
            std::endl;

        current = current->next; // moves to the next node
    }

    file.close(); // closes file

    // checks if the data was writted to the file
    if(file.fail()){
        std::cerr << "failed to write to temporary file in updateFile()" << std::endl;
        return;
    }

    std::error_code ec; // variable for error code

    // error handling for file removal
    if(!std::filesystem::remove(file_path, ec) && ec){
        std::cerr << "Failed to remove original file: " << ec.message() << std::endl;
        return;
    }
    
    std::filesystem::rename(temp_path, file_path, ec); // renames file

    // error handling for file renaming
    if(ec){
        std::cerr << "Failed to rename temporary file: " << ec.message() << std::endl;
        return;
    }
}

bool Client::clientControls(Structs::Node *curr){
    int dec = 0, dec2 = 0;
    bool cont = true, exit = false, logout = false;

    do{
        std::cout << "========== BANK ==========" << std::endl;
        std::cout << "[1] Transaction" << std::endl;
        std::cout << "[2] Personal Info" << std::endl;
        std::cout << "[3] Inbox" << std::endl;
        std::cout << "[4] Log Out" << std::endl;
        std::cout << "[5] Exit" << std::endl;

        std::cout << "Select an item: ";
        std::cin >> dec;
        std::cout << std::endl << std::endl;

        General::wait(2);
        system("cls");

        switch(dec){
            case 1:
                std::cout << "========== BANK ==========" << std::endl;
                std::cout << "[1] Check Savings" << std::endl;
                std::cout << "[2] Deposit" << std::endl;
                std::cout << "[3] Withdraw" << std::endl;
                std::cout << "[4] View Transaction History" << std::endl;
                std::cout << "[5] Back" << std::endl;

                std::cout << "Select an item: ";
                std::cin >> dec2;
                std::cout << std::endl << std::endl;

                General::wait(2);
                system("cls");

                switch(dec2){
                    case 1:
                        Client::checkSavings(curr);
                        cont = General::askToContinue();
                        break;
                    case 2:
                        curr = Client::deposit(curr);
                        cont = General::askToContinue();
                        break;
                    case 3:
                        curr = Client::withdraw(curr);
                        cont = General::askToContinue();
                        break;
                    case 4:
                        Client::viewTransactionHistory(curr);
                        cont = General::askToContinue();
                        break;
                    case 5:
                        break;
                    default:
                        std::cout << "Invalid input.";
                        break;
                }
                break;
            case 2:
                std::cout << "========== BANK ==========" << std::endl;
                std::cout << "[1] View Info" << std::endl;
                std::cout << "[2] Edit Personal Info" << std::endl;
                std::cout << "[3] Back" << std::endl;

                std::cout << "Select an item: ";
                std::cin >> dec2;
                std::cout << std::endl << std::endl;

                General::wait(2);
                system("cls");

                switch(dec2){
                    case 1:
                        Client::viewPersonalInfo(curr);
                        cont = General::askToContinue();
                        break;
                    case 2:
                        curr = Client::editPersonalInfo(curr);
                        cont = General::askToContinue();
                        break;
                    case 3:
                        break;
                    default:
                        std::cout << "Invalid input.";
                        break;
                }
                break;
            case 3:
                std::cout << "To be worked upon." << std::endl;
                break;
            case 4:
                cont = false;
                logout = true;
                break;
            case 5:
                cont = false;
                exit = true;
                break;
            default:
                std::cout << "Invalid input. Please try again." << std::endl;
                break;
        }

        General::wait(2);
        system("cls");
    }while(cont);

    if(exit) return false;
    if(logout) return true;
}

void Client::checkSavings(Structs::Node* curr){
    std::cout << "========== BANK ==========" << std::endl;
    std::cout << "Hello, " << curr->data.getUsername() << std::endl; // access username through a getter
    std::cout << "This is your current balance: " << curr->data.getBalance() << std::endl; // access balance through a getter

    return;
}

Structs::Node* Client::deposit(Structs::Node *curr){
    double amount = 0;
    bool cont = true;

    do{
        std::cout << "========== BANK ==========" << std::endl;
        std::cout << "Hello, " << curr->data.getUsername() << std::endl << std::endl; // retrieves username

        // user input for amount
        std::cout << "Enter deposit amount: " ;
        std::cin >> amount;

        if(amount >= 0){
            curr->data.modifyBalance(amount, "Deposit"); // modifies balance
            cont = false; // stops loop
        } else{
            std::cout << "Invalid amount." << std::endl; // error message for an invalid amount
        }

        General::wait(2); // time delay
        system("cls"); // clears terminal
    } while(cont);

    std::string date;

    std::cin.ignore(); // clears buffer

    // asking for date
    std::cout << "Enter date(MM/DD/YYYY): ";
    std::getline(std::cin, date);

    Structs::Transaction* temp = new Structs::Transaction(); // creates a temporary node
    // assigning of values
    temp->date = date;
    temp->amount = amount;
    temp->new_balance = curr->data.getBalance();
    temp->details = "Deposit";
    temp->next = NULL;

    if(curr->transaction == NULL){
        temp->transaction_num = 1; // sets transaction number to 1 by default

        std::stringstream id;
        id << "DEPO" << temp->transaction_num; // sets the value of ID
        std::string new_id = id.str(); // converts id from stringstream to string
        temp->transaction_id = new_id; // assigns the ID to the transaction id

        curr->transaction = temp; // sets the transaction head ptr to temp
    } else{
        Structs::Transaction* current_trans = curr->transaction; // creates a temporary node to traverse through the list
        while(current_trans->next != NULL) current_trans = current_trans->next; // list traversal

        temp->transaction_num = current_trans->transaction_num + 1; // sets the value of the current transaction num as the incrementation of the previous transaction num

        std::stringstream id;
        id << "DEPO" << temp->transaction_num; // sets the value of ID
        std::string new_id = id.str(); // converts id from stringstream to string
        temp->transaction_id = new_id; // assigns the ID to the transaction id

        current_trans->next = temp; // sets the previous link to the current/temp node
    }

    General::updateFile(curr); // updates the personal data file

    Client::updateTransactionFile(curr); // updates the transaction_database file of that user

    return curr;
}

Structs::Node* Client::withdraw(Structs::Node *curr){
    double amount = 0; // storage for the desired amount to withdraw
    bool cont = true;
    int i = 0; // for limit of loop

    do{
        std::cout << "========== BANK ==========" << std::endl;
        std::cout << "Hello, " << curr->data.getUsername() << std::endl << std::endl;

        std::cout << "Input 0 if you want to go back" << std::endl << std::endl; // they can input 0 to break the loop
        std::cout << "Enter withdraw amount: " ;
        std::cin >> amount;

        if(amount > 0 && amount <= curr->data.getBalance()){
            curr->data.modifyBalance(amount, "Withdraw"); // modifies balance
            cont = false; // so the loop ends
        } 
        // checks if the amount is correct and valid
        else if(i <= 5 && amount > curr->data.getBalance()){
            std::cout << "Invalid amount. Not enough balance." << std::endl; // error message
        } else if(amount == 0) break;
        // error message for when the input is invalid
        else{
            std::cout << "Invalid input! Please try again." << std::endl;
        }

        General::wait(2); // time delay
        system("cls"); // clears terminal

        i++; // incrementation for amount of tries

        if(i > 5){
            std::cout << "Max numbers of attempts reached." << std::endl;
            return curr;
        }
    } while(cont);

    std::string date; // stores date to string

    std::cin.ignore(); // clear buffer

    // input date
    std::cout << "Enter date: ";
    std::getline(std::cin, date);

    Structs::Transaction* temp = new Structs::Transaction(); // creates a temporary node
    // assigning of values
    temp->date = date;
    temp->amount = amount;
    temp->new_balance = curr->data.getBalance();
    temp->details = "Withdraw";
    temp->next = NULL;

    if(curr->transaction == NULL){
        temp->transaction_num = 1; // sets transaction number to 1 by default

        std::stringstream id;
        id << "WTDR" << temp->transaction_num; // sets the value of id
        std::string new_id = id.str(); // converts id from stringstream to string
        temp->transaction_id = new_id; // assigns the transaction id to the set id

        curr->transaction = temp; // sets the head of transaction to temp
    } else{
        Structs::Transaction* current_trans = curr->transaction; // creates a temporary pointer to traverse through each node
        while(current_trans->next != NULL) current_trans = current_trans->next; // traversing of list

        temp->transaction_num = current_trans->transaction_num + 1; // sets transaction num to the incrementation of previous transaction num

        std::stringstream id;
        id << "WTDR" << temp->transaction_num; // sets the value of id
        std::string new_id = id.str(); // converts id from stringstream to string
        temp->transaction_id = new_id; // assigns the transaction id to the set id

        current_trans->next = temp; // sets the head of transaction to temp
    }

    General::updateFile(curr); // updates the personal data file

    Client::updateTransactionFile(curr); // updates the transaction_database file of that user

    return curr;
}

void Client::viewTransactionHistory(Structs::Node* curr){
    std::cout << "========== BANK ==========" << std::endl;
    std::cout << "Hello, " << curr->data.getUsername() << ". This is your transaction history." << std::endl;

    Structs::Transaction* current = curr->transaction; // creates a temporary current pointer

    // traverses through each node of transaction
    while(current != NULL){
        std::cout << "----------------------------------------" << std::endl; 
        std::cout << "Transaction Number   :  " << current->transaction_num << std::endl; 
        std::cout << "Transaction ID       :  " << current->transaction_id << std::endl; 
        std::cout << "Transaction Details  :  " << current->details << std::endl; 
        std::cout << "Transaction Date     :  " << current->date << std::endl; 
        std::cout << "Transaction Amount   :  " << ((current->details == "Deposit") ? '+' : '-') << std::fixed << std::setprecision(2) << current->amount << std::endl; 
        std::cout << "Balance              :  " << std::fixed << std::setprecision(2) << current->new_balance << std::endl; 
        std::cout << "----------------------------------------" << std::endl; 

        current = current->next;
    }
}

void Client::viewPersonalInfo(Structs::Node* curr){
    // output of user details and personal details
    std::cout << "========== BANK ==========" << std::endl;
    std::cout << "Hello, " << curr->data.getUsername() << ". This is your personal info." << std::endl; 

    std::cout << "--------------------------------------------------------" << std::endl; 
    std::cout << "USER INFO: " << std::endl;
    std::cout << "Username    :  " << curr->data.getUsername() << std::endl;
    std::cout << "Password    :  " << curr->data.getPassword() << std::endl;
    std::cout << "User ID     :  " << curr->data.getID() << std::endl;

    if(curr->data.getRole() == "Admin"){
        std::cout << "You are an ADMIN." << std::endl;
    }

    std::cout << "--------------------------------------------------------" << std::endl; 

    std::cout << "--------------------------------------------------------" << std::endl; 
    std::cout << "PERSONAL INFO: " << std::endl;
    std::cout << "Name         :  " << curr->data.getName() << std::endl;
    std::cout << "Age          :  " << curr->data.getAge() << std::endl;
    std::cout << "Birthdate    :  " << curr->data.getBirthdate() << std::endl;
    std::cout << "Contact #    :  " << curr->data.getContactNum() << std::endl;
    std::cout << "Email        :  " << curr->data.getEmail() << std::endl;
    std::cout << "Home Address :  " << curr->data.getAddress() << std::endl;
    std::cout << "TIN Number   :  " << curr->data.getTIN() << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl; 
}

Structs::Node* Client::editPersonalInfo(Structs::Node* curr){
    std::string name, email, contact_num, age, birthdate, address; // variables to store the data into
    const std::string TIN = curr->data.getTIN(); // retrieves the TIN number and assigns it to a constant variable

    std::cout << "========== BANK ==========" << std::endl;
    std::cout << "Hello, " << curr->data.getUsername() << "!" << std::endl;

    std::cout << std::endl;

    std::cout << "INSTRUCTION: Enter the same info if you don't want to change that specific field." << std::endl << std::endl; // instructio nbefore user input
    // important because data might change

    // USER INPUT
    std::cin.ignore();

    std::cout << "Enter new name: "; // full name
    std::getline(std::cin, name);

    std::cout << std::endl;

    std::cout << "Enter new age: "; // age
    std::getline(std::cin, age);

    std::cout << std::endl;

    std::cout << "Enter new birthdate: "; // birthdate
    std::getline(std::cin, birthdate);

    std::cout << std::endl;

    std::cout << "Enter new email: "; // email
    std::getline(std::cin, email);

    std::cout << std::endl;

    std::cout << "Enter new contact number: "; // contact number
    std::getline(std::cin, contact_num);

    std::cout << std::endl;

    std::cout << "Enter new address: "; // home address
    std::getline(std::cin, address);

    std::cout << std::endl;

    int new_age = std::stoi(age); // converts string to integer for age

    curr->data.setPersonalDetails(name, new_age, birthdate, email, contact_num, address, TIN); // madifies personal details

    General::updateFile(curr); // runs the update file

    return curr;
}