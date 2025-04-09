// property management system
#pragma once
#include <string>

typedef unsigned long long int64; 

class DateTime {
private:
    int64 seconds;

public:
    DateTime(int64 sec=0) : seconds(sec) {};
    DateTime(
        u_int year,
        u_int month,
        u_int day,
        u_int hours=0,
        u_int minutes=0,
        u_int seconds=0
    ):
        seconds((year - 1970) * 31536000
                + (month - 1) * 2592000 
                + (day - 1)  * 86400
                + hours * 3600
                + minutes * 60
                + seconds
        ) {};
    
    std::string toString() {
        int64 tmp = seconds;
        u_int year = tmp / 31536000 + 1970;
        tmp %= 31536000;
        u_int month = tmp / 2592000 + 1;
        tmp %= 2592000;
        u_int day = tmp / 86400 + 1;
        tmp %= 86400;
        u_int hours = tmp / 3600;
        tmp %= 3600;
        u_int minutes = tmp / 60;

        char result[20];
        snprintf(result, 20, "%04d-%02d-%02d %02d:%02d", year, month, day, hours, minutes);
        return std::string(result);
    }
    void string_to_date(std::string str) {
        std::stringstream ss(str);

        u_int year;
        u_int month;
        u_int day;
        u_int hours = 0;
        u_int minutes = 0;
        u_int seconds = 0;

        char delim;
        ss >> year >> delim;
        ss >> month >> delim;
        ss >> day >> delim;
        ss >> hours >> delim;
        ss >> minutes >> delim;
        
        
    }
};

class Guest {
private: // модификатор доступа
    u_int64_t id;
    std::string firstName; // свойства/поле
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

