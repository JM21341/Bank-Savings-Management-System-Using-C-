#include <iostream>
#include <cstdlib> // for system("cls")
#include <filesystem> // for rename() and delete()
#include <fstream> // for ofstream
#include <sstream> // for stringstream

#include "../header/client.h"
#include "../header/general.h"

void Client::updateTransactionFile(Structs::Node* curr){
    std::stringstream filename; // for filename
    filename << "../records/transaction_database/" << curr->data.getUsername() << ".csv"; // sets the filename to the directory of the specific transaction database

    std::string file_path = filename.str(); // converts the variable from a stringstream to string

    std::ofstream file("../records/transaction_database/temp.csv"); // opens the directory

    // checks if file is open
    if(!file.is_open()){
        std::cerr << "File was not created in updateFile" << std::endl;
        return;
    }

    // writes to that file until the current transaction in the history is NULL
    // traverses through each node and writes the data from it to the file
    while(curr->transaction != NULL){
        file << curr->transaction->transaction_num << "," << 
            curr->transaction->transaction_id << "," << 
            curr->transaction->details << "," << 
            curr->transaction->date << "," << 
            curr->transaction->amount << "," << 
            curr->transaction->new_balance << "," << 
            std::endl;

        curr->transaction = curr->transaction->next;
    }

    std::filesystem::remove(file_path);
    std::filesystem::rename("../records/transaction_database/temp.csv", file_path);

    file.close();
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

        std::cout << "Select an item: " << std::endl;
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

                std::cout << "Select an item: " << std::endl;
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

                std::cout << "Select an item: " << std::endl;
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
    std::cout << "Hello, " << curr->data.getUsername() << std::endl;
    std::cout << "This is your current balance: " << curr->data.getBalance() << std::endl;

    return;
}

Structs::Node* Client::deposit(Structs::Node *curr){
    double amount = 0;
    bool cont = true;

    do{
        std::cout << "========== BANK ==========" << std::endl;
        std::cout << "Hello, " << curr->data.getUsername() << std::endl << std::endl;

        std::cout << "Enter deposit amount: " ;
        std::cin >> amount;

        if(amount >= 0){
            curr->data.modifyBalance(amount, "Deposit");
            cont = false;
        } else{
            std::cout << "Invalid amount." << std::endl;
        }

        General::wait(2);
        system("cls");
    } while(cont);

    std::string date;

    std::cout << "Enter date(MM/DD/YYYY): ";
    std::getline(std::cin, date);

    Structs::Transaction* temp;
    temp->date = date;
    temp->amount = amount;
    temp->new_balance = curr->data.getBalance();
    temp->details = "Deposit";
    temp->next = NULL;

    if(curr->transaction == NULL){
        temp->transaction_num = 1;

        std::stringstream id;
        id << "DEPO" << temp->transaction_num;
        std::string new_id = id.str();
        temp->transaction_id = new_id;

        curr->transaction = temp;
    } else{
        Structs::Transaction* current_trans = curr->transaction;
        while(current_trans->next != NULL) current_trans = current_trans->next;

        temp->transaction_num = current_trans->transaction_num + 1;

        std::stringstream id;
        id << "DEPO" << temp->transaction_num;
        std::string new_id = id.str();
        temp->transaction_id = new_id;

        current_trans->next = temp;
    }

    General::updateFile(curr);

    Client::updateTransactionFile(curr);

    return curr;
}

Structs::Node* Client::withdraw(Structs::Node *curr){
    double amount = 0;
    bool cont = true;
    int i = 0;

    do{
        std::cout << "========== BANK ==========" << std::endl;
        std::cout << "Hello, " << curr->data.getUsername() << std::endl << std::endl;

        std::cout << "Input 0 if you want to go back" << std::endl << std::endl;
        std::cout << "Enter withdraw amount: " ;
        std::cin >> amount;

        if(amount > 0 && amount <= curr->data.getBalance()){
            curr->data.modifyBalance(amount, "Withdraw");
            cont = false;
        } else if(i <= 5 && amount > curr->data.getBalance()){
            std::cout << "Invalid amount. Not enough balance." << std::endl;
        } else if(amount == 0) break;
        else{
            std::cout << "Invalid input! Please try again." << std::endl;
        }

        General::wait(2);
        system("cls");
    } while(cont);

    std::string date;

    std::cout << "Enter date: ";
    std::getline(std::cin, date);

    Structs::Transaction* temp;
    temp->date = date;
    temp->amount = amount;
    temp->new_balance = curr->data.getBalance();
    temp->details = "Withdraw";
    temp->next = NULL;

    if(curr->transaction == NULL){
        temp->transaction_num = 1;

        std::stringstream id;
        id << "WTDR" << temp->transaction_num;
        std::string new_id = id.str();
        temp->transaction_id = new_id;

        curr->transaction = temp;
    } else{
        Structs::Transaction* current_trans = curr->transaction;
        while(current_trans->next != NULL) current_trans = current_trans->next;

        temp->transaction_num = current_trans->transaction_num + 1;

        std::stringstream id;
        id << "WTDR" << temp->transaction_num;
        std::string new_id = id.str();
        temp->transaction_id = new_id;

        current_trans->next = temp;
    }

    General::updateFile(curr);

    Client::updateTransactionFile(curr);

    return curr;
}

void Client::viewTransactionHistory(Structs::Node* curr){
    std::cout << "========== BANK ==========" << std::endl;
    std::cout << "Hello, " << curr->data.getUsername() << ". This is your transaction history." << std::endl;

    while(curr->transaction != NULL){
        std::cout << "----------------------------------------" << std::endl; 
        std::cout << "Transaction Number   :  " << curr->transaction->transaction_num << std::endl; 
        std::cout << "Transaction ID       :  " << curr->transaction->transaction_id << std::endl; 
        std::cout << "Transaction Details  :  " << curr->transaction->details << std::endl; 
        std::cout << "Transaction Date     :  " << curr->transaction->date << std::endl; 
        std::cout << "Transaction Amount   :  " << ((curr->transaction->details == "Deposit") ? '+' : '-') << curr->transaction->amount << std::endl; 
        std::cout << "Balance              :  " << curr->transaction->transaction_num << std::endl; 
        std::cout << "----------------------------------------" << std::endl; 
    }
}

void viewPersonalInfo(Structs::Node* curr){
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
    std::cout << "Contact #    :  " << curr->data.getBirthdate() << std::endl;
    std::cout << "Email        :  " << curr->data.getBirthdate() << std::endl;
    std::cout << "Home Address :  " << curr->data.getBirthdate() << std::endl;
    std::cout << "TIN Number   :  " << curr->data.getBirthdate() << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl; 
}

Structs::Node* editPersonalInfo(Structs::Node* curr){
    std::string name, email, contact_num, age, birthdate, address;
    const std::string TIN = curr->data.getTIN();
    std::cout << "========== BANK ==========" << std::endl;
    std::cout << "Hello, " << curr->data.getUsername() << "!" << std::endl;

    std::cout << std::endl;

    std::cout << "INSTRUCTION: Enter the same info if you don't want to change that specific field." << std::endl << std::endl;

    std::cout << "Enter new name: ";
    std::getline(std::cin, name);

    std::cout << std::endl;

    std::cout << "Enter new age: ";
    std::getline(std::cin, age);

    std::cout << std::endl;

    std::cout << "Enter new birthdate: ";
    std::getline(std::cin, birthdate);

    std::cout << std::endl;

    std::cout << "Enter new email: ";
    std::getline(std::cin, email);

    std::cout << std::endl;

    std::cout << "Enter new contact number: ";
    std::getline(std::cin, contact_num);

    std::cout << std::endl;

    std::cout << "Enter new address: ";
    std::getline(std::cin, address);

    std::cout << std::endl;

    int new_age = std::stoi(age);

    curr->data.setPersonalDetails(name, new_age, birthdate, email, contact_num, address, TIN);

    General::updateFile(curr);

    return curr;
}