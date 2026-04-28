# Bank Savings Management System Using C++

## Table Of Contents

1. Pre-Creation
    > 1.1. Introduction \
    > 1.2. Contents \
    > 1.3. Planning \
    > 1.4. Program Flow
2. Creatiom
    > 2.1. How The Topic and Concept Applies \
    > 2.2. Modularization and File Systems \
    > 2.3. Code Explanation \
    > 2.4. Errors Faced \
    > 2.5. Experiences
3. Post-Creation
    > 3.1. Conclusion \
    > 3.2. Problems faced \
    > 3.3. Reflection \
    > 3.4. Recommendations 

## Chapter 1 : Pre-Creation

### Introduction

This project serves as a practice for my software engineering career. This will be my first biggest project and repository. This may serve as a guideline for beginners or may also be used a source for those who wishes for this. This README will serve as the documentation of the project, showing how the developer planned, made and tested the project. Note that this project also uses AI as a tool for suggestions and checking for mistakes not seen by the programmer.

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
5. Conesole-Based Approach
6. Menu-driven Program

### Planning

#### How the program operates:

- The program will use a menu-driven approach, meaning the user must input a choice in order for the program to proceed.
- Classes will be used to determine the type of users and seperate the functions by methods.
- Linked lists nodes will be used to define users.
- There will be two types of users: client and admin.
- The CLIENT may use three operations: Transaction (check savings, deposit, withdraw, view transaction history); Personal Info(view info, edit info); and Inbox (check inbox, view messages, send inbox).
- The ADMIN may use three operations: Transaction (check savings, deposit, withdraw, view transaction history); Personal Info(view info, edit info); Inbox (check inbox, view messages, send inbox); and Admin Controls (add user, remove user, view all users, view user, view logs).

#### Program Flow

### START
1. Run login() function
2. Determine user (Admin or Client)
3. Run while isExit == true
    > 3.3. If user == admin, then go to Admin Controls \
    > 3.2. If user == client, then go to Client Controls \
    > 3.3. Else, print "Invalid username. Try again." \
    > 3.4. Break if isExit == true 
4. Print "Thank you"
### END

