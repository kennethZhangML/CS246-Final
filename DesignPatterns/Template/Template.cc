#include <iostream>

// non-virtual interface idiom
// non-virtual methods are public (except dtors)
// virtuals are private or protected

class DigitalMedia {
public:
    void play() {
        prePlayAction();
        doPlay();
        postPlayAction();
    }

protected:
    virtual void doPlay() = 0;
    virtual void display() = 0;

private:
    void prePlayAction() {
        std::cout << "Starting to play..." << std::endl;
    }

    void postPlayAction() {
        std::cout << "Finished Playing." << std::endl;
    }
};

class Video : public DigitalMedia { 
public:
    void display() {
        std::cout << "Video DigitalMedia." << std::endl;
    }

    void doPlay() {
        std::cout << "Playing Video..." << std::endl;
    }
};

class Music : public DigitalMedia {
public:
    void display() {
        std::cout << "Music DigitalMedia." << std::endl;
    }

    void doPlay() {
        std::cout << "Playing Music..." << std::endl;
    }
};

int main() {
    // playing music DigitalMedia  
    
    Music myMusic;
    myMusic.display();
    myMusic.play();

    return 0;
}
