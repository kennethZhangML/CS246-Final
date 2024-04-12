#include <iostream>
#include <string>

class AbstractBook {

protected:
    std::string title;
    std::string author;
    int numPages;
    AbstractBook& operator=(const AbstractBook& other);

public:
    AbstractBook(const std::string& title, const std::string& author, int numPages)
        : title(title), author(author), numPages(numPages) {}

    virtual ~AbstractBook() = 0;
};

AbstractBook::~AbstractBook() {}

AbstractBook& AbstractBook::operator=(const AbstractBook& other) {
    if (this == &other) return *this;
    title = other.title;
    author = other.author;
    numPages = other.numPages;
    return *this;
}

class Book : public AbstractBook {
public:
    Book(const std::string& title, const std::string& author, int numPages) 
        : AbstractBook(title, author, numPages) {}

    Book& operator=(const Book& other) {
        if (this == &other) return *this;
        AbstractBook::operator=(other);
        return *this;
    }
};

class Comic : public AbstractBook {

public:
    Comic(const std::string& title, const std::string& author, int numPages) 
        : AbstractBook(title, author, numPages) {}

    Comic& operator=(const Comic& other) {
        if (this == &other) return *this;
        AbstractBook::operator=(other);
        return *this;
    }
};

class Text : public AbstractBook {

public:
    Text(const std::string title, const std::string& author, int numPages) 
        : AbstractBook(title, author, numPages) {}
    
    Text& operator=(const Text& other) {
        if (this == &other) return *this;
        AbstractBook::operator=(other);
        return *this;
    }
};

int main() {
    Book b1("The Great Gatsby", "F. Scott Fitzgerald", 180);
    Book b2("To Kill a Mockingbird", "Harper Lee", 281);
    Comic c1("Spider-Man", "Stan Lee", 36);
    Comic c2("Batman", "Bob Kane", 32);
    Text t1("War and Peace", "Leo Tolstoy", 1225);
    Text t2("1984", "George Orwell", 328);

    AbstractBook* p1 = &b1;
    AbstractBook* p2 = &c2;
    return 0;
}

