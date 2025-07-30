/*
==============================================
Exercise 10: Virtual Functions
==============================================

PROBLEM: Demonstrate virtual functions and runtime polymorphism

Show:
1. Virtual function mechanism
2. Virtual function table (vtable)
3. Pure virtual functions and abstract classes
4. Virtual destructors
5. Early vs Late binding

Expected Output:
Runtime polymorphism demonstrated
Virtual function calls resolved correctly
Abstract classes preventing instantiation
Proper cleanup with virtual destructors
*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cmath>
using namespace std;

// ==============================================
// 1. BASIC VIRTUAL FUNCTIONS
// ==============================================
class Employee
{
protected:
    string name;
    int id;
    double baseSalary;

public:
    Employee(string n, int empId, double salary)
    {
        name = n;
        id = empId;
        baseSalary = salary;
        cout << "Employee constructor: " << name << endl;
    }

    // Virtual function - enables runtime polymorphism
    virtual double calculateSalary()
    {
        cout << "Employee::calculateSalary() called for " << name << endl;
        return baseSalary;
    }

    virtual void displayInfo()
    {
        cout << "Employee ID: " << id << ", Name: " << name
             << ", Base Salary: $" << baseSalary << endl;
    }

    // Non-virtual function - static binding
    void printRole()
    {
        cout << name << " is a general employee" << endl;
    }

    // Virtual destructor - IMPORTANT for proper cleanup
    virtual ~Employee()
    {
        cout << "Employee destructor: " << name << endl;
    }
};

class Manager : public Employee
{
private:
    double bonus;
    int teamSize;

public:
    Manager(string n, int id, double salary, double b, int team)
        : Employee(n, id, salary), bonus(b), teamSize(team)
    {
        cout << "Manager constructor: " << name << endl;
    }

    // Override virtual function
    double calculateSalary() override
    {
        cout << "Manager::calculateSalary() called for " << name << endl;
        return baseSalary + bonus + (teamSize * 500); // Team bonus
    }

    void displayInfo() override
    {
        Employee::displayInfo(); // Call base class version
        cout << "Role: Manager, Bonus: $" << bonus
             << ", Team Size: " << teamSize << endl;
    }

    // Non-virtual function with same name (hiding, not overriding)
    void printRole()
    {
        cout << name << " is a manager leading " << teamSize << " people" << endl;
    }

    ~Manager()
    {
        cout << "Manager destructor: " << name << endl;
    }
};

class Developer : public Employee
{
private:
    string programmingLanguage;
    int projectsCompleted;

public:
    Developer(string n, int id, double salary, string lang, int projects)
        : Employee(n, id, salary), programmingLanguage(lang), projectsCompleted(projects)
    {
        cout << "Developer constructor: " << name << endl;
    }

    double calculateSalary() override
    {
        cout << "Developer::calculateSalary() called for " << name << endl;
        return baseSalary + (projectsCompleted * 1000); // Project bonus
    }

    void displayInfo() override
    {
        Employee::displayInfo();
        cout << "Role: Developer, Language: " << programmingLanguage
             << ", Projects: " << projectsCompleted << endl;
    }

    ~Developer()
    {
        cout << "Developer destructor: " << name << endl;
    }
};

// ==============================================
// 2. PURE VIRTUAL FUNCTIONS & ABSTRACT CLASSES
// ==============================================
class Shape
{
protected:
    string shapeName;
    static int shapeCount;

public:
    Shape(string name) : shapeName(name)
    {
        shapeCount++;
        cout << "Shape constructor: " << shapeName << endl;
    }

    // Pure virtual functions - make this class abstract
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
    virtual void draw() = 0;

    // Regular virtual function with implementation
    virtual void displayInfo()
    {
        cout << "Shape: " << shapeName << ", Area: " << calculateArea()
             << ", Perimeter: " << calculatePerimeter() << endl;
    }

    // Non-virtual function
    static int getShapeCount()
    {
        return shapeCount;
    }

    string getName() const
    {
        return shapeName;
    }

    // Virtual destructor
    virtual ~Shape()
    {
        shapeCount--;
        cout << "Shape destructor: " << shapeName << endl;
    }
};

int Shape::shapeCount = 0;

// Cannot instantiate Shape directly - it's abstract
// Shape s("test");  // This would cause compilation error

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : Shape("Rectangle"), length(l), width(w)
    {
        cout << "Rectangle constructor: " << length << "x" << width << endl;
    }

    // Must implement all pure virtual functions
    double calculateArea() override
    {
        return length * width;
    }

    double calculatePerimeter() override
    {
        return 2 * (length + width);
    }

    void draw() override
    {
        cout << "Drawing Rectangle: " << length << "x" << width << endl;
        cout << "┌";
        for (int i = 0; i < (int)length; i++)
            cout << "─";
        cout << "┐" << endl;
        for (int i = 0; i < (int)width; i++)
        {
            cout << "│";
            for (int j = 0; j < (int)length; j++)
                cout << " ";
            cout << "│" << endl;
        }
        cout << "└";
        for (int i = 0; i < (int)length; i++)
            cout << "─";
        cout << "┘" << endl;
    }

    ~Rectangle()
    {
        cout << "Rectangle destructor" << endl;
    }
};

class Circle : public Shape
{
private:
    double radius;
    static constexpr double PI = 3.14159;

public:
    Circle(double r) : Shape("Circle"), radius(r)
    {
        cout << "Circle constructor: radius=" << radius << endl;
    }

    double calculateArea() override
    {
        return PI * radius * radius;
    }

    double calculatePerimeter() override
    {
        return 2 * PI * radius;
    }

    void draw() override
    {
        cout << "Drawing Circle with radius " << radius << endl;
        int size = (int)(radius * 2);
        for (int i = 0; i <= size; i++)
        {
            for (int j = 0; j <= size; j++)
            {
                double distance = sqrt((i - radius) * (i - radius) + (j - radius) * (j - radius));
                if (distance > radius - 0.5 && distance < radius + 0.5)
                {
                    cout << "* ";
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }

    ~Circle()
    {
        cout << "Circle destructor" << endl;
    }
};

// ==============================================
// 3. VIRTUAL FUNCTION TABLE DEMONSTRATION
// ==============================================
class Base
{
public:
    Base() { cout << "Base constructor" << endl; }

    virtual void func1() { cout << "Base::func1()" << endl; }
    virtual void func2() { cout << "Base::func2()" << endl; }
    void func3() { cout << "Base::func3() - Non-virtual" << endl; }

    virtual ~Base() { cout << "Base destructor" << endl; }
};

class Derived1 : public Base
{
public:
    Derived1() { cout << "Derived1 constructor" << endl; }

    void func1() override { cout << "Derived1::func1()" << endl; }
    // func2 not overridden - will use Base version
    void func3() { cout << "Derived1::func3() - Hiding" << endl; }

    virtual void func4() { cout << "Derived1::func4() - New virtual function" << endl; }

    ~Derived1() { cout << "Derived1 destructor" << endl; }
};

class Derived2 : public Base
{
public:
    Derived2() { cout << "Derived2 constructor" << endl; }

    void func1() override { cout << "Derived2::func1()" << endl; }
    void func2() override { cout << "Derived2::func2()" << endl; }

    ~Derived2() { cout << "Derived2 destructor" << endl; }
};

// ==============================================
// 4. ADVANCED VIRTUAL FUNCTION CONCEPTS
// ==============================================
class Animal
{
public:
    virtual void makeSound() = 0;                           // Pure virtual
    virtual void move() { cout << "Animal moves" << endl; } // Virtual with default

    // Virtual function called from constructor
    Animal()
    {
        cout << "Animal constructor" << endl;
        // NOTE: Virtual functions don't work as expected when called from constructors
        // They will call the current class version, not the derived class version
        initialize();
    }

    virtual void initialize()
    {
        cout << "Animal::initialize() called" << endl;
    }

    virtual ~Animal() { cout << "Animal destructor" << endl; }
};

class Dog : public Animal
{
public:
    Dog()
    {
        cout << "Dog constructor" << endl;
    }

    void makeSound() override
    {
        cout << "Dog: Woof!" << endl;
    }

    void move() override
    {
        cout << "Dog runs on four legs" << endl;
    }

    void initialize() override
    {
        cout << "Dog::initialize() called" << endl;
    }

    ~Dog() { cout << "Dog destructor" << endl; }
};

// Function to demonstrate runtime polymorphism
void demonstrateVirtualFunctions()
{
    cout << "\n=== VIRTUAL FUNCTION MECHANISM ===" << endl;

    // Array of base class pointers
    vector<unique_ptr<Employee>> employees;

    employees.push_back(make_unique<Employee>("John Doe", 1001, 50000));
    employees.push_back(make_unique<Manager>("Jane Smith", 1002, 80000, 15000, 5));
    employees.push_back(make_unique<Developer>("Bob Johnson", 1003, 70000, "C++", 3));

    cout << "\n--- Runtime Polymorphism ---" << endl;
    for (auto &emp : employees)
    {
        emp->displayInfo();
        cout << "Calculated Salary: $" << emp->calculateSalary() << endl;
        cout << "---" << endl;
    }

    cout << "\n--- Static vs Dynamic Binding ---" << endl;
    Employee *empPtr = new Manager("Alice Brown", 1004, 75000, 20000, 8);

    // Virtual function - runtime binding
    empPtr->calculateSalary(); // Calls Manager version
    empPtr->displayInfo();     // Calls Manager version

    // Non-virtual function - compile-time binding
    empPtr->printRole(); // Calls Employee version (static binding)

    // Clean up
    delete empPtr;
}

void demonstrateAbstractClasses()
{
    cout << "\n=== ABSTRACT CLASSES & PURE VIRTUAL FUNCTIONS ===" << endl;

    // Shape shape("test");  // ERROR - cannot instantiate abstract class

    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Rectangle>(5, 3));
    shapes.push_back(make_unique<Circle>(4));

    cout << "\n--- Polymorphic Shape Operations ---" << endl;
    for (auto &shape : shapes)
    {
        shape->draw();
        shape->displayInfo();
        cout << "---" << endl;
    }

    cout << "Total shapes created: " << Shape::getShapeCount() << endl;
}

void demonstrateVTable()
{
    cout << "\n=== VIRTUAL FUNCTION TABLE DEMO ===" << endl;

    Base *objects[] = {
        new Base(),
        new Derived1(),
        new Derived2()};

    cout << "\n--- Virtual Function Calls ---" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Object " << i << ":" << endl;
        objects[i]->func1(); // Virtual - runtime binding
        objects[i]->func2(); // Virtual - runtime binding
        objects[i]->func3(); // Non-virtual - static binding
        cout << endl;
    }

    // Clean up
    for (int i = 0; i < 3; i++)
    {
        delete objects[i]; // Virtual destructor ensures proper cleanup
    }
}

int main()
{
    cout << "=== VIRTUAL FUNCTIONS DEMONSTRATION ===" << endl;

    // 1. Basic virtual functions
    demonstrateVirtualFunctions();

    // 2. Abstract classes and pure virtual functions
    demonstrateAbstractClasses();

    // 3. Virtual function table demonstration
    demonstrateVTable();

    // 4. Virtual function behavior in constructors
    cout << "\n=== VIRTUAL FUNCTIONS IN CONSTRUCTORS ===" << endl;
    {
        cout << "Creating Dog object:" << endl;
        Dog dog; // Virtual function called from constructor uses current class version
        cout << "\nCalling virtual functions after construction:" << endl;
        dog.makeSound();
        dog.move();
    }

    // 5. Importance of virtual destructors
    cout << "\n=== VIRTUAL DESTRUCTORS ===" << endl;
    {
        cout << "With virtual destructor:" << endl;
        Animal *animalPtr = new Dog();
        delete animalPtr; // Calls both Dog and Animal destructors
    }

    cout << "\n=== Program Ending ===" << endl;
    return 0;
}

/*
VIRTUAL FUNCTIONS SUMMARY:

1. VIRTUAL FUNCTION MECHANISM:
   - Declared with 'virtual' keyword in base class
   - Enable runtime polymorphism (late binding)
   - Function call resolved at runtime using vtable
   - Override with same signature in derived classes

2. VIRTUAL FUNCTION TABLE (vtable):
   - Each class with virtual functions has a vtable
   - Contains pointers to virtual function implementations
   - Object contains pointer to its class's vtable
   - Runtime: vtable lookup determines which function to call

3. PURE VIRTUAL FUNCTIONS:
   - Syntax: virtual function() = 0;
   - Makes class abstract (cannot be instantiated)
   - Must be implemented in derived classes
   - Used to define interface contracts

4. VIRTUAL DESTRUCTORS:
   - CRITICAL when using inheritance with polymorphism
   - Ensures proper cleanup of derived class objects
   - Called in reverse order of construction
   - Always make base class destructor virtual if class has virtual functions

5. BINDING TYPES:
   - Static (Early) Binding: Compile-time resolution
   - Dynamic (Late) Binding: Runtime resolution using vtable

6. IMPORTANT RULES:
   - Virtual functions don't work as expected in constructors/destructors
   - Cannot be static, template, or friend functions
   - Can have default parameters (but be careful with overriding)
   - Performance overhead due to vtable lookup

7. WHEN TO USE:
   - When you need runtime polymorphism
   - Interface design with abstract base classes
   - Polymorphic containers (vector<Base*>)
   - Factory patterns

PERFORMANCE CONSIDERATIONS:
- Virtual function calls have slight overhead (vtable lookup)
- Each object with virtual functions has vtable pointer (memory overhead)
- Modern compilers can optimize some virtual calls (devirtualization)

COMMON MISTAKES:
1. Forgetting virtual destructor in base class
2. Calling virtual functions from constructors expecting derived behavior
3. Not using override keyword (C++11+)
4. Mixing virtual and non-virtual functions carelessly

PRACTICE EXERCISES:

1. Create a Media Player hierarchy:
   - Abstract MediaPlayer base class
   - Concrete implementations: AudioPlayer, VideoPlayer
   - Pure virtual functions: play(), pause(), stop()

2. Create a Drawing Application:
   - Abstract Drawable base class
   - Various shape classes implementing draw()
   - Canvas class that holds collection of Drawable objects

3. Create a Game Entity System:
   - Abstract GameObject base class
   - Derived classes: Player, Enemy, PowerUp
   - Virtual functions: update(), render(), handleCollision()

4. Banking System with Polymorphism:
   - Abstract Account base class
   - Different account types with different behaviors
   - Virtual functions for transactions and interest calculation
*/
