#include <iostream>

class AbstractAlgorithm {
public:
    virtual void execute() {
        step1();
        step2();
        customStep(); 
        step3();
    }

protected:
    virtual void step1() {
        std::cout << "Performing Step 1..." << std::endl;
    }

    virtual void step2() {
        std::cout << "Performing Step 2..." << std::endl;
    }

    virtual void customStep() {
        std::cout << "Performing Custom Step..." << std::endl;
    }

    virtual void step3() {
        std::cout << "Performing Step 3..." << std::endl;
    }
};

class ConcreteAlgorithm : public AbstractAlgorithm {
protected:
    void customStep() override {
        std::cout << "Customizing the step in ConcreteAlgorithm..." << std::endl;
    }
};

int main() {
    AbstractAlgorithm* algorithm = new ConcreteAlgorithm();
    algorithm->execute();
    delete algorithm;
    return 0;
}
