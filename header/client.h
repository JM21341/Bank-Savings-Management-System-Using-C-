#ifndef CLIENT_H
#define CLIENT_H

#include "structs.h"

namespace Client{
    // General
    bool clientControls(Structs::Node* curr);
    void updateTransactionFile(Structs::Node* curr);

    // Transaction
    void checkSavings(Structs::Node* curr);
    void viewTransactionHistory(Structs::Node* curr);
    Structs::Node* deposit(Structs::Node* curr);
    Structs::Node* withdraw(Structs::Node* curr);

    // Personal Info
    void viewPersonalInfo(Structs::Node* curr);
    Structs::Node* editPersonalInfo(Structs::Node* curr);
}

#endif