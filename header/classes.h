#ifndef CLASSES_H
#define CLASSES_H

#define MAX_CONTACT 5

#include <string>

namespace Classes{
    class User{
        private:
            // importang details
            std::string role;
            std::string username;
            std::string password;

            // personal details
            std::string full_name;
            int age;
            std::string birthdate;
            std::string email[MAX_CONTACT];
            std::string contact_number[MAX_CONTACT];

            // private details
            std::string home_address;
            std::string TIN_number;
            
            // bank details
            double balance;
            std::string bank_number;
            std::string ID;

        public:
            // GETTERS AND SETTERS
            // getters
            std::string getUsername() const { return username; } // retrieves username
            std::string getPassword() const { return password; } // retrieves password

            // setters
            void setLoginDetails(std::string& username, std::string& password, std::string role, std::string& user_id){
                this->username = username; // sets username
                this->password = password; // sets password
                this->role = role;
                ID = user_id; // sets ID
            }
    };


}

#endif