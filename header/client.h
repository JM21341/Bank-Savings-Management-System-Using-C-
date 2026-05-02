#ifndef CLIENT_H
#define CLIENT_H

#include "structs.h"

namespace Client{
    bool clientControls(Structs::Node* curr);

    // Transaction
    void viewTransactionHistory(Structs::Node* curr);
    void deposit(Structs::Node* curr);
    void withdraw(Structs::Node* curr);
    void checkSavings(Structs::Node* curr);

    // Personal Info
    void viewPersonalInfo(Structs::Node* curr);
    void editPersonalInfo(Structs::Node* curr);
}

#endif