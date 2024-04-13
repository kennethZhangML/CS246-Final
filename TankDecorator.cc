#include <iostream>
#include <vector>
#include <string>

class Tank {
public:
    virtual ~Tank() {}
    virtual int dps() const = 0;
    virtual std::string desc() const = 0;
};

class Decorator : public Tank {
protected:
    Tank* next;

public:
    Decorator(Tank* t) : next(t) {}
    virtual ~Decorator() { delete next; }
};

class SuperPershing : public Tank {
public:
    int dps() const override { return 250; }
    std::string desc() const override { return "T26E4 Super Pershing (aka. Tiger Destroyer)"; }
};

class Tiger2 : public Tank {
public:
    int dps() const override { return 300; }
    std::string desc() const override { return "Tiger II (King Tiger)"; }
};

class KV122 : public Tank {
public:
    int dps() const override { return 220; }
    std::string desc() const override { return "KV-122"; }
};

class Tiger1 : public Tank {
public:
    int dps() const override { return 200; }
    std::string desc() const override { return "Tiger I"; }
};

class Gun : public Decorator {
    int gunDamage;
    std::string gunDesc;

public:
    Gun(Tank* p, int damage, std::string desc) : Decorator(p), gunDamage(damage), gunDesc(desc) {}
    int dps() const override { return gunDamage + next->dps(); }
    std::string desc() const override {
        return gunDesc + " and " + next->desc();
    }
};

int main() {
    Tank* t = new SuperPershing{};
    t = new Gun{t, 250, "Improvised M26"};

    std::cout << t->desc() << " Total DPS:" << t->dps() << std::endl;

    Tank* t2 = new Tiger2{};
    t2 = new Gun{t2, 300, "Improved 8.8 cm KwK 43 L/71"};

    std::cout << t2->desc() << " Total DPS:" << t2->dps() << std::endl;

    Tank* kv = new KV122{};
    kv = new Gun{kv, 240, "122 mm D-25T cannon"};

    std::cout << kv->desc() << " Total DPS:" << kv->dps() << std::endl;

    Tank* t1 = new Tiger1{};
    t1 = new Gun{t1, 250, "Improved 8.8 cm KwK 36 L/56"};

    std::cout << t1->desc() << " Total DPS:" << t1->dps() << std::endl;

    return 0;
}
