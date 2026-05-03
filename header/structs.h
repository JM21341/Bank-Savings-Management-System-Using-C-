#ifndef STRUCTS_H
#define STRUCTS_H

#include "classes.h"
#include <string>

namespace Structs{
    struct Transaction{
        int transaction_num;
        std::string transaction_id, details, date;
        double amount, new_balance;
        Transaction* next;
    };

    struct Node{
        Classes::User data;
        Transaction* transaction;
        Node* next;
    };
}

#endif