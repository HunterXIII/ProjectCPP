#pragma once
#include <string>
#include "DateTime.hpp"

class Guest {
private: 
    u_int64_t id;
    std::string firstName; 
    std::string secondName;
    std::string phone;
    std::string email;
    u_int64_t passport;
    DateTime date;
    u_int loyalPoint;
    
public:
    Guest(
        u_int64_t id,
        std::string fname,
        std::string sname,
        std::string phone,
        std::string email,
        u_int64_t passport,
        DateTime date,
        u_int loyalPoint
    ); //конструктор

    void setFirstName(std::string);
    void setSecondName(std::string);
    void setPhone(std::string);
    void setPassport(u_int64_t);

    std::string getFullName();
    void showInfo();
};
