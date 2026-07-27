#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>

class Member {
private:
    int memberID;
    std::string name;
    std::string phone;
    std::string email;
    std::vector<int> borrowedBooks;

public:
    // Constructors
    Member();
    Member(int id, std::string n, std::string p, std::string e);

    // Getters
    int getMemberID() const;
    std::string getName() const;
    std::string getPhone() const;
    std::string getEmail() const;
    const std::vector<int>& getBorrowedBooks() const;

    // Setters
    void setMemberID(int id);
    void setName(std::string n);
    void setPhone(std::string p);
    void setEmail(std::string e);

    // Methods
    void borrowBook(int bookID);
    void returnBook(int bookID);
    void display() const;
    std::string serialize() const;
    static Member deserialize(const std::string& data);
};

#endif // MEMBER_H
