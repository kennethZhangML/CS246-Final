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
    std::vector<Observer *> observers;

public:
    void attach(Observer* o) {
        observers.push_back(o);
    }

    void detach(Observer* o) {
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

class Pandemic : public Subject {
    std::ifstream in;
    int infectionStrength;

public:
    Pandemic(std::string source) : in{source} {}

    bool infect() {
        if (in >> infectionStrength) {
            std::cout << "Infection Strength: " << infectionStrength << std::endl;
            return true;
        } else {
            return false;
        }
    }

    bool lastInfection() {
        return infectionStrength;
    }
};

class Person : public Observer {
    Pandemic *pd;
    std::string name;
    int infectionImmunity;

public:
    Person(Pandemic *pd, std::string name, int infectionImmunity) : pd{pd}, name{name}, infectionImmunity{infectionImmunity} {
        pd->attach(this);
    }

    ~Person() {
        pd->detach(this);
    }

    void notify() override {
        std::cout << name << ": " << (pd->lastInfection() <= infectionImmunity ? "I'm healthy!" : "I'm infected!") << std::endl;
    }
};


int main() {
    std::string fname = "virus.txt";
    Pandemic pd(fname);
    Person person1(&pd, "Ronald", 250);
    Person person2(&pd, "Korshal", 120);
    Person person3(&pd, "Justin", 300);

    while (pd.infect()) {
        pd.notifyObservers();
    }
    return 0;
}

