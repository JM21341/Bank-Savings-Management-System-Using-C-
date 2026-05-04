# Bank Savings Management System Using C++

## Table Of Contents

### Chapters
1. Pre-Creation
    > 1.1. Introduction \
    > 1.2. Contents \
    > 1.3. Planning 
    >> 1.3.1. How the Program Operates \
    >> 1.3.2. Program Flow
2. Development
    > 2.1. How The Topic and Concept Applies \
    > 2.2. Code Explanation \
    > 2.3. Errors Faced \
    > 2.4. Experiences
3. Post-Creation
    > 3.1. Conclusion \
    > 3.2. Problems faced \
    > 3.3. Reflection \
    > 3.4. Recommendations 

## Chapter 1 : Pre-Creation

### Introduction

This project serves as a practice for my software engineering career. This will be my first biggest project and repository. This may serve as a guideline for beginners or may also be used a source for those who wishes for this. This README will serve as the documentation of the project, showing how the developer planned, made and tested the project. Note that this project also uses AI as a tool for suggestions and checking for mistakes not seen by the programmer. The AI tool that will be used in this program are: Claude, CoPilot, and ChatGPT.

### Contents

#### This program includes the following topics:

1. Basic I/O in C++
2. Variables and Data Types
3. Arithmetic, Relational and Logical Operators
4. Conditional Statements
5. Loops and Control Statements
6. Functions 
7. Arrays 
8. Strings
9. Pointers and Memory Allocation
10. Structs
11. File Handling
12. Objects and Classes
13. Namespaces

#### This program may also include the following concepts:

1. Function modularization
2. Basic Object-Oriented Programming
3. Linked Lists
4. Algorithms
5. Console-Based Approach
6. Menu-driven Program
7. File-Based Records Management System
8. Testing and Debugging

### Planning

#### How the program operates:

- The program will use a menu-driven approach, meaning the user must input a choice in order for the program to proceed.
- Classes will be used to determine the type of users and seperate the functions by methods.
- Linked lists nodes will be used to store users.
- There will be two types of users: client and admin.
- The CLIENT may use three operations: Transaction (check savings, deposit, withdraw, view transaction history); Personal Info(view info, edit info); and Inbox (check inbox, view messages, send inbox).
- The ADMIN may use three operations: Transaction (check savings, deposit, withdraw, view transaction history); Personal Info(view info, edit info); Inbox (check inbox, view messages, send inbox); and Admin Controls (add user, remove user, view all users, view user, view logs).

#### Program Flow

### START
1. Run login() function
2. Determine user (Admin or Client)
3. Run while isExit == true
    > 3.1 . If user == admin, then go to Admin Controls \
    > 3.2. If user == client, then go to Client Controls \
    > 3.3. Else, print "Invalid username. Try again." \
    > 3.4. Break if isExit == true 
4. Print "Thank you"
### END

## Chapter 2 : Development

 > 2.1. How The Topic and Concept Applies \
> 2.2. Modularization and File Systems \
> 2.3. Code Explanation \
> 2.4. Errors Faced \
> 2.5. Experiences

### How the Topic and Concept Applies

#### TOPICS

1. Basic I/O in C++ 
    > 1.1. Used basic output for user interface \
    > 1.2. Used basic input for the user's selection \
    > 1.3. Basic output for error handling \
    > 1.4. Basic user input of strings and non-string literals 
2. Variables and Data Types
    > 2.1. Used in storing values \
    > 2.2. Used as a temporary storage \
    > 2.3. Used in determining return types \
    > 2.4. Used in storing user input \
    > 2.5. Used for program output
3. Arithmetic, Relational and Logical Operators
    > 3.1. Arithmetic operators are used to calculate balance after transactions \
    > 3.2. Relational operators are used in error handling, input validation, and basic program flow \
    > 3.3. Logical operators are used to determine two conditions, mostly in error handling and input validation 
4. Conditional Statements
    > 4.1. If...else conditionals are used error handling, input validation and output verification \
    > 4.2. Switch...case statements are used in determining user selection in the menu of choices \
    > 4.3. If...else if...else are used in determining many conditions, like in withdraw() function, etc. 
5. Loops and Control Statements
    > 5.1. Do...while loop was used in repeating the menu interface until user logouts or exits. \
    > 5.2. While loop is used in non-iterable instances, like traversing through the lists and getting each line in a file \
    > 5.3. Break statement was used to break a loop or exit the program. 
6. Functions 
    > 6.1. Functions were used to split tasks into smaller code \
    > 6.2. Used to make the code shorter 
7. Arrays 
    > 7.1. NOT used in the program, since mostly, linked lists are used 
8. Strings
    > 8.1. Used string literals \
    > 8.2. Used stringstream literals \
    > 8.3. Manipulated strings using stringstream 
9. Pointers and Memory Allocation
    > 9.1. Used for allocating memory for nodes and lists 
10. Structs
    > 10.1. Used in defining a User 
11. File Handling
    > 11.1. Reading data from files at the start of the program \
    > 11.2. Saving changes to file 
12. Objects and Classes
    > 12.1. Used objects to define the data of clients and used getters and setters to assign them 
13. Namespaces
    > 13.1. Used in breaking down the modularization in one namespace each header file

#### CONCEPTS

1. Function modularization 
    > 1.1. Tasks are split into function/modules \
    > 1.2. Functions are defined in different header files 
2. Basic Object-Oriented Programming
    > 2.2. Used classes in defining user data \
    > 2.3. Used setters and getters to retrieve and assign values \
    > 2.4. Used methods in classes
3. Linked Lists
    > 3.1. Major data structure in the program \
    > 3.2. Traversing through a lists to find a node with an empty link, write each data of a node to a file, etc.
4. Algorithms
    > 4.1. Algorithm in updating files \
    > 4.2. Algorithms in editing user info
5. Console-Based Approach
    > 5.1. Program used a console interface, instead of a GUI.
6. Menu-driven Program
    > 6.1. Tasks are seperated and shown in a menu
7. File-Based Records Management System
    > 7.1. Savings records \
    > 7.2. Updating records \
    > 7.3. Reading records
8. Testing and Debugging   
    > 8.1. Error handling in functions

### Code Explanation

### PREREQUISITE REQUIREMENTS: 

#### The following is what you might need in running this program:

Note: This prerequisites are based from what I have and used. This program may or may not run for you who has a different compiler.

#### Requirements:
1. Clang++ Compiler
2. Clangd LLVM
3. CMake
4. Local Code Editor
5. MSYS2 and/or MINGW

#### Compiler Setting Requirements:

### c_cpp_properties.json:

```
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**",
                "C:\\msys64\\ucrt64\\include\\c++\\15.2.0",
                "C:\\msys64\\ucrt64\\include\\c++\\15.2.0\\x86_64-w64-mingw32",
                "C:\\msys64\\ucrt64\\include\\c++\\15.2.0\\backward",
                "C:\\msys64\\ucrt64\\include",
                "C:\\msys64\\ucrt64\\lib\\gcc\\x86_64-w64-mingw32\\15.2.0\\include",
                "C:\\msys64\\ucrt64\\lib\\gcc\\x86_64-w64-mingw32\\15.2.0\\include-fixed"
            ],
            "defines": ["_DEBUG", "UNICODE", "_UNICODE"],
            "compilerPath": "C:\\msys64\\ucrt64\\bin\\g++.exe",
            "intelliSenseMode": "gcc-x64",
            "cppStandard": "c++17",
            "cStandard": "c17"
        }
    ],
    "version": 4
}
```

### tasks.json:

```
{
    "version": "2.0.0",
    "tasks": [
        {
            "type": "shell",
            "label": "C/C++: clang++ build active file",
            "command": "C:/msys64/ucrt64/bin/clang++.exe",
            "args": [
                "-std=c++17",
                "-g",
                "-static",
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": ["$gcc"],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        },
        {
            "label": "C/C++: build and run",
            "type": "shell",
            "command": "/ucrt64/bin/clang++ -std=c++17 -static -g '${fileDirname}'/*.cpp -o '${fileDirname}/${fileBasenameNoExtension}.exe' && '${fileDirname}/${fileBasenameNoExtension}.exe'",
            "options": {
                "cwd": "${fileDirname}",
                "shell": {
                    "executable": "C:\\msys64\\usr\\bin\\bash.exe",
                    "args": ["-l", "-c"]
                }
            },
            "problemMatcher": ["$gcc"],
            "group": "build"
        }
    ]
}
```

### launch.json:

```
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "C/C++: clang++ build and run",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": true,
            "MIMode": "gdb",
            "miDebuggerPath": "C:\\msys64\\ucrt64\\bin\\gdb.exe",
            "miDebuggerArgs": "--interpreter=mi2",
            "preLaunchTask": "C/C++: clang++ build active file"
        }
    ]
}
```

### settings.json:

```
{
    "C_Cpp.intelliSenseEngine": "disabled",
    "clangd.path": "C:\\msys64\\ucrt64\\bin\\clangd.exe",
    "files.associations": {
        "*.h": "cpp"
    },
}
```

### compile_flags.txt

#### 1. Go to the global directory 
##### Example: C:\C++-Projects

#### 2. Create compile_flags.txt

#### 3. Enter the following:

```
-std=c++17
-x
c++
-IC:/msys64/ucrt64/include/c++/15.2.0
-IC:/msys64/ucrt64/include/c++/15.2.0/x86_64-w64-mingw32
-IC:/msys64/ucrt64/include
```

#### 4. Save changes

### CODE EXPLANATION

1. The program starts off with including all the header files and the iostream standard library.
```
#include <iostream>
#include "../header/structs.h"
#include "../header/general.h"
#include "../header/client.h"
```

2. Inside the main function, a variable was declared for the loop

``` bool cont = true; ```

3. We then create a head node which points to the first user in the list. After that the program reads the data from the file.

``` 
Structs::Node* head = NULL; 

head = General::readDataFromFile(head); 
```

Inside the function, it is complex, which is why I made it as abstract as possible in the main function. First, we check for an error (if a user is already existing)

``` 
    if(head != NULL){
        std::cout << "Something went wrong. Data already pre-exists in the program before running." << std::endl;
        return NULL;
    }
```

We then open the program for reading. Then, we check for any errors.
std::string line, line2;

```
    std::ifstream file("C:\\C++ Projects\\Projects\\Console-Based_Bank_Savings_Management_System\\records\\user.csv"); 

    if(!file.is_open()){
        std::cerr << "File user.csv did not open in readDataFromFile." << std::endl;
        return NULL;
    }
```

We then declare a while loop to move through each line. For each line, there is a user. The program stores the data from the file inside temporary variables in the function. A temporary node was then created, then the values for that instance of an object was created.

```
while(std::getline(file, line)){
        std::stringstream ss(line);
        std::string ID, username, password, role;

        std::getline(ss, ID, ',');
        std::getline(ss, username, ',');
        std::getline(ss, password, ',');
        std::getline(ss, role, ',');

        Structs::Node* temp = new Structs::Node(); // creates a temp node
        temp->next = NULL; 

        temp->data.setLoginDetails(username, password, role, ID);
```

We then create another file for the personal details. Same thing for error handling and reading each line.

```
        std::stringstream filename; 
        filename << "C:\\C++ Projects\\Projects\\Console-Based_Bank_Savings_Management_System\\records\\user_database\\" << username << ".txt";
        
        std::string final_path = filename.str(); 
        std::string full_name, birthdate, email, contact_number, home_address, TIN_number, bank_number;
        std::string age_str, balance_str;
        
        std::ifstream file2(final_path);

        if(!file2.is_open()){
            std::cerr << "Something went wrong. Path does not exist for the user " << username << ".";
            break;
        }

        while(std::getline(file2, line2)){
            std::stringstream ss2(line2);

            std::getline(ss2, full_name, ',');
            std::getline(ss2, age_str, ',');
            std::getline(ss2, birthdate, ',');
            std::getline(ss2, balance_str, ',');
            std::getline(ss2, contact_number, ',');
            std::getline(ss2, email, ',');
            std::getline(ss2, home_address, ',');
            std::getline(ss2, TIN_number, ',');
        }
```

We use a ternary operator to check for the values. It checks whether the string is empty. If yes, the default value is 0 balance. If not, it converts the data from the file into their own respective data types.

```
        int age = age_str.empty() ? 0 : std::stoi(age_str);
        double balance = balance_str.empty() ? 0.0 : std::stod(balance_str); 
```

After all that, we then close the second file.

        ``` file2.close(); ```

We then assign the attributes of the class values. The values will be from the variables that was used as a storage when reading the file.

```
        temp->data.setBalance(balance);
        temp->data.setPersonalDetails(full_name, age, birthdate, email, contact_number, home_address, TIN_number);
```

Same thing goes for the readTransactionFromRecord(). I just made it so that the code doesn't get more longer.

``` temp->transaction = readTransactionFromRecord(temp); ```

After that, we link the head to the temporary node OR find a node who has an empty link and set its link to the temporary node.

```
        if(head == NULL){
            head = temp; // sets the head ptr to the temp
        } else{
            Structs::Node* curr = head; // creates a temp ptr which traverses through each node
            while(curr->next != NULL) curr = curr->next; // search for a node which doesn't have a next link
            curr->next = temp; // sets the link of that node to the temp
        }
```

We then close the first file after the loop and return head.

```
    }

    file.close(); // closes user.csv

    return head;

```

4. We go back to the main function. After setting up the head node, we let the user log in. This is the first interface the user sees. We will wrap the flow first inside a do...while loop so the login will continue as long as cont/logout is true.

```
    do{
        Structs::Node* curr = General::login(head); 

        if(!cont) break;
```

We create a node named curr, which stores the user details from the login() function. This is important so that we know which node this user is. Inside the login function are as follows:

```
    std::string username, password; 
    bool found = false; 

    Structs::Node* curr = head; // create a temporary node
```
 
We create a variable for the user input of username and password. We also created a bool type variable named "found" so the loop will end until a user is found. We then create another temporary node curr which will store all the lists for the traversal.

```
    do{
        std::cout << "Enter username: ";
        std::getline(std::cin, username);
        
        std::cout << std::endl << "Enter password: ";
        std::getline(std::cin, password);
```

Inside a do...while loop, the user inputs their username and password.

We then traverse through each node in the lists. If there are any same username and password as the user typed, the found variable becomes true and the loop for traversal ends. It will continue until the curr is NULL.

```
        while(curr != NULL){
            // if the username and password is correct, print a prompt, set found to true then break the loop
            if(username == curr->data.getUsername() && password == curr->data.getPassword()){
                std::cout << "You have successfully logged in." << std::endl;
                found = true;
                break;
            }

            curr = curr->next; // moves to the next node
        }
```

If the user is not found, it will print that it wasn't able to find the username with the same password in the lists.

```
        if(!found){
            std::cout << "Incorrect username and/or password. Please try again." << std::endl;
            continue;
        }
    } while(!found);

    return curr;
```

The loop will continue until the found is true. After the loop ends, we return curr since that is the user who logged in. Going back to main, there is a condition wherein it'll check the role of the user. If the user is a client, run the clientControls() function, which is already explained.

```
        if(curr->data.getRole() == "Client"){ 
            cont = Client::clientControls(head); // for user controls such as transactions, edit personal info, etc.
        }
        else{
            std::cout << "An error occurred in determining the user role." << std::endl;
            break;
        }
    } while(cont);
```

5. Program then exits. The head is freed from the memory.

```
   std::cout << "Exiting..." << std::endl;

    delete(head);

    return 0;
```