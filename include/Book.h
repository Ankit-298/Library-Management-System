#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    int bookID;
    std::string title;
    std::string author;
    std::string genre;
    int year;
    std::string isbn;
    bool available;

public:
    // Constructors
    Book();
    Book(int id, std::string t, std::string a, std::string g, int y, std::string i, bool avail = true);

    // Getters
    int getBookID() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getGenre() const;
    int getYear() const;
    std::string getISBN() const;
    bool isAvailable() const;

    // Setters
    void setBookID(int id);
    void setTitle(std::string t);
    void setAuthor(std::string a);
    void setGenre(std::string g);
    void setYear(int y);
    void setISBN(std::string i);
    void setAvailable(bool avail);

    // Methods
    void display() const;
    std::string serialize() const;
    static Book deserialize(const std::string& data);
};

#endif // BOOK_H
