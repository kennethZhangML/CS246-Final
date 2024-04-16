#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Observer {
public:
    virtual ~Observer() {}
    virtual void notify() = 0;
};

class Subject {
    std::vector<Observer*> observers;
public:
    void attach(Observer *o) {
        observers.push_back(o);
    }

    void detach(Observer *o) {
        for (auto it = observers.begin(); it != observers.end(); ++it) {
            if (*it == o) {
                observers.erase(it);
                break;
            }
        }
    }

    void notifyObservers() {
        for (auto o : observers) {
            o->notify();
        }
    }
};

class Farm : public Subject {
    std::fstream in;
    std::string animal;

public:
    Farm(std::string source) : in{source} {}
    bool selectSlaughter() {
        if (in >> animal) {
            std::cout << "Animal to be Slaughtered: " << animal << std::endl;
            return true;
        } else {
            return false;
        }
    }

    std::string chosenAnimal() {
        return animal;
    }
};

class Animal : public Observer {
    Farm *fm;
    std::string animalName;
    std::string animalType;

public:
    Animal(Farm *fm, std::string animalName, std::string animalType) : fm{fm}, animalName{animalName}, animalType{animalType} {
        fm->attach(this);
    }

    ~Animal() {
        fm->detach(this);
    }

    void notify() override {
        std::cout << animalName << ": " << (fm->chosenAnimal() == animalType ? "Slaughtered!" : "Alive!") << std::endl;
    }
};

int main() {
    std::string fname = "farm.txt";
    Farm fm{fname};

    Animal animal1(&fm, "Bob", "Cow");
    Animal animal2(&fm, "Jeff", "Cow");
    Animal animal3(&fm, "Otto", "Duck");
    Animal animal4(&fm, "Chelsea", "Chicken");

    while (fm.selectSlaughter()) {
        fm.notifyObservers();
    }

    return 0;
}