/*
==============================================
Exercise 9: Polymorphism
==============================================

PROBLEM: Demonstrate function overloading and function overriding

Show:
1. Function Overloading (Compile-time Polymorphism)
2. Function Overriding (Runtime Polymorphism)
3. Operator Overloading
4. Early vs Late Binding

Expected Output:
Different functions called based on parameters and object types
Compile-time and runtime polymorphism demonstrated
Operator overloading working correctly
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ==============================================
// 1. FUNCTION OVERLOADING (Compile-time Polymorphism)
// ==============================================
class Calculator
{
public:
    // Function overloading - same name, different parameters

    // Add two integers
    int add(int a, int b)
    {
        cout << "Adding two integers: ";
        return a + b;
    }

    // Add three integers
    int add(int a, int b, int c)
    {
        cout << "Adding three integers: ";
        return a + b + c;
    }

    // Add two doubles
    double add(double a, double b)
    {
        cout << "Adding two doubles: ";
        return a + b;
    }

    // Add two strings
    string add(string a, string b)
    {
        cout << "Concatenating two strings: ";
        return a + b;
    }

    // Add array elements
    int add(int arr[], int size)
    {
        cout << "Adding array elements: ";
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += arr[i];
        }
        return sum;
    }

    // Multiply with different parameter types
    int multiply(int a, int b)
    {
        cout << "Multiplying integers: ";
        return a * b;
    }

    double multiply(double a, double b)
    {
        cout << "Multiplying doubles: ";
        return a * b;
    }

    // Function with default parameters (another form of overloading)
    double power(double base, int exponent = 2)
    {
        cout << "Power function (base=" << base << ", exp=" << exponent << "): ";
        double result = 1;
        for (int i = 0; i < exponent; i++)
        {
            result *= base;
        }
        return result;
    }
};

// ==============================================
// 2. OPERATOR OVERLOADING
// ==============================================
class Complex
{
private:
    double real;
    double imaginary;

public:
    Complex(double r = 0, double i = 0)
    {
        real = r;
        imaginary = i;
    }

    // Overload + operator
    Complex operator+(const Complex &other) const
    {
        cout << "Using overloaded + operator" << endl;
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // Overload - operator
    Complex operator-(const Complex &other) const
    {
        cout << "Using overloaded - operator" << endl;
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    // Overload * operator
    Complex operator*(const Complex &other) const
    {
        cout << "Using overloaded * operator" << endl;
        double r = real * other.real - imaginary * other.imaginary;
        double i = real * other.imaginary + imaginary * other.real;
        return Complex(r, i);
    }

    // Overload == operator
    bool operator==(const Complex &other) const
    {
        return (real == other.real && imaginary == other.imaginary);
    }

    // Overload << operator for output
    friend ostream &operator<<(ostream &os, const Complex &c)
    {
        os << c.real;
        if (c.imaginary >= 0)
            os << " + ";
        else
            os << " - ";
        os << abs(c.imaginary) << "i";
        return os;
    }

    // Overload >> operator for input
    friend istream &operator>>(istream &is, Complex &c)
    {
        cout << "Enter real part: ";
        is >> c.real;
        cout << "Enter imaginary part: ";
        is >> c.imaginary;
        return is;
    }

    // Overload [] operator (for accessing real/imaginary parts)
    double operator[](int index) const
    {
        if (index == 0)
            return real;
        else if (index == 1)
            return imaginary;
        else
            throw out_of_range("Index must be 0 or 1");
    }

    // Overload ++ operator (prefix)
    Complex &operator++()
    {
        ++real;
        ++imaginary;
        return *this;
    }

    // Overload ++ operator (postfix)
    Complex operator++(int)
    {
        Complex temp = *this;
        real++;
        imaginary++;
        return temp;
    }
};

// ==============================================
// 3. FUNCTION OVERRIDING (Runtime Polymorphism)
// ==============================================
class Shape
{
protected:
    string name;
    double area;

public:
    Shape(string n) : name(n), area(0)
    {
        cout << "Shape constructor: " << name << endl;
    }

    // Virtual function - enables runtime polymorphism
    virtual double calculateArea()
    {
        cout << "Base Shape calculateArea() called" << endl;
        return 0;
    }

    virtual void display()
    {
        cout << "Shape: " << name << ", Area: " << area << endl;
    }

    // Pure virtual function - makes this an abstract class
    virtual double getPerimeter() = 0;

    virtual ~Shape()
    {
        cout << "Shape destructor: " << name << endl;
    }
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : Shape("Rectangle"), length(l), width(w)
    {
        cout << "Rectangle constructor" << endl;
    }

    // Override virtual function
    double calculateArea() override
    {
        cout << "Rectangle calculateArea() called" << endl;
        area = length * width;
        return area;
    }

    void display() override
    {
        cout << "Rectangle: " << length << "x" << width << ", Area: " << area << endl;
    }

    double getPerimeter() override
    {
        return 2 * (length + width);
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
        cout << "Circle constructor" << endl;
    }

    // Override virtual function
    double calculateArea() override
    {
        cout << "Circle calculateArea() called" << endl;
        area = PI * radius * radius;
        return area;
    }

    void display() override
    {
        cout << "Circle: radius=" << radius << ", Area: " << area << endl;
    }

    double getPerimeter() override
    {
        return 2 * PI * radius;
    }

    ~Circle()
    {
        cout << "Circle destructor" << endl;
    }
};

class Triangle : public Shape
{
private:
    double base;
    double height;
    double side1, side2, side3;

public:
    Triangle(double b, double h, double s1, double s2, double s3)
        : Shape("Triangle"), base(b), height(h), side1(s1), side2(s2), side3(s3)
    {
        cout << "Triangle constructor" << endl;
    }

    double calculateArea() override
    {
        cout << "Triangle calculateArea() called" << endl;
        area = 0.5 * base * height;
        return area;
    }

    void display() override
    {
        cout << "Triangle: base=" << base << ", height=" << height << ", Area: " << area << endl;
    }

    double getPerimeter() override
    {
        return side1 + side2 + side3;
    }

    ~Triangle()
    {
        cout << "Triangle destructor" << endl;
    }
};

// ==============================================
// 4. ADVANCED POLYMORPHISM EXAMPLE
// ==============================================
class Animal
{
protected:
    string species;

public:
    Animal(string s) : species(s) {}

    virtual void makeSound() = 0; // Pure virtual function
    virtual void move() = 0;      // Pure virtual function
    virtual void eat(string food) = 0;

    // Virtual function with default implementation
    virtual void sleep()
    {
        cout << species << " is sleeping..." << endl;
    }

    virtual ~Animal() {}
};

class Dog : public Animal
{
public:
    Dog() : Animal("Dog") {}

    void makeSound() override
    {
        cout << "Dog: Woof! Woof!" << endl;
    }

    void move() override
    {
        cout << "Dog: Running on four legs" << endl;
    }

    void eat(string food) override
    {
        cout << "Dog: Eating " << food << " with enthusiasm!" << endl;
    }

    // Additional function specific to Dog
    void wagTail()
    {
        cout << "Dog: Wagging tail happily!" << endl;
    }
};

class Bird : public Animal
{
public:
    Bird() : Animal("Bird") {}

    void makeSound() override
    {
        cout << "Bird: Tweet! Tweet!" << endl;
    }

    void move() override
    {
        cout << "Bird: Flying in the sky" << endl;
    }

    void eat(string food) override
    {
        cout << "Bird: Pecking at " << food << endl;
    }

    void sleep() override
    {
        cout << "Bird: Sleeping in the nest" << endl;
    }
};

// Function to demonstrate runtime polymorphism
void demonstratePolymorphism(Animal *animal, string food)
{
    cout << "\n--- Polymorphic behavior ---" << endl;
    animal->makeSound();
    animal->move();
    animal->eat(food);
    animal->sleep();
}

// Function to demonstrate function overloading
void processShapes(Shape *shapes[], int count)
{
    cout << "\n--- Processing shapes polymorphically ---" << endl;

    for (int i = 0; i < count; i++)
    {
        shapes[i]->calculateArea(); // Runtime polymorphism
        shapes[i]->display();
        cout << "Perimeter: " << shapes[i]->getPerimeter() << endl;
        cout << "---" << endl;
    }
}

int main()
{
    cout << "=== POLYMORPHISM DEMONSTRATION ===" << endl;

    // 1. Function Overloading (Compile-time Polymorphism)
    cout << "\n=== 1. FUNCTION OVERLOADING ===" << endl;
    Calculator calc;

    cout << calc.add(5, 3) << endl;
    cout << calc.add(1, 2, 3) << endl;
    cout << calc.add(2.5, 3.7) << endl;
    cout << calc.add("Hello", "World") << endl;

    int arr[] = {1, 2, 3, 4, 5};
    cout << calc.add(arr, 5) << endl;

    cout << calc.multiply(4, 5) << endl;
    cout << calc.multiply(2.5, 4.0) << endl;

    cout << calc.power(3) << endl;    // Uses default exponent = 2
    cout << calc.power(2, 5) << endl; // Explicit exponent

    // 2. Operator Overloading
    cout << "\n=== 2. OPERATOR OVERLOADING ===" << endl;
    Complex c1(3, 4);
    Complex c2(1, 2);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    Complex c3 = c1 + c2;
    cout << "c1 + c2 = " << c3 << endl;

    Complex c4 = c1 - c2;
    cout << "c1 - c2 = " << c4 << endl;

    Complex c5 = c1 * c2;
    cout << "c1 * c2 = " << c5 << endl;

    cout << "c1 == c2: " << (c1 == c2) << endl;
    cout << "c1[0] (real part): " << c1[0] << endl;
    cout << "c1[1] (imaginary part): " << c1[1] << endl;

    Complex c6 = c1++; // Postfix
    cout << "After c1++: c1 = " << c1 << ", returned value = " << c6 << endl;

    ++c2; // Prefix
    cout << "After ++c2: c2 = " << c2 << endl;

    // 3. Function Overriding (Runtime Polymorphism)
    cout << "\n=== 3. FUNCTION OVERRIDING ===" << endl;

    // Create objects
    Rectangle rect(5, 3);
    Circle circle(4);
    Triangle triangle(6, 4, 3, 4, 5);

    // Array of base class pointers
    Shape *shapes[] = {&rect, &circle, &triangle};

    // Demonstrate runtime polymorphism
    processShapes(shapes, 3);

    // 4. Advanced Polymorphism with Animals
    cout << "\n=== 4. ADVANCED POLYMORPHISM ===" << endl;

    Dog dog;
    Bird bird;

    // Polymorphic behavior through base class pointers
    Animal *animals[] = {&dog, &bird};

    demonstratePolymorphism(animals[0], "dog food");
    demonstratePolymorphism(animals[1], "seeds");

    // Direct access to derived class specific methods
    cout << "\n--- Derived class specific behavior ---" << endl;
    dog.wagTail(); // Only available in Dog class

    // 5. Virtual Function Table Demonstration
    cout << "\n=== 5. VIRTUAL FUNCTION TABLE DEMO ===" << endl;

    Shape *shapePtr;

    Rectangle newRect(10, 5);
    shapePtr = &newRect;
    cout << "Rectangle through base pointer: ";
    shapePtr->calculateArea(); // Calls Rectangle's version

    Circle newCircle(3);
    shapePtr = &newCircle;
    cout << "Circle through base pointer: ";
    shapePtr->calculateArea(); // Calls Circle's version

    cout << "\n=== Program Ending ===" << endl;
    return 0;
}

/*
POLYMORPHISM SUMMARY:

1. COMPILE-TIME POLYMORPHISM:
   a) Function Overloading:
      - Same function name, different parameters
      - Resolved at compile time
      - Based on number, type, or order of parameters

   b) Operator Overloading:
      - Give new meanings to operators for user-defined types
      - Improves code readability and intuitiveness

2. RUNTIME POLYMORPHISM:
   a) Function Overriding:
      - Derived class provides specific implementation
      - Base class function must be virtual
      - Resolved at runtime using virtual function table

   b) Virtual Functions:
      - Enable runtime polymorphism
      - Late binding - function call resolved at runtime
      - Virtual function table (vtable) used for resolution

3. KEY CONCEPTS:

   VIRTUAL FUNCTIONS:
   - Declared with 'virtual' keyword in base class
   - Enable runtime polymorphism
   - Can be overridden in derived classes
   - Virtual destructor needed for proper cleanup

   PURE VIRTUAL FUNCTIONS:
   - virtual function = 0;
   - Makes class abstract (cannot be instantiated)
   - Must be implemented in derived classes

   EARLY vs LATE BINDING:
   - Early (Static): Compile-time resolution
   - Late (Dynamic): Runtime resolution using vtable

4. ADVANTAGES:
   - Code reusability
   - Flexibility and extensibility
   - Uniform interface for different implementations
   - Easy to add new types without changing existing code

5. RULES FOR OVERRIDING:
   - Function signature must match exactly
   - Base function must be virtual
   - Access level can be same or more accessible
   - Return type should be same or covariant

PRACTICE EXERCISES:

1. Create a Media Player system:
   - Base class: MediaPlayer with play(), pause(), stop()
   - Derived: AudioPlayer, VideoPlayer, StreamingPlayer
   - Demonstrate runtime polymorphism

2. Create a Banking System:
   - Base: Account with deposit(), withdraw(), getBalance()
   - Derived: SavingsAccount, CheckingAccount, CreditAccount
   - Different implementations for each account type

3. Mathematical Operations:
   - Overload operators for Matrix class
   - Addition, subtraction, multiplication
   - Comparison operators

4. Shape Calculator:
   - Abstract Shape base class
   - Multiple derived shapes with area/perimeter calculations
   - Factory pattern to create shapes dynamically
*/
