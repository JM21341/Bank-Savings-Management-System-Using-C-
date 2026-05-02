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
                        break;
                    case 2:
                        curr = Client::deposit(curr);
                        break;
                    case 3:
                        curr = Client::withdraw(curr);
                        break;
                    case 4:
                        Client::viewTransactionHistory(curr);
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
                        break;
                    case 2:
                        curr = Client::editPersonalInfo(curr);
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
}