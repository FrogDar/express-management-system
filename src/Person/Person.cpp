#include "Person.h"

#include <fstream>
#include <iostream>

#include "User.h"
PersonType Person::getType() { return type; }

void Person::setBalance(double balance) {
    this->balance = balance;
    this->save();
}
double Person::getBalance() { return balance; }

void Person::setUsername(string username) {
    this->username = username;
    this->save();
}
string Person::getUsername() { return username; }

void Person::setNickname(string nickname) {
    this->nickname = nickname;
    this->save();
}
string Person::getNickname() { return nickname; }

void Person::setPassword(string password) {
    this->password = password;
    this->save();
}
bool Person::checkPassword(string password) {
    return this->password == password;
}

void Person::save() {
    std::ofstream out(USER_DIR + username + ".txt");
    if (out.is_open()) {
        out << int(type) << std::endl;
        out << username << std::endl;
        out << nickname << std::endl;
        out << password << std::endl;
        out << balance << std::endl;
        out.close();
    } else {
        std::cout << "[Person::save()]Error: Could not open file " + USER_DIR +
                         username + ".txt"
                  << std::endl;
    }
}

Person::Person(ifstream& in) {
    in >> username;
    in >> nickname;
    in >> password;
    in >> balance;
}

Person* Person::load(string file) {
    Person* person = nullptr;
    std::ifstream in(file);
    if (in.is_open()) {
        int _type;
        in >> _type;

        PersonType type{_type};

        switch (type) {
            case PersonType::USER:
                person = new User(in);
                break;
        }
        in.close();
    } else {
        std::cout << "[Person::load()]Error: Could not open file " + file
                  << std::endl;
    }
    return person;
}

/**
 * @brief 用户基本信息
 * 包括用户类型、用户名、姓名、余额等信息
 * @return string 用户基本信息
 */
string Person::toString() {
    string str = "";
    switch (type) {
        case PersonType::USER:
            str += "USER";
            break;
        case PersonType::ADMIN:
            str += "ADMIN";
            break;
        default:
            str += "UNKNOWN";
            break;
    }
    str += '\t';
    str += username + '\t';
    str += nickname + '\t';
    str += std::to_string(balance);
    return str;
}