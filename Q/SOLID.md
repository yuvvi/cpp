# SOLID Principles
The SOLID principles are five design principles that help developers create maintainable, scalable, and flexible software. They are:
1. S – Single Responsibility Principle (SRP)
2. O – Open/Closed Principle (OCP)
3. L – Liskov Substitution Principle (LSP)
4. I – Interface Segregation Principle (ISP)
5. D – Dependency Inversion Principle (DIP)

## 1. Single Responsibility Principle (SRP)
Each class should have only one reason to change.

### Example (Violation of SRP)
```
#include <iostream>
#include <fstream>
using namespace std;

class Report {
public:
    string content;

    void generateReport() {
        content = "Report Data";
        cout << "Report generated." << endl;
    }

    void saveToFile() {  // Violation: Report should not handle file operations
        ofstream file("report.txt");
        file << content;
        file.close();
    }
};
```
👉 Problem: The Report class has two responsibilities:

> Generating the report.\
> Saving the report to a file.

### Corrected Example (SRP Applied)
```
class Report {
public:
    string content;

    void generateReport() {
        content = "Report Data";
        cout << "Report generated." << endl;
    }
};

class FileManager {
public:
    static void saveToFile(const Report& report) {
        ofstream file("report.txt");
        file << report.content;
        file.close();
    }
};
```
✅ Now, the **Report** class only generates reports, and **FileManager** handles file saving.

## 2. Open/Closed Principle (OCP)
A class should be open for extension but closed for modification.

### Example (Violation of OCP)
```
class Rectangle {
public:
    double width, height;
};

class AreaCalculator {
public:
    double calculateArea(Rectangle rect) {
        return rect.width * rect.height;
    }
};
```
👉 Problem: If we add a **Circle** class, we must modify **AreaCalculator**.

### Corrected Example (OCP Applied)
```
class Shape {
public:
    virtual double area() const = 0;  // Abstract method
};

class Rectangle : public Shape {
public:
    double width, height;
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
};

class Circle : public Shape {
public:
    double radius;
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14159 * radius * radius; }
};

class AreaCalculator {
public:
    static double calculateArea(const Shape& shape) {
        return shape.area();
    }
};
```
✅ Now, we can add more shapes (e.g., Triangle, Polygon) without modifying AreaCalculator.

## 3. Liskov Substitution Principle (LSP)
Derived classes should be substitutable for their base class without altering program behavior.

### Example (Violation of LSP)
```
class Bird {
public:
    virtual void fly() { cout << "Flying" << endl; }
};

class Penguin : public Bird {
public:
    void fly() override { throw runtime_error("Penguins cannot fly!"); }
};
```
👉 Problem: If a function expects a Bird, it may break when passing a Penguin.

### Corrected Example (LSP Applied)
```
class Bird {
public:
    virtual void move() { cout << "Moving" << endl; }
};

class FlyingBird : public Bird {
public:
    virtual void fly() { cout << "Flying" << endl; }
};

class Sparrow : public FlyingBird {};

class Penguin : public Bird {
public:
    void move() override { cout << "Swimming" << endl; }
};
```
✅ Now, Penguin follows the LSP as it does not inherit unnecessary behaviors.

## 4. Interface Segregation Principle (ISP)
A class should not be forced to implement interfaces it does not use.

### Example (Violation of ISP)
```
class Worker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;  // Not all workers need this
};

class Robot : public Worker {
public:
    void work() override { cout << "Robot working" << endl; }
    void eat() override { throw runtime_error("Robots don't eat!"); }
};
```
👉 Problem: Robot is forced to implement eat(), which it doesn't need.

### Corrected Example (ISP Applied)
```
class Workable {
public:
    virtual void work() = 0;
};

class Eatable {
public:
    virtual void eat() = 0;
};

class Human : public Workable, public Eatable {
public:
    void work() override { cout << "Human working" << endl; }
    void eat() override { cout << "Human eating" << endl; }
};

class Robot : public Workable {
public:
    void work() override { cout << "Robot working" << endl; }
};
```
✅ Now, Robot only implements Workable and avoids unnecessary methods.

## 5. Dependency Inversion Principle (DIP)
High-level modules should not depend on low-level modules. Both should depend on abstractions.

### Example (Violation of DIP)
```
class Keyboard {
public:
    void input() { cout << "Typing..." << endl; }
};

class Computer {
    Keyboard keyboard;
public:
    void operate() { keyboard.input(); }
};
```
👉 Problem: Computer is tightly coupled to Keyboard, making it hard to replace with another input device.

Corrected Example (DIP Applied)
```
class InputDevice {
public:
    virtual void input() = 0;
};

class Keyboard : public InputDevice {
public:
    void input() override { cout << "Typing..." << endl; }
};

class Touchscreen : public InputDevice {
public:
    void input() override { cout << "Touch input..." << endl; }
};

class Computer {
    InputDevice& device;
public:
    Computer(InputDevice& dev) : device(dev) {}
    void operate() { device.input(); }
};
```
✅ Now, Computer can work with any InputDevice (Keyboard, Touchscreen, etc.).

| SOLID | comment |
| ----- | ------- |
| SRP-Single responsibility principle | One class, one responsibility. |
| OCP-Open/Close principle | Open for extension, close for modification |
| LSP-Liskov substitution principle | Derived classes should be substitutable for their base class without altering program behavior. |
|ISP-Interface segragation principle | A class should not be forced to implement interfaces it does not use. |
|DIP-Dependency inversion principle| High-level modules should not depend on low-level modules. Both should depend on abstractions. |

# Favor COMPOSITION over INHERITANCE
- Inheritance is main state of object oriented design & programming.
- With inheritance we can avoid code duplication by inheriting behavior.
- This is a powerful technique, But its a techinque that can easily be overused.
- This is also a technique that are far too rigged and not extensible.

> **HAS-A** is better than **IS-A**

**IS-A** is an INHERITANCE relationship.\
**HAS-A** is a COMPOSITION relationship.
