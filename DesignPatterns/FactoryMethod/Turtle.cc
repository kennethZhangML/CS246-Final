#include <iostream>
#include <vector>

class Enemy {
public:
    virtual ~Enemy() = default;
};

class Turtle : public Enemy {
public: 
    Turtle() {
        std::cout << "Turtle created!" << std::endl;
    }
};

class Bullet : public Enemy {
public:
    Bullet() {
        std::cout << "Bullet created!" << std::endl;
    }
};

class Level {
public:
    virtual Enemy* create() = 0;
    virtual ~Level() = default;
};

class Easy : public Level {
public:
    Enemy* create() override {
        if (rand() % 10 < 7) {
            return new Turtle();
        } else {
            return new Bullet();
        }
    }
};

class Hard : public Level {
public:
    Enemy* create() override {
        if (rand() % 10 < 7) {
            return new Bullet();
        } else {
            return new Turtle();
        }
    }
};


int main() {
    srand(time(nullptr));

    Level* easyFactory = new Hard();
    std::cout << "Creating enemies for easy level:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        Enemy* enemy = easyFactory->create();
        delete enemy;
    }
    delete easyFactory;

    Level* hardFactory = new Hard();
    std::cout << "Creating enemies for hard level:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        Enemy* enemy = hardFactory->create();
        delete enemy;
    }
    delete hardFactory;

    return 0;
}