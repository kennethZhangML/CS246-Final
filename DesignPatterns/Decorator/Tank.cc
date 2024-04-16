#include <iostream>
#include <string>

class Tank {
public:
    virtual ~Tank() {}
    virtual std::string name() const = 0;
    virtual std::string weapons() const = 0;
    virtual int damage() const = 0;
};

class Decorator : public Tank {
protected:
    Tank *next;

public:
    Decorator(Tank* t) : next{t} {}
    virtual ~Decorator() { delete next; }
};

class SuperPershing : public Tank {
public:
    std::string name() const override { return "T26E4 Super Pershing"; }
    std::string weapons() const override { return "M26 Enhanced"; }
    int damage() const override { return 390; }
};

class Weapon : public Decorator {
protected:
    std::string weaponName;
    int weaponDamage;
public:
    Weapon(Tank *p, std::string name, int damage) : Decorator{p}, weaponName(name), weaponDamage(damage) {}

    std::string name() const override {
        return weaponName + " and " + next->weapons();
    }

    std::string weapons() const override {
        return weaponName + " with " + next->weapons();
    }

    int damage() const override {
        return weaponDamage + next->damage();
    }
};

class NameModifier : public Decorator {
    std::string nickname;

public: 
    NameModifier(Tank *p, std::string name) : Decorator(p), nickname(name) {}

    std::string name() const override {
        return next->name() + " aka. " + nickname;
    }

    std::string weapons() const override {
        return next->weapons();
    }

    int damage() const override {
        return next->damage();
    }
};

int main() {
    Tank *t = new SuperPershing{};

    t = new NameModifier(t, "King Tiger Destroyer");
    t = new Weapon(t, "Howitzer M27 Long-Range Rifled", 150);

    std::cout << t->name() << " Damage: " << t->damage() << " with " << t->weapons();

    delete t;
    return 0;
}
