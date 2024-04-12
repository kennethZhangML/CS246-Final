#include <iostream>
#include <string>

using namespace std;

class Pizza {
public:
    virtual ~Pizza() {}
    virtual float cost() const = 0;
    virtual string desc() const = 0;
};

class Decorator : public Pizza {
protected:
    Pizza *next;
public:
    Decorator(Pizza *p) : next(p) {}
    virtual ~Decorator() { delete next; }
};

class CrustAndSauce : public Pizza {
public:
    float cost() const override { return 5.99f; }
    string desc() const override { return "Crust & Sauce Pizza"; }
};

class Topping : public Decorator {
    float topCost;
    string topDesc;
public:
    Topping(Pizza *p, float cost, string desc) : Decorator(p), topCost(cost), topDesc(desc) {}
    float cost() const override { return topCost + next->cost(); }
    string desc() const override { return topDesc + " and " + next->desc(); }
};

int main() {
    Pizza *p = new CrustAndSauce{};
    p = new Topping{p, 2.50f, "Bacon"};
    cout << p->desc() << " $" << p->cost() << endl;

    delete p;

    return 0;
}
