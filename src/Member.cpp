#include "Member.h"
#include "Utility.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

Member::Member() : memberID(0) {}

Member::Member(int id, std::string n, std::string p, std::string e)
    : memberID(id), name(std::move(n)), phone(std::move(p)), email(std::move(e)) {}

int Member::getMemberID() const { return memberID; }
std::string Member::getName() const { return name; }
std::string Member::getPhone() const { return phone; }
std::string Member::getEmail() const { return email; }
const std::vector<int>& Member::getBorrowedBooks() const { return borrowedBooks; }

void Member::setMemberID(int id) { memberID = id; }
void Member::setName(std::string n) { name = std::move(n); }
void Member::setPhone(std::string p) { phone = std::move(p); }
void Member::setEmail(std::string e) { email = std::move(e); }

void Member::borrowBook(int bookID) {
    borrowedBooks.push_back(bookID);
}

void Member::returnBook(int bookID) {
    auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), bookID);
    if (it != borrowedBooks.end()) {
        borrowedBooks.erase(it);
    }
}

void Member::display() const {
    std::cout << "Member ID: " << memberID << "\n"
              << "Name: " << name << "\n"
              << "Phone: " << phone << "\n"
              << "Email: " << email << "\n"
              << "Borrowed Books IDs: ";
    if (borrowedBooks.empty()) {
        std::cout << "None";
    } else {
        for (size_t i = 0; i < borrowedBooks.size(); ++i) {
            std::cout << borrowedBooks[i] << (i < borrowedBooks.size() - 1 ? ", " : "");
        }
    }
    std::cout << "\n---------------------------\n";
}

std::string Member::serialize() const {
    std::string data = std::to_string(memberID) + "|" + name + "|" + phone + "|" + email;
    if (!borrowedBooks.empty()) {
        data += "|";
        for (size_t i = 0; i < borrowedBooks.size(); ++i) {
            data += std::to_string(borrowedBooks[i]);
            if (i < borrowedBooks.size() - 1) data += ",";
        }
    }
    return data;
}

Member Member::deserialize(const std::string& data) {
    std::vector<std::string> tokens = Utility::split(data, '|');
    if (tokens.size() < 4) {
        throw std::runtime_error("Invalid member data format.");
    }
    Member m;
    m.setMemberID(std::stoi(tokens[0]));
    m.setName(tokens[1]);
    m.setPhone(tokens[2]);
    m.setEmail(tokens[3]);
    
    if (tokens.size() > 4 && !tokens[4].empty()) {
        std::vector<std::string> books = Utility::split(tokens[4], ',');
        for (const auto& b : books) {
            if (!b.empty()) {
                m.borrowBook(std::stoi(b));
            }
        }
    }
    return m;
}
