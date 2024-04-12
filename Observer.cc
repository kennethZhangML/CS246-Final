#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Observer {

public:
    virtual ~Observer() {}
    virtual void notify() = 0;
};

class Subject { 
    std::vector<Observer*> observers;

public:
    virtual ~Subject() {}
    void attach(Observer *o) { 
        observers.push_back(o);
    }

    void detach(Observer*o) {
        for (auto it = observers.begin(); it != observers.end(); ++it) {
            if (*it == 0) {
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

class HorseRace : public Subject {
    std::ifstream in;
    std::string lastWinner;

public:
    HorseRace(std::string source) : in(source) {}

    bool runRace() {
        if (in >> lastWinner) {
            std::cout << "Winner: " << lastWinner << std::endl;
            return true;
        } else {
            return false;
        }
    }

    std::string winner() {
        return lastWinner;
    }
};

class Bettor : public Observer {
    HorseRace* hr;
    std::string name;
    std::string favHorse;

public:
    Bettor(HorseRace* hr, std::string n, std::string fh) : hr(hr), name(n), favHorse(fh) {
        hr->attach(this);
    }

    ~Bettor() {
        hr->detach(this);
    }

    void notify() override { 
        std::cout << name << ": " << (hr->winner() == favHorse ? "Yay!" : "Boo!") << std::endl;
    }
};

int main() {
    std::string fname = "races.txt";
    HorseRace hr(fname);
    Bettor bettor1(&hr, "Stamp", "Runs like a cow");
    Bettor bettor2(&hr, "John", "Fast Runner");
    Bettor bettor3(&hr, "Alice", "Speedy Horse");

    while (hr.runRace()) {
        hr.notifyObservers();
    }

    return 0;
}