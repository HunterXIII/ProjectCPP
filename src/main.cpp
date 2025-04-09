#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "includes/pms.hpp"

// std::vector<Guest> loadGuests() {
//     std::vector<Guest> guests; // создаём массив
//     std::ifstream file("guests.txt"); // создаём файловый поток на чтение
//     std::string line;
//     std::getline(file, line);
//     while (std::getline(file, line)) {
//         std::stringstream ss(line);

//         char delim;
//         u_int64_t id;
//         std::string fname;
//         std::string sname;
//         std::string phone;
//         std::string email;
//         u_int64_t passport;
//         std::string date;
//         u_int loyalPoint;

//         ss >> id >> delim;
//         std::getline(ss, fname, ',');
//         std::getline(ss, sname, ',');
//         std::getline(ss, phone, ',');
//         std::getline(ss, email, ',');
//         ss >> passport >> delim;
//         std::getline(ss, date, ',');
//         ss >> loyalPoint;

//         DateTime dateObj;
//         dateObj.string_to_date(date);
//         Guest guest(id, fname, sname, phone, email, passport, dateObj, loyalPoint);
//         guests.push_back(guest);
        
//     }

//     return guests;           

// }

int main() {
    // auto guests = loadGuests(); // массив гостей 
    // for (auto guest : guests) {
    //     guest.showInfo();
    // }
    DateTime date(2025, 4, 9, 9);
    std::cout << date.toString() << std::endl; 
    return 0;
}