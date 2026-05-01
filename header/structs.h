#ifndef STRUCTS_H
#define STRUCTS_H

#include "classes.h"

namespace Structs{
    struct Transaction{
        int transaction_num;
        std::string transaction_id, details, date;
    };

    struct Node{
        Classes::User data;
        Transaction transaction;
        Node* next;
    };
}

#endif