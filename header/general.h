#ifndef GENERAL_H
#define GENERAL_H

#include <string>
#include "structs.h"

namespace General{
    Structs::Node* readDataFromFile(Structs::Node* temp_head); // returns head
    Structs::Node* login(Structs::Node* head); // returns the user role
    void wait(int seconds);
    bool askToContinue();
}

#endif