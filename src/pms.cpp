#include <iostream>
#include <sstream>
#include "includes/pms.hpp"

void Guest::setFirstName(std::string name) {
    // тут типо проверки
    this->firstName = name; // this == self
}

void Guest::setSecondName(std::string name) {
    secondName = name;
}

void Guest::setPhone(std::string phoneNum) {
    phone = phoneNum;
}

void Guest::setPassport(u_int64_t passportNum) {
    passport = passportNum;
}

std::string Guest::getFullName(){
    return firstName + secondName;
}

void Guest::showInfo() {
    std::cout << "ID: " << this->id << std::endl;
    std::cout << "Имя: " << this->firstName << std::endl;
    std::cout << "Фамилия: " << this->secondName << std::endl;
    std::cout << "Номер телефона: " << this->phone << std::endl;
    std::cout << "Email: " << this->email << std::endl;
    std::cout << "Номер паспорта: " << this->passport << std::endl;
    std::cout << "Дата рождения: " << this->date.toString() << std::endl;
    std::cout << "Бонусы: " << this->loyalPoint << std::endl;
    std::cout << std::endl;
}

// Реализация конструктора
Guest::Guest(
        u_int64_t id,
        std::string fname,
        std::string sname,
        std::string phone,
        std::string email,
        u_int64_t passport,
        DateTime date,
        u_int loyalPoint
    ) {
    this->id = id;
    this->firstName = fname;
    this->secondName = sname;
    this->phone = phone;
    this->email = email;
    this->passport = passport;
    this->date = date;
    this->loyalPoint = loyalPoint;
}


DateTime::DateTime(int64 sec=0) : seconds(sec) {};

DateTime::DateTime(
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

std::string DateTime::toString() {
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

