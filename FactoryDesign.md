# Factory Method Design Pattern

## Overview

The Factory Method design pattern is a creational pattern that provides an interface for creating objects in a superclass but allows subclasses to alter the type of objects that will be created. It encapsulates object creation by defining a method that subclasses implement to produce objects. This pattern promotes loose coupling between client code and the concrete classes being instantiated.

## How it Works

### Participants

1. **Creator**: This is typically an abstract class or interface that declares the factory method, which returns an object of type `Product`. The creator may also provide a default implementation for the factory method.
2. **Concrete Creator**: Concrete classes that inherit from the Creator class and implement the factory method to produce specific types of objects.
3. **Product**: The abstract class or interface that defines the type of object the factory method returns.
4. **Concrete Product**: Concrete classes that implement the Product interface.

### Workflow

1. **Client Code Requests an Object**: The client code interacts with the Creator class to request an object through the factory method.
2. **Creator Delegates Object Creation**: Instead of directly creating the object, the Creator delegates the responsibility of object creation to its subclasses by calling the factory method.
3. **Subclasses Implement Factory Method**: Each Concrete Creator subclass implements the factory method to create and return a specific type of object.
4. **Object Creation is Decoupled**: The client code remains decoupled from the actual implementation of object creation. It only interacts with the Creator class and does not need to know the specific subclass that creates the object.

### Example

In the provided example:

- **Creator**: The `Level` class declares the factory method `create()`.
- **Concrete Creators**: The `Easy` and `Hard` classes inherit from `Level` and implement the `create()` method to create different types of enemies (`Turtle` or `Bullet`).
- **Product**: The `Enemy` class represents the abstract product.
- **Concrete Products**: The `Turtle` and `Bullet` classes represent the concrete products.

When the client code requests an enemy object from a level, it interacts with the `Level` class without needing to know the specific subclass (`Easy` or `Hard`). The factory method in each subclass determines the type of enemy to create based on the level's difficulty.

## Advantages

- Encapsulates object creation logic, making it easy to change or extend without modifying client code.
- Promotes loose coupling between client code and concrete classes.
- Allows for easy subclassing to create variations of objects.

## Disadvantages

- Can lead to an explosion of subclasses if there are many variations of objects to create.
- Clients might need to subclass the Creator class to provide a custom factory method implementation, which can lead to a complex class hierarchy.

## Conclusion

The Factory Method design pattern is a powerful tool for encapsulating object creation and promoting loose coupling in object-oriented systems. By delegating object creation to subclasses, it allows for flexibility and extensibility in creating objects of different types.
