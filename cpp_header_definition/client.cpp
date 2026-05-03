#include <iostream>
#include <cstdlib> // for system("cls")

#include "../header/client.h"
#include "../header/general.h"

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

    General::updateFile(curr);

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

    General::updateFile(curr);

    return curr;
}