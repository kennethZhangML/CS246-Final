#include <iostream>
#include <string>
#include <memory>

class Book {
protected:
    std::string author;
    std::string title;
    int numPages;

public:
    Book(std::string a, std::string t, int n) : author(a), title(t), numPages(n) {}

    virtual ~Book() {}

    virtual bool isHeavy() const {
        return numPages > 200;
    }

    virtual std::string getDescription() const {
        return title + " by " + author + ", " + std::to_string(numPages) + " pages";
    }
};

class Comic : public Book {
private:
    std::string hero;

public:
    Comic(std::string a, std::string t, int n, std::string h) : Book(a, t, n), hero(h) {}

    bool isHeavy() const override {
        return numPages > 30;
    }

    std::string getDescription() const override {
        return Book::getDescription() + ", featuring " + hero;
    }
};

class Text : public Book {

public:
    Text(std::string a, std::string t, int n) : Book(a, t, n) {}

    bool isHeavy() const override {
        return numPages > 300;
    }

    std::string getDescription() const override {
        return Book::getDescription() + " [Textbook]";
    }
};

int main() {
    std::unique_ptr<Book> books[10];

    books[0] = std::make_unique<Comic>("Alan Moore", "Watchmen", 416, "Rorschach");
    books[1] = std::make_unique<Text>("Thomas H. Cormen", "Introduction to Algorithms", 1312);
    books[2] = std::make_unique<Book>("J. R. R. Tolkien", "The Hobbit", 310);

    for (size_t i = 0; i < 3; ++i) {
        std::cout << books[i]->getDescription() << std::endl;
        std::cout << "Is it heavy? " << books[i]->isHeavy() << std::endl;
    }

    return 0;
}

