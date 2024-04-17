#include <iostream>
#include <string>

class Cake {
public: 
    virtual std::string desc() const = 0;
    virtual float price() const = 0;
    virtual ~Cake() = default;
};

class CherryCake : public Cake {
public:
    std::string desc() const override {
        return "Cake with Cherry";
    }

    float price() const override {
        return 10.99f;
    }
};

class Decorator : public Cake {
protected:
    Cake* next;

public:
    Decorator(Cake* c) : next{c} {}
    virtual ~Decorator() = default;
};

class ToppingDecorator : public Decorator {
protected:  
    std::string toppingDesc;
    float toppingCost;

public:
    ToppingDecorator(Cake *c, std::string desc, float cost) 
        : Decorator{c}, toppingDesc(desc), toppingCost(cost) {}

    std::string desc() const override {
        return next->desc() + ", " + toppingDesc;
    }

    float price() const override {
        return next->price() + toppingCost;
    }
};

class Strawberry : public ToppingDecorator {
public:
    Strawberry(Cake *c) : ToppingDecorator(c, "Strawberry", 5.99f) {}

    std::string desc() const override {
        return next->desc() + ", " + toppingDesc;
    }

    float price() const override {
        return next->price() + this->toppingCost;
    }
};

class Chocolate : public ToppingDecorator { 
public:
    Chocolate(Cake *c) : ToppingDecorator(c, "Chocolate", 2.99f) {}

    std::string desc() const override {
        return next->desc() + ", " + toppingDesc;
    }

    float price() const override {
        return next->price() + toppingCost;
    }
};

int main() {
    Cake *c = new CherryCake{};

    c = new Strawberry{c};
    c = new Chocolate{c};

    std::cout << c->desc() << " $" << c->price() << std::endl;

    return 0;
}
