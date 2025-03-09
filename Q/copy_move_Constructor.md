# Copy & Move Constructors and Assignment Operators
```
#include <iostream>

class Array {
private:
    int* data;
    size_t size;

public:
    // Constructor
    Array(size_t sz) : size(sz) {
        data = new int[size];  // Allocate memory
        for (size_t i = 0; i < size; i++) data[i] = i + 1;  // Initialize values
    }

    // Copy Constructor (Deep Copy)
    Array(const Array& other) : size(other.size) {
        data = new int[size];  // Allocate new memory
        for (size_t i = 0; i < size; i++) data[i] = other.data[i];  // Copy data
        std::cout << "Copy Constructor Called" << std::endl;
    }

    // Move Constructor (Efficient Transfer)
    Array(Array&& other) noexcept : size(other.size), data(other.data) {
        other.data = nullptr; // Leave other in a valid state
        other.size = 0;
        std::cout << "Move Constructor Called" << std::endl;
    }

    // Copy Assignment Operator (Deep Copy)
    Array& operator=(const Array& other) {
        if (this == &other) return *this; // Self-assignment check

        delete[] data;  // Free old memory
        size = other.size;
        data = new int[size];  // Allocate new memory
        for (size_t i = 0; i < size; i++) data[i] = other.data[i];  // Copy data

        std::cout << "Copy Assignment Called" << std::endl;
        return *this;
    }

    // Move Assignment Operator (Efficient Transfer)
    Array& operator=(Array&& other) noexcept {
        if (this == &other) return *this; // Self-assignment check

        delete[] data;  // Free old memory
        data = other.data;  // Transfer ownership
        size = other.size;
        other.data = nullptr; // Leave other in a valid state
        other.size = 0;

        std::cout << "Move Assignment Called" << std::endl;
        return *this;
    }

    // Display function
    void display() const {
        if (data) {
            for (size_t i = 0; i < size; i++) std::cout << data[i] << " ";
        } else {
            std::cout << "Empty";
        }
        std::cout << std::endl;
    }

    // Destructor
    ~Array() { delete[] data; }
};

int main() {
    Array a(5);
    std::cout << "Original Object: ";
    a.display();

    // Copy Constructor
    Array b = a;  // Copy constructor is called
    std::cout << "After Copy Construction: ";
    b.display();

    // Move Constructor
    Array c = std::move(a);  // Move constructor is called
    std::cout << "After Move Construction: ";
    c.display();
    std::cout << "Original Object after Move: ";
    a.display(); // Should be "Empty"

    // Copy Assignment
    Array d(5);
    d = b;  // Copy assignment is called
    std::cout << "After Copy Assignment: ";
    d.display();

    // Move Assignment
    Array e(5);
    e = std::move(b);  // Move assignment is called
    std::cout << "After Move Assignment: ";
    e.display();
    std::cout << "Original Object after Move: ";
    b.display(); // Should be "Empty"

    return 0;
}
```
### Output
```
Original Object: 1 2 3 4 5 
Copy Constructor Called
After Copy Construction: 1 2 3 4 5 
Move Constructor Called
After Move Construction: 1 2 3 4 5 
Original Object after Move: Empty
Copy Assignment Called
After Copy Assignment: 1 2 3 4 5 
Move Assignment Called
After Move Assignment: 1 2 3 4 5 
Original Object after Move: Empty
```
## Explanation of Key Features
### Copy Constructor (`Array(const Array& other)`)
- Called when creating a new object from an existing object (Array b = a;).
- Allocates new memory and copies data.

## Move Constructor (`Array(Array&& other)`)
- Called when creating a new object from a temporary or moved object (Array c = std::move(a);).
- Transfers ownership of the memory instead of copying.
- Leaves the source object empty.
  
## Copy Assignment Operator (`operator=(const Array& other)`)
- Used when assigning one existing object to another (d = b;).
- Deletes old memory and performs deep copy.
  
## Move Assignment Operator (`operator=(Array&& other)`)
- Used when assigning a temporary or moved object (e = std::move(b);).
- Transfers ownership of the data (no deep copy).
- Leaves the source object empty.


| Feature	| Copy Constructor (Array(const Array&)) |	Move Constructor (Array(Array&&)) |	Copy Assignment (operator=(const Array&)) |	Move Assignment (operator=(Array&&)) |
|---------|----------------------------------------|------------------------------------|-------------------------------------------|--------------------------------------|
| When Used? |	Array b = a; |	Array c = std::move(a); |	d = b; |	e = std::move(b); |
| Memory Allocation? |	Yes (new allocation) |	No (pointer swap) |	Yes (new allocation) |	No (pointer swap) |
| Speed	| Slower (deep copy) |	Faster (pointer transfer) |	Slower (deep copy) |	Faster (pointer transfer) |
|Use Case |	When object must be copied |	When object is temporary |	When object must be copied |	When object is temporary |

### Key Takeaways
- ✔ Copy constructor & copy assignment are needed when deep copies are required.
- ✔ Move constructor & move assignment improve performance by avoiding unnecessary copying.
- ✔ Use std::move() to enable move operations (Array c = std::move(a);).
- ✔ Always implement both copy and move operations if your class manages dynamic memory.
