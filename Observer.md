# Observer Design Pattern

The Observer pattern is a behavioral design pattern that defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically. It's often compared to a publisher-subscriber model where the subject (publisher) maintains a list of its dependents (subscribers) and notifies them of any state changes.

## Understanding the Provided Code:

### Subject:

The `Subject` class represents the entity being observed. It maintains a list of observers and provides methods to attach, detach, and notify observers.
- `attach(Observer* o)`: Adds an observer to the list.
- `detach(Observer* o)`: Removes an observer from the list.
- `notifyObservers()`: Notifies all observers when a state change occurs.

### Observer:

The `Observer` class is an abstract class/interface that defines the interface for objects that should be notified of changes in the subject.
- It declares a pure virtual method `notify()` which concrete observers must implement.

### Concrete Subject - HorseRace:

`HorseRace` is a concrete class that inherits from `Subject`. It represents a horse race scenario where observers (bettors) are interested in the outcome of the race.
- It has an `ifstream` member for reading race data and a `lastWinner` member to store the winner of the race.
- `runRace()`: Simulates running a race. It reads the winner from the input file and notifies observers.
- `winner()`: Returns the last winner of the race.

### Concrete Observer - Bettor:

`Bettor` is a concrete class that inherits from `Observer`. It represents a bettor who observes the race and reacts based on their favorite horse.
- It has members for the name of the bettor, their favorite horse, and a pointer to the observed `HorseRace`.
- In the constructor, it attaches itself to the `HorseRace` subject.
- `notify()`: Overrides the `notify()` method from the `Observer` class. It reacts to the race outcome by printing "Yay!" if the favorite horse wins, otherwise "Boo!".

### Main Function:

In the `main()` function:
- A `HorseRace` object is created with a filename.
- A `Bettor` object is also created, subscribing to the `HorseRace`.
- Inside a loop, the race is simulated (`runRace()`) and observers are notified.
- The loop continues until there are no more races.
