#include "Library.h"
#include "Utility.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdexcept>
#include <ctime>

Library::Library() {
    loadBooks();
    loadMembers();
    loadIssues();
}

Library::~Library() {
    saveBooks();
    saveMembers();
    saveIssues();
}

void Library::loadBooks() {
    std::ifstream file(booksFile);
    if (!file.is_open()) return;
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            try {
                books.push_back(Book::deserialize(line));
            } catch (...) {
                // Skip invalid lines
            }
        }
    }
}

void Library::saveBooks() const {
    std::ofstream file(booksFile);
    if (!file.is_open()) return;
    for (const auto& book : books) {
        file << book.serialize() << "\n";
    }
}

void Library::loadMembers() {
    std::ifstream file(membersFile);
    if (!file.is_open()) return;
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            try {
                members.push_back(Member::deserialize(line));
            } catch (...) {
                // Skip invalid lines
            }
        }
    }
}

void Library::saveMembers() const {
    std::ofstream file(membersFile);
    if (!file.is_open()) return;
    for (const auto& member : members) {
        file << member.serialize() << "\n";
    }
}

void Library::loadIssues() {
    std::ifstream file(issuesFile);
    if (!file.is_open()) return;
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            std::vector<std::string> tokens = Utility::split(line, '|');
            if (tokens.size() == 3) {
                int bookID = std::stoi(tokens[0]);
                int memberID = std::stoi(tokens[1]);
                issuedBooks[bookID] = memberID;
                dueDates[bookID] = tokens[2];
            }
        }
    }
}

void Library::saveIssues() const {
    std::ofstream file(issuesFile);
    if (!file.is_open()) return;
    for (const auto& pair : issuedBooks) {
        file << pair.first << "|" << pair.second << "|" << dueDates.at(pair.first) << "\n";
    }
}

int Library::findBookIndex(int bookID) const {
    auto it = std::find_if(books.begin(), books.end(), [bookID](const Book& b) {
        return b.getBookID() == bookID;
    });
    return (it != books.end()) ? std::distance(books.begin(), it) : -1;
}

int Library::findMemberIndex(int memberID) const {
    auto it = std::find_if(members.begin(), members.end(), [memberID](const Member& m) {
        return m.getMemberID() == memberID;
    });
    return (it != members.end()) ? std::distance(members.begin(), it) : -1;
}

void Library::addBook() {
    std::cout << "\n--- Add Book ---\n";
    std::cout << "Enter Book ID (Positive Integer): ";
    int id = Utility::getValidID();
    
    if (findBookIndex(id) != -1) {
        throw std::runtime_error("Book ID already exists!");
    }

    std::cout << "Enter Title: ";
    std::string title = Utility::getValidString();
    
    std::cout << "Enter Author: ";
    std::string author = Utility::getValidString();
    
    std::cout << "Enter Genre: ";
    std::string genre = Utility::getValidString();
    
    std::cout << "Enter Year: ";
    int year = Utility::getValidYear();
    
    std::cout << "Enter ISBN: ";
    std::string isbn = Utility::getValidString();

    books.emplace_back(id, title, author, genre, year, isbn);
    saveBooks();
    std::cout << "✓ Book Added Successfully\n";
}

void Library::removeBook() {
    std::cout << "\n--- Remove Book ---\n";
    std::cout << "Enter Book ID: ";
    int id = Utility::getValidID();
    
    int index = findBookIndex(id);
    if (index == -1) {
        throw std::runtime_error("Book not found!");
    }

    if (!books[index].isAvailable()) {
        throw std::runtime_error("Cannot remove an issued book!");
    }

    books.erase(books.begin() + index);
    saveBooks();
    std::cout << "✓ Book Removed Successfully\n";
}

void Library::updateBook() {
    std::cout << "\n--- Update Book ---\n";
    std::cout << "Enter Book ID: ";
    int id = Utility::getValidID();
    
    int index = findBookIndex(id);
    if (index == -1) {
        throw std::runtime_error("Book not found!");
    }

    std::cout << "Enter New Title: ";
    books[index].setTitle(Utility::getValidString());
    
    std::cout << "Enter New Author: ";
    books[index].setAuthor(Utility::getValidString());
    
    std::cout << "Enter New Genre: ";
    books[index].setGenre(Utility::getValidString());
    
    std::cout << "Enter New Year: ";
    books[index].setYear(Utility::getValidYear());
    
    std::cout << "Enter New ISBN: ";
    books[index].setISBN(Utility::getValidString());

    saveBooks();
    std::cout << "✓ Book Updated Successfully\n";
}

void Library::displayBooks() const {
    std::cout << "\n--- All Books ---\n";
    if (books.empty()) {
        std::cout << "No books available.\n";
        return;
    }
    for (const auto& book : books) {
        book.display();
    }
}

void Library::searchBookByID() const {
    std::cout << "\n--- Search Book by ID ---\n";
    std::cout << "Enter Book ID: ";
    int id = Utility::getValidID();
    
    int index = findBookIndex(id);
    if (index != -1) {
        books[index].display();
    } else {
        std::cout << "✗ Book Not Found\n";
    }
}

void Library::searchBookByTitle() const {
    std::cout << "\n--- Search Book by Title ---\n";
    std::cout << "Enter Title: ";
    std::string title = Utility::getValidString();
    
    std::string lowerTitle = title;
    std::transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), ::tolower);
    
    bool found = false;
    for (const auto& book : books) {
        std::string bookTitle = book.getTitle();
        std::string lowerBookTitle = bookTitle;
        std::transform(lowerBookTitle.begin(), lowerBookTitle.end(), lowerBookTitle.begin(), ::tolower);
        
        if (lowerBookTitle.find(lowerTitle) != std::string::npos) {
            book.display();
            found = true;
        }
    }
    if (!found) {
        std::cout << "✗ No Matching Books Found\n";
    }
}

void Library::searchBookByAuthor() const {
    std::cout << "\n--- Search Book by Author ---\n";
    std::cout << "Enter Author: ";
    std::string author = Utility::getValidString();
    
    std::string lowerAuthor = author;
    std::transform(lowerAuthor.begin(), lowerAuthor.end(), lowerAuthor.begin(), ::tolower);
    
    bool found = false;
    for (const auto& book : books) {
        std::string bookAuthor = book.getAuthor();
        std::string lowerBookAuthor = bookAuthor;
        std::transform(lowerBookAuthor.begin(), lowerBookAuthor.end(), lowerBookAuthor.begin(), ::tolower);
        
        if (lowerBookAuthor.find(lowerAuthor) != std::string::npos) {
            book.display();
            found = true;
        }
    }
    if (!found) {
        std::cout << "✗ No Matching Books Found\n";
    }
}

void Library::registerMember() {
    std::cout << "\n--- Register Member ---\n";
    std::cout << "Enter Member ID: ";
    int id = Utility::getValidID();
    
    if (findMemberIndex(id) != -1) {
        throw std::runtime_error("Member ID already exists!");
    }

    std::cout << "Enter Name: ";
    std::string name = Utility::getValidString();
    
    std::string phone;
    while (true) {
        std::cout << "Enter Phone: ";
        phone = Utility::getValidString();
        if (Utility::isValidPhone(phone)) break;
        std::cout << "Invalid phone format.\n";
    }
    
    std::string email;
    while (true) {
        std::cout << "Enter Email: ";
        email = Utility::getValidString();
        if (Utility::isValidEmail(email)) break;
        std::cout << "Invalid email format.\n";
    }

    members.emplace_back(id, name, phone, email);
    saveMembers();
    std::cout << "✓ Member Registered Successfully\n";
}

void Library::removeMember() {
    std::cout << "\n--- Remove Member ---\n";
    std::cout << "Enter Member ID: ";
    int id = Utility::getValidID();
    
    int index = findMemberIndex(id);
    if (index == -1) {
        throw std::runtime_error("Member not found!");
    }

    if (!members[index].getBorrowedBooks().empty()) {
        throw std::runtime_error("Cannot remove member with issued books!");
    }

    members.erase(members.begin() + index);
    saveMembers();
    std::cout << "✓ Member Removed Successfully\n";
}

void Library::displayMembers() const {
    std::cout << "\n--- All Members ---\n";
    if (members.empty()) {
        std::cout << "No members registered.\n";
        return;
    }
    for (const auto& member : members) {
        member.display();
    }
}

void Library::issueBook() {
    std::cout << "\n--- Issue Book ---\n";
    std::cout << "Enter Book ID: ";
    int bookID = Utility::getValidID();
    
    int bIndex = findBookIndex(bookID);
    if (bIndex == -1) {
        throw std::runtime_error("Book not found!");
    }
    if (!books[bIndex].isAvailable()) {
        throw std::runtime_error("Book is already issued!");
    }

    std::cout << "Enter Member ID: ";
    int memberID = Utility::getValidID();
    
    int mIndex = findMemberIndex(memberID);
    if (mIndex == -1) {
        throw std::runtime_error("Member not found!");
    }

    std::cout << "Enter Due Date (YYYY-MM-DD): ";
    std::string dueDate;
    while (true) {
        dueDate = Utility::getValidString();
        if (Utility::isValidDate(dueDate)) {
            break;
        }
        std::cout << "Invalid date format. Enter Due Date (YYYY-MM-DD): ";
    }

    books[bIndex].setAvailable(false);
    members[mIndex].borrowBook(bookID);
    issuedBooks[bookID] = memberID;
    dueDates[bookID] = dueDate;

    saveBooks();
    saveMembers();
    saveIssues();

    std::cout << "✓ Book Issued Successfully\n";
}

void Library::returnBook() {
    std::cout << "\n--- Return Book ---\n";
    std::cout << "Enter Book ID: ";
    int bookID = Utility::getValidID();
    
    if (issuedBooks.find(bookID) == issuedBooks.end()) {
        throw std::runtime_error("Book is not currently issued!");
    }

    int memberID = issuedBooks[bookID];
    
    std::cout << "Enter Return Date (YYYY-MM-DD): ";
    std::string returnDate;
    while (true) {
        returnDate = Utility::getValidString();
        if (Utility::isValidDate(returnDate)) {
            break;
        }
        std::cout << "Invalid date format. Enter Return Date (YYYY-MM-DD): ";
    }

    calculateFine(bookID, returnDate);

    int bIndex = findBookIndex(bookID);
    if (bIndex != -1) {
        books[bIndex].setAvailable(true);
    }

    int mIndex = findMemberIndex(memberID);
    if (mIndex != -1) {
        members[mIndex].returnBook(bookID);
    }

    issuedBooks.erase(bookID);
    dueDates.erase(bookID);

    saveBooks();
    saveMembers();
    saveIssues();

    std::cout << "✓ Book Returned Successfully\n";
}

void Library::calculateFine(int bookID, const std::string& returnDate) const {
    std::string dueDate = dueDates.at(bookID);
    int days = Utility::dateDifferenceInDays(dueDate, returnDate);
    
    int fine = 0;
    if (days > 0) {
        fine = days * 10;
    }
    
    std::cout << "---------------------------\n";
    std::cout << "Due Date: " << dueDate << "\n";
    std::cout << "Return Date: " << returnDate << "\n";
    std::cout << "Late Days: " << (days > 0 ? days : 0) << "\n";
    std::cout << "Total Fine: rs" << fine << "\n";
    std::cout << "---------------------------\n";
}

void Library::showIssuedBooks() const {
    std::cout << "\n--- Issued Books ---\n";
    if (issuedBooks.empty()) {
        std::cout << "No books currently issued.\n";
        return;
    }
    for (const auto& pair : issuedBooks) {
        int bookID = pair.first;
        int memberID = pair.second;
        std::string dueDate = dueDates.at(bookID);
        
        std::string bookTitle = "Unknown";
        int bIndex = findBookIndex(bookID);
        if (bIndex != -1) bookTitle = books[bIndex].getTitle();
        
        std::string memberName = "Unknown";
        int mIndex = findMemberIndex(memberID);
        if (mIndex != -1) memberName = members[mIndex].getName();
        
        std::cout << "Book ID: " << bookID << " (" << bookTitle << ")\n"
                  << "Issued To Member ID: " << memberID << " (" << memberName << ")\n"
                  << "Due Date: " << dueDate << "\n"
                  << "---------------------------\n";
    }
}

void Library::menu() {
    while (true) {
        std::cout << "\n======== LIBRARY MANAGEMENT SYSTEM ========\n"
                  << "1  Add Book\n"
                  << "2  Remove Book\n"
                  << "3  Update Book\n"
                  << "4  Display Books\n"
                  << "5  Search by ID\n"
                  << "6  Search by Title\n"
                  << "7  Search by Author\n"
                  << "8  Register Member\n"
                  << "9  Remove Member\n"
                  << "10 Display Members\n"
                  << "11 Issue Book\n"
                  << "12 Return Book\n"
                  << "13 Show Issued Books\n"
                  << "14 Exit\n"
                  << "===========================================\n"
                  << "Enter choice: ";
        
        int choice = Utility::getValidInt();
        
        try {
            switch (choice) {
                case 1: addBook(); break;
                case 2: removeBook(); break;
                case 3: updateBook(); break;
                case 4: displayBooks(); break;
                case 5: searchBookByID(); break;
                case 6: searchBookByTitle(); break;
                case 7: searchBookByAuthor(); break;
                case 8: registerMember(); break;
                case 9: removeMember(); break;
                case 10: displayMembers(); break;
                case 11: issueBook(); break;
                case 12: returnBook(); break;
                case 13: showIssuedBooks(); break;
                case 14: 
                    std::cout << "Exiting system. Goodbye!\n"; 
                    return;
                default:
                    std::cout << "✗ Invalid choice. Please try again.\n";
            }
        } catch (const std::exception& e) {
            std::cout << "✗ Error: " << e.what() << "\n";
        }
    }
}
