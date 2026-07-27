#include "Book.h"
#include "Utility.h"
#include <iostream>
#include <vector>
#include <stdexcept>

Book::Book() : bookID(0), year(0), available(true) {}

Book::Book(int id, std::string t, std::string a, std::string g, int y, std::string i, bool avail)
    : bookID(id), title(std::move(t)), author(std::move(a)), genre(std::move(g)), year(y), isbn(std::move(i)), available(avail) {}

int Book::getBookID() const { return bookID; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
std::string Book::getGenre() const { return genre; }
int Book::getYear() const { return year; }
std::string Book::getISBN() const { return isbn; }
bool Book::isAvailable() const { return available; }

void Book::setBookID(int id) { bookID = id; }
void Book::setTitle(std::string t) { title = std::move(t); }
void Book::setAuthor(std::string a) { author = std::move(a); }
void Book::setGenre(std::string g) { genre = std::move(g); }
void Book::setYear(int y) { year = y; }
void Book::setISBN(std::string i) { isbn = std::move(i); }
void Book::setAvailable(bool avail) { available = avail; }

void Book::display() const {
    std::cout << "Book ID: " << bookID << "\n"
              << "Title: " << title << "\n"
              << "Author: " << author << "\n"
              << "Genre: " << genre << "\n"
              << "Year: " << year << "\n"
              << "ISBN: " << isbn << "\n"
              << "Status: " << (available ? "Available" : "Issued") << "\n"
              << "---------------------------\n";
}

std::string Book::serialize() const {
    return std::to_string(bookID) + "|" + title + "|" + author + "|" + genre + "|" + 
           std::to_string(year) + "|" + isbn + "|" + (available ? "1" : "0");
}

Book Book::deserialize(const std::string& data) {
    std::vector<std::string> tokens = Utility::split(data, '|');
    if (tokens.size() < 7) {
        throw std::runtime_error("Invalid book data format.");
    }
    Book b;
    b.setBookID(std::stoi(tokens[0]));
    b.setTitle(tokens[1]);
    b.setAuthor(tokens[2]);
    b.setGenre(tokens[3]);
    b.setYear(std::stoi(tokens[4]));
    b.setISBN(tokens[5]);
    b.setAvailable(tokens[6] == "1");
    return b;
}
