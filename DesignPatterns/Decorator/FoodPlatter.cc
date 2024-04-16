#include <iostream>
#include <string>

class Platter {
public:
    virtual ~Platter() {}
    virtual float cost() const = 0;
    virtual std::string items() const = 0;
};

class Decorator : public Platter {
protected:
    Platter *next;

public:
    Decorator(Platter *next) : next{next} {}
    virtual ~Decorator() { delete next; }
};

class ChinesePlatter : public Platter {
public:
    float cost() const override { return 10.99f; }
    std::string items() const override { return "Kung Pao Chicken, Fried Rice, and Orange Chicken"; }
};

class Additional : public Decorator {
    float addCost;
    std::string addItems;

public:
    Additional(Platter* p, float cost, std::string items)
        : Decorator(p), addCost(cost), addItems(items) {}
    
    float cost() const override {
        return addCost + next->cost();
    }

    std::string items() const override {
        return addItems + " and " + next->items();
    }
};

int main() {
    Platter *p = new ChinesePlatter{};
    p = new Additional{p, 15.00f, "Gai lan, Chow Fun"};

    std::cout << p->items() << " $" << p->cost() << std::endl;
    
    delete p;
    return 0;
}