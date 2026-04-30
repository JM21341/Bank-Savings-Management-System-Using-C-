#ifndef GENERAL_H
#define GENERAL_H

#include <string>
#include "structs.h"

namespace General{
    Structs::Node* readDataFromFile(Structs::Node* temp_head);
    std::string login(Structs::Node* head);
}

#endif