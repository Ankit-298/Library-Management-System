#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Member.h"
#include <vector>
#include <unordered_map>
#include <map>
#include <string>

class Library {
private:
    std::vector<Book> books;
    std::vector<Member> members;
    std::unordered_map<int, int> issuedBooks; // BookID -> MemberID
    std::map<int, std::string> dueDates;      // BookID -> Due Date (YYYY-MM-DD)

    // Data paths
    static constexpr const char* booksFile = "data/books.txt";
    static constexpr const char* membersFile = "data/members.txt";
    static constexpr const char* issuesFile = "data/issues.txt";

public:
    Library();
    ~Library();

    void loadBooks();
    void saveBooks() const;
    void loadMembers();
    void saveMembers() const;
    void loadIssues();
    void saveIssues() const;

    void addBook();
    void removeBook();
    void updateBook();
    void displayBooks() const;

    void searchBookByID() const;
    void searchBookByTitle() const;
    void searchBookByAuthor() const;

    void registerMember();
    void removeMember();
    void displayMembers() const;

    void issueBook();
    void returnBook();
    void calculateFine(int bookID, const std::string& returnDate) const;
    void showIssuedBooks() const;

    void menu();

private:
    int findBookIndex(int bookID) const;
    int findMemberIndex(int memberID) const;
};

#endif // LIBRARY_H
