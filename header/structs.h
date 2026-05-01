#ifndef STRUCTS_H
#define STRUCTS_H

#include "classes.h"

namespace Structs{
    struct Node{
        Classes::User data;
        Node* next;
    };
}

#endif