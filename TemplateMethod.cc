#include <iostream>

class Turtle {
public:
    void draw() {
        drawHead();
        drawFeet();
        drawShell();
    }

private:
    virtual void drawHead() = 0;
    virtual void drawFeet() = 0;
    virtual void drawShell() = 0;
};

class RedTurtle : public Turtle {
protected:
    void drawHead() override {
        std::cout << "Drawing Red Head!" << std::endl;
    }

    void drawFeet() override {
        std::cout << "Drawing Red Feet!" << std::endl;
    }

    void drawShell() override {
        std::cout << "Drawing Red Shell!" << std::endl;
    }
};

class GreenTurtle : public Turtle {
protected:
    void drawFeet() override {
        std::cout << "Drawing green feet" << std::endl;
    }

    void drawHead() override {
        std::cout << "Drawing green head" << std::endl;
    }

    void drawShell() override {
        std::cout << "Drawing green shell" << std::endl;
    }
};

int main() {
    RedTurtle redTurtle;
    GreenTurtle greenTurtle;

    std::cout << "Drawing Red Turtle:" << std::endl;
    redTurtle.draw();
    std::cout << std::endl;

    std::cout << "Drawing Green Turtle:" << std::endl;
    greenTurtle.draw();
    std::cout << std::endl;

    return 0;
}