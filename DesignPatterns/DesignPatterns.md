# Design Patterns for CS246 Final Exam

## Iterator
- **Definition**: Iterator is a behavioral design pattern that provides a way to access the elements of an aggregate object sequentially without exposing its underlying representation.
- **Key Points**:
  - Iterators provide a uniform way to traverse different types of collections (arrays, lists, trees) without exposing their internal structure.
  - Separates the algorithm for iteration from the underlying collection, promoting a clear separation of concerns.
  - Iterator: `!=, ++, *, begin(), end()` methods are required.

## Observer
- **Definition**: Observer is a behavioral design pattern that defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.
- **Key Points**:
  - Follows the publisher-subscriber model where the subject (publisher) maintains a list of observers (subscribers) and notifies them of any state changes.
  - Promotes loose coupling between objects, allowing for easily extensible and maintainable code.
  - Commonly used in event handling, GUI frameworks, and reactive programming.

## Decorator
- **Definition**: Decorator is a structural design pattern that allows behavior to be added to individual objects dynamically, at runtime, without affecting the behavior of other objects from the same class.
- **Key Points**:
  - Enhances the functionality of objects by wrapping them with one or more decorators, each providing additional features.
  - Follows the open/closed principle, allowing new functionality to be added to existing classes without modifying their structure.
  - Provides an alternative to subclassing for extending functionality, promoting code reuse and flexibility.

## Factory Method
- **Definition**: Factory Method is a creational design pattern that provides an interface for creating objects in a superclass, but allows subclasses to alter the type of objects that will be created.
- **Key Points**:
  - Defines an interface for creating objects but allows subclasses to override the type of objects that will be created.
  - Encapsulates object creation logic, promoting loose coupling between clients and the created objects.
  - Often used when a class cannot anticipate the class of objects it must create or when subclasses need to control the instantiation process.

## Template Method
- **Definition**: Template Method is a behavioral design pattern that defines the skeleton of an algorithm in the superclass but allows subclasses to override specific steps of the algorithm without changing its structure.
- **Key Points**:
  - Defines the steps of an algorithm in a base class, with certain steps implemented in the base class and others left to be implemented by subclasses.
  - Promotes code reuse by providing a common algorithm structure while allowing for variations in specific steps.
  - Often implemented using non-virtual interface (NVI) idiom to separate public interface from implementation details.
