#include <iostream>
#include <memory>
#include <string>

class Beverage {
public:
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
    virtual ~Beverage() = default;
};

class Espresso : public Beverage {
public:
    std::string getDescription() const override {
        return "Espresso";
    }

    double cost() const override {
        return 1.99;
    }
};

class Tea : public Beverage {
public:
    std::string getDescription() const override {
        return "Tea";
    }

    double cost() const override {
        return 1.49;
    }
};

class CondimentDecorator : public Beverage {
protected:
    std::shared_ptr<Beverage> beverage;
public:
    CondimentDecorator(std::shared_ptr<Beverage> beverage) : beverage(beverage) {}
    virtual std::string getDescription() const = 0;
};

class Milk : public CondimentDecorator {
public:
    Milk(std::shared_ptr<Beverage> beverage) : CondimentDecorator(beverage) {}

    std::string getDescription() const override {
        return beverage->getDescription() + ", Milk";
    }

    double cost() const override {
        return beverage->cost() + 0.50;
    }
};

class Mocha : public CondimentDecorator {
public:
    Mocha(std::shared_ptr<Beverage> beverage) : CondimentDecorator(beverage) {}

    std::string getDescription() const override {
        return beverage->getDescription() + ", Mocha";
    }

    double cost() const override {
        return beverage->cost() + 0.75;
    }
};

int main() {
    std::shared_ptr<Beverage> espresso = std::make_shared<Espresso>();
    std::cout << espresso->getDescription() << " $" << espresso->cost() << std::endl;

    std::shared_ptr<Beverage> milkEspresso = std::make_shared<Milk>(espresso);
    std::cout << milkEspresso->getDescription() << " $" << milkEspresso->cost() << std::endl;

    std::shared_ptr<Beverage> mochaMilkEspresso = std::make_shared<Mocha>(milkEspresso);
    std::cout << mochaMilkEspresso->getDescription() << " $" << mochaMilkEspresso->cost() << std::endl;

    std::shared_ptr<Beverage> tea = std::make_shared<Tea>();
    std::cout << tea->getDescription() << " $" << tea->cost() << std::endl;

    return 0;
}
