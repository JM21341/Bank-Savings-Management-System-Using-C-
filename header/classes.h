#ifndef CLASSES_H
#define CLASSES_H

#define MAX_CONTACT 5

#include <string>

namespace Classes{
    class User{
        protected:
            // important details
            std::string role;
            std::string username;
            std::string password;

            // personal details
            std::string full_name;
            int age;
            std::string birthdate;
            std::string email;
            std::string contact_number;

            // private details
            std::string home_address;
            std::string TIN_number;
            
            // bank details
            double balance;
            std::string ID;

        public:
            // GETTERS AND SETTERS
            // getters
            std::string getUsername() const { return username; } // retrieves username
            std::string getPassword() const { return password; } // retrieves password
            std::string getRole() const { return role; } // retrieves role(admin/client)
            double getBalance() const{ return balance; } // retrieves balance

            // for replacement && viewing of personal info
            std::string getName() const{ return full_name; } 
            int getAge() const{ return age; } 
            std::string getBirthdate() const{ return birthdate; } 
            std::string getEmail() const{ return email; } 
            std::string getContactNum() const{ return contact_number; } 
            std::string getAddress() const{ return home_address; } 
            std::string getTIN() const{ return TIN_number; } 
            std::string getID() const{ return ID; }

            // setters
            void setLoginDetails(std::string& username, std::string& password, std::string role, std::string& user_id){
                this->username = username; // sets username
                this->password = password; // sets password
                this->role = role;
                ID = user_id; // sets ID
            }

            void setBalance(double& balance){
                this->balance = balance; 
            }

            void setPersonalDetails(std::string& name, int& age, std::string& birthdate, std::string& email, std::string& contact_number, std::string& home_address, std::string TIN){
                full_name = name;
                TIN_number = TIN;
                this->age = age;
                this->birthdate = birthdate;
                this->email = email;
                this->contact_number = contact_number;
                this->home_address = home_address;
            }

            // METHODS
            // modifies balance
            void modifyBalance(double amount, std::string purpose){
                if(purpose == "Deposit") balance += amount;
                else if(purpose == "Withdraw") balance -= amount;
            }
    };
}

#endif