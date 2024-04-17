#include <iostream>
#include <variant>
#include <vector>
#include <random>

class Enemy {
public:
    virtual ~Enemy() = default;
};

class Turtle : public Enemy {
public:
    Turtle() {
        std::cout << "Creating Turtle!" << std::endl;
    }
};

class Bullet : public Enemy {
public:
    Bullet() {
        std::cout << "Creating Bullet!" << std::endl;
    }
};

class Level {
public:
    virtual std::variant<Turtle, Bullet> create() = 0;
    virtual ~Level() = default;
};

class Easy : public Level {
public:
    std::variant<Turtle, Bullet> create() override {
        if (rand() % 10 < 7) {
            return Turtle();
        } else {
            return Bullet();
        }
    }
};

class Hard : public Level {
public:
    std::variant<Turtle, Bullet> create() override {
        if (rand() % 10 < 7) {
            return Bullet();
        } else {
            return Turtle();
        }
    }
};

int main() {
    srand(time(nullptr));

    Level* level1 = new Easy();
    for (int i = 0; i < 5; ++i) {
        try {
            std::variant<Turtle, Bullet> enemy = level1->create();
        } catch (const std::bad_variant_access& e) {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }
    }

    Level* level2 = new Hard();
    for (int i = 0; i < 5; ++i) {
        try {
            std::variant<Turtle, Bullet> enemy = level2->create();
        } catch (const std::bad_variant_access& e) {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }
    }
    
    delete level1;
    delete level2;
    
    return 0;
}
