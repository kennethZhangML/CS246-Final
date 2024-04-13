# Template Method Design Pattern

The Template Method is a behavioral design pattern that defines the skeleton of an algorithm in the superclass but lets subclasses override specific steps of the algorithm without changing its structure. This pattern is useful when you have an algorithm that follows a specific sequence of steps but allows for customization of some of those steps.

## Structure

The Template Method pattern typically consists of the following components:

- **Abstract Class**: This class defines the template method, which is the algorithm skeleton. It may also contain abstract methods that represent the steps of the algorithm to be implemented by subclasses.

- **Concrete Class (Subclasses)**: These classes extend the abstract class and implement the abstract methods to provide concrete implementations of the algorithm steps. They can also override the template method if necessary.

## Example

Consider a scenario where we have a base class `Turtle` representing a turtle drawing algorithm. The turtle has three main steps: drawing feet, drawing head, and drawing shell. We want to allow subclasses to customize the drawing of the shell while keeping the overall algorithm structure intact.

```cpp
class Turtle {
public:
    void draw() {
        drawFeet();
        drawHead();
        drawShell();
    }

private:
    virtual void drawFeet() = 0;
    virtual void drawHead() = 0;
    virtual void drawShell() = 0;
};
