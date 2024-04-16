#include <iostream>

class March {

    struct Soldier {
        std::string name;
        int badge_id;
        Soldier* next;

        Soldier(std::string name, int id, Soldier* next = nullptr) : name{name}, badge_id{id}, next{next} {}
    };

    Soldier* theMarch = nullptr;

public:
    
    class MarchIterator {
        Soldier* currentSoldier;

    public:
        explicit MarchIterator(Soldier *s = nullptr);
        bool operator!=(const MarchIterator& other);
        std::string operator*() const;
        MarchIterator& operator++();
    };

    ~March();
    void addSoldier(std::string name, int badge_id);
    MarchIterator begin() const;
    MarchIterator end() const;
};

March::MarchIterator::MarchIterator(Soldier *s) : currentSoldier{s} {}

bool March::MarchIterator::operator!=(const MarchIterator& other) {
    return currentSoldier != other.currentSoldier;
}

std::string March::MarchIterator::operator*() const {
    return currentSoldier->name;
}

March::MarchIterator& March::MarchIterator::operator++() {
    if (currentSoldier != nullptr) {
        currentSoldier = currentSoldier->next;
    }
    return *this;
}

March::~March() {
    while (theMarch != nullptr) {
        Soldier* temp = theMarch;
        theMarch = theMarch->next;
        delete temp;
    }
}

void March::addSoldier(std::string name, int badge_id) {
    theMarch = new Soldier{name, badge_id, theMarch};
}

March::MarchIterator March::begin() const {
    return MarchIterator(theMarch);
}

March::MarchIterator March::end() const {
    return MarchIterator(nullptr);
}

int main() {

    March myMarch;
    myMarch.addSoldier("Vladimir Poosy-tin", 1);
    myMarch.addSoldier("Adolf Titler", 2);
    myMarch.addSoldier("Justin Falsedeau", 3);
    myMarch.addSoldier("Xi JinPing me", 4);

    std::cout << "Iterating over my march: " << std::endl;
    for (March::MarchIterator it = myMarch.begin(); it != myMarch.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}