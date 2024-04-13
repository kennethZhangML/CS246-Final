#include <iostream>
#include <vector>

class DigitalMedia {

public:
    void play() {
        prePlayAction();
        doPlay();
        postPlayAction();
    }

    virtual void display() = 0;

protected:
    virtual void doPlay() = 0;

    void prePlayAction() {
        std::cout << "Preparing to play..." << std::endl;
    }

    void postPlayAction() { 
        std::cout << "Playback completed." << std::endl;
    }
};  


class Video : public DigitalMedia { 
public:
    void display() override {
        std::cout << "Displaying video." << std::endl;
    }

private:
    void doPlay() override {
        std::cout << "Playing video..." << std::endl;
    }
};

class Audio : public DigitalMedia { 
public:
    void display() override {
        std::cout << "Displaying Audio." << std::endl; 
    }

private:
    void doPlay() override { 
        std::cout << "Playing Audio..." << std::endl;
    }
};

int main() {
    Video video;
    Audio audio;

    std::cout << "Playing Video:" << std::endl;
    video.play();
    std::cout << std::endl;

    std::cout << "Playing Audio:" << std::endl;
    audio.play();
    std::cout << std::endl;

    return 0;
}