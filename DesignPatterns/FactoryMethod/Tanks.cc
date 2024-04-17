#include <iostream>
#include <cstdlib>
#include <ctime>

class Enemy {
public:
    virtual ~Enemy() = default;
};

class Tiger1 : public Enemy {
public:
    Tiger1() {
        std::cout << "Tiger 1 approaching!" << std::endl;
    }
};

class Tiger2 : public Enemy { 
public:
    Tiger2() {
        std::cout << "Tiger 2 approaching!" << std::endl;
    }
};

class Friendly {
public:
    virtual ~Friendly() = default;
};

class SuperPershing : public Friendly {
public:
    SuperPershing() {
        std::cout << "Super Pershing coming!" << std::endl;
    }
};

class T29 : public Friendly {
public:
    T29() {
        std::cout << "T29 coming!" << std::endl;
    }
};

class Level {
public:
    virtual Enemy* createEnemy() = 0;
    virtual Friendly* createFriendly() = 0;
    virtual ~Level() = default;
};

class Easy : public Level {
public:
    Enemy* createEnemy() override {
        if (rand() % 10 < 7) {
            return new Tiger1();
        } else {
            return new Tiger2();
        }
    }

    Friendly* createFriendly() override {
        if (rand() % 2 == 0) {
            return new SuperPershing();
        } else {
            return new T29();
        }
    }
};

class Medium : public Level {
public:
    Enemy* createEnemy() override {
        if (rand() % 10 < 5) {
            return new Tiger1();
        } else {
            return new Tiger2();
        }
    }

    Friendly* createFriendly() override {
        if (rand() % 2 == 0) {
            return new SuperPershing();
        } else {
            return new T29();
        }
    }
};

class Hard : public Level {
public:
    Enemy* createEnemy() override {
        if (rand() % 10 < 3) {
            return new Tiger1();
        } else {
            return new Tiger2();
        }
    }

    Friendly* createFriendly() override {
        if (rand() % 2 == 0) {
            return new SuperPershing();
        } else {
            return new T29();
        }
    }
};

int main() {
    srand(time(nullptr));

    Level* level = new Hard(); 
    std::cout << "Creating enemies and friendly units:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        Enemy* enemy = level->createEnemy();
        delete enemy;
        Friendly* friendly = level->createFriendly();
        delete friendly;
    }
    delete level;

    return 0;
}
