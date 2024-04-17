### Basic Pointer Management:

- Create a `shared_ptr` to an integer and initialize it with a new dynamically allocated integer.

- Create a `unique_ptr` to a string and initialize it with a new dynamically allocated string.

### Transfer Ownership:

- Write a function that takes a `unique_ptr` to a vector of integers as a parameter and returns a `shared_ptr` to the same vector.

- Write a function that takes a `shared_ptr` to a map of strings to doubles and returns a `unique_ptr` to the same map.

### Accessing Elements:

- Create a `unique_ptr` to a dynamically allocated array of floats with a size of 5. Populate the array with some values and print them out.

- Create a `shared_ptr` to a dynamically allocated list of characters. Add some characters to the list and print them out.

### Circular References:

- Create two classes, A and B. A should have a `shared_ptr<B>` member, and B should have a `shared_ptr<A>` member. Make sure these classes can be constructed without any memory leaks or circular reference issues.

- Modify the classes so that A holds a `unique_ptr<B>` and B holds a `unique_ptr<A>`. Test that the objects can be constructed and destroyed without any memory leaks.

### Exception Handling:

- Write a function that creates a `unique_ptr` to a dynamically allocated object, and then intentionally throws an exception before transferring ownership to a `shared_ptr`. Ensure that memory is properly deallocated in the event of an exception.

- Write a function that creates a `shared_ptr` to a dynamically allocated object, and then intentionally throws an exception before transferring ownership to a `unique_ptr`. Ensure that memory is properly deallocated in the event of an exception.

### Custom Deleters:

- Create a custom deleter function that prints a message when invoked and use it with a `shared_ptr` to a dynamically allocated object.

- Create a custom deleter function that logs the deallocation of an object to a file and use it with a `unique_ptr` to a dynamically allocated object.
