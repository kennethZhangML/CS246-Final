#include <iostream>
#include <string>
#include <vector>
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

class StockPrice : public Subject {
    std::ifstream in;
    int closingPrice;

public:
    StockPrice(std::string source) : in{source} {}

    bool runBacktest() {
        if (in >> closingPrice) {
            std::cout << "Closing Price: " << closingPrice << std::endl;
            return true;
        } else {
            return false;
        }
    }

    int closing() {
        return closingPrice;
    }
};

class Trader : public Observer {
    StockPrice *st;
    std::string name;
    int optimalPrice;

public:
    Trader(StockPrice *st, std::string name, int optimalPrice) : st{st}, name{name}, optimalPrice{optimalPrice} {
        st->attach(this);
    }

    ~Trader() {
        st->detach(this);
    }

    void notify() override {
        std::cout << name << ": " << (st->closing() >= optimalPrice ? "Profit!" : "Loss!") << std::endl;
    }
};

int main() {
    std::string fname = "stockMarket.txt";
    StockPrice st(fname);
    Trader trader1(&st, "Kenneth", 150000);
    Trader trader2(&st, "Ryan", 200000);
    Trader trader3(&st, "Jeck", 1000000);

    while (st.runBacktest()) {
        st.notifyObservers();
    }

    // detaching trader1 from stock price subject
    st.detach(trader1);

    while (st.runBacktest()) {
        st.notifyObserver();
    }

    return 0;
}