#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

class Observer {
public:
    virtual void update() = 0;
    virtual ~Observer() {};
};

class GameModel {
    std::vector<Observer*> observers;
    int gameState;
public:
    GameModel() : gameState(0) {}

    void addObserver(Observer* obs) {
        observers.push_back(obs);
    }

    void makeMove(int move) {
        std::cout << "Making move: " << move << std::endl;
        gameState += move;

        notifyObservers();
    }

    void notifyObservers() {
        for (auto& observer : observers) {
            observer->update();
        }
    }

    int getState() const {
        return gameState;
    }

    virtual ~GameModel() {};
};

class GameView : public Observer {
    GameModel& model;

public:
    GameView(GameModel& m) : model(m) {
        model.addObserver(this);
    }

    void update() override {
        std::cout << "View: Current game state is " << model.getState() << std::endl;
    }

    void display() {
        std::cout << "Displaying game state: " << model.getState() << std::endl;
    }

    virtual ~GameView() {};
};

class GameController {
    GameModel& model;

public:
    GameController(GameModel& m) : model(m) {}

    void processInput(int move) {
        model.makeMove(move);
    }

    virtual ~GameController() {};
};


int main() {
    GameModel model; 
    GameController gc(model); 

    std::ifstream file("testfile.in");
    
    if (file.is_open()) {
        std::string line;
        int n;
        while (getline(file, line)) {
            std::istringstream ss{line};
            ss >> n;
            gc.processInput(n);
        }

        return 0;
    }
}