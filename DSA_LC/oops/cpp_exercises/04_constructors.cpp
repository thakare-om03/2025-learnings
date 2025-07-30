/*
==============================================
Exercise 4: Constructors
==============================================

PROBLEM: Demonstrate all types of constructors

Create classes that showcase:
1. Default Constructor (non-parameterized)
2. Parameterized Constructor
3. Copy Constructor
4. Constructor Overloading

Expected Output:
Default constructor called
Parameterized constructor called
Copy constructor called
Constructor with 2 parameters called
Constructor with 3 parameters called
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Student
{
private:
    string name;
    int rollNumber;
    double marks;
    string course;

public:
    // 1. DEFAULT CONSTRUCTOR (Non-parameterized)
    Student()
    {
        cout << "Default constructor called" << endl;
        name = "Unknown";
        rollNumber = 0;
        marks = 0.0;
        course = "Not Assigned";
    }

    // 2. PARAMETERIZED CONSTRUCTOR (with all parameters)
    Student(string n, int roll, double m, string c)
    {
        cout << "Parameterized constructor (4 params) called" << endl;
        name = n;
        rollNumber = roll;
        marks = m;
        course = c;
    }

    // 3. CONSTRUCTOR OVERLOADING (different number of parameters)
    Student(string n, int roll)
    {
        cout << "Constructor with 2 parameters called" << endl;
        name = n;
        rollNumber = roll;
        marks = 0.0;
        course = "Not Assigned";
    }

    Student(string n, int roll, double m)
    {
        cout << "Constructor with 3 parameters called" << endl;
        name = n;
        rollNumber = roll;
        marks = m;
        course = "Not Assigned";
    }

    // 4. COPY CONSTRUCTOR
    Student(const Student &other)
    {
        cout << "Copy constructor called" << endl;
        name = other.name;
        rollNumber = other.rollNumber;
        marks = other.marks;
        course = other.course;
    }

    // Display method
    void display() const
    {
        cout << "Name: " << name << ", Roll: " << rollNumber
             << ", Marks: " << marks << ", Course: " << course << endl;
    }

    // Destructor
    ~Student()
    {
        cout << "Destructor called for " << name << endl;
    }
};

// Example with dynamic memory allocation to show deep copy
class DynamicArray
{
private:
    int *arr;
    int size;

public:
    // Default constructor
    DynamicArray()
    {
        cout << "Default constructor called for DynamicArray" << endl;
        size = 5;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = i + 1;
        }
    }

    // Parameterized constructor
    DynamicArray(int s)
    {
        cout << "Parameterized constructor called for DynamicArray" << endl;
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = (i + 1) * 10;
        }
    }

    // Copy constructor (Deep copy)
    DynamicArray(const DynamicArray &other)
    {
        cout << "Copy constructor called for DynamicArray (Deep Copy)" << endl;
        size = other.size;
        arr = new int[size]; // Allocate new memory

        // Copy elements
        for (int i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }
    }

    // Method to modify array
    void setValue(int index, int value)
    {
        if (index >= 0 && index < size)
        {
            arr[index] = value;
        }
    }

    // Display method
    void display() const
    {
        cout << "Array: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor
    ~DynamicArray()
    {
        cout << "Destructor called for DynamicArray" << endl;
        delete[] arr;
    }
};

// Class to demonstrate constructor delegation (C++11 feature)
class Rectangle
{
private:
    double length;
    double width;
    string color;

public:
    // Main constructor
    Rectangle(double l, double w, string c)
    {
        cout << "Main constructor called" << endl;
        length = l;
        width = w;
        color = c;
    }

    // Delegating constructors
    Rectangle(double l, double w) : Rectangle(l, w, "White")
    {
        cout << "Delegating constructor (2 params) called" << endl;
    }

    Rectangle() : Rectangle(1.0, 1.0, "White")
    {
        cout << "Delegating constructor (default) called" << endl;
    }

    void display() const
    {
        cout << "Rectangle: " << length << "x" << width
             << ", Color: " << color << endl;
    }
};

int main()
{
    cout << "=== Constructor Types Demonstration ===" << endl;

    // 1. Default Constructor
    cout << "\n--- Default Constructor ---" << endl;
    Student s1;
    s1.display();

    // 2. Parameterized Constructor
    cout << "\n--- Parameterized Constructor ---" << endl;
    Student s2("Alice", 101, 85.5, "Computer Science");
    s2.display();

    // 3. Constructor Overloading
    cout << "\n--- Constructor Overloading ---" << endl;
    Student s3("Bob", 102);
    s3.display();

    Student s4("Charlie", 103, 78.5);
    s4.display();

    // 4. Copy Constructor
    cout << "\n--- Copy Constructor ---" << endl;
    Student s5 = s2; // Copy constructor called
    s5.display();

    Student s6(s2); // Another way to call copy constructor
    s6.display();

    // Dynamic Array Example
    cout << "\n--- Dynamic Array Example ---" << endl;
    DynamicArray arr1;
    arr1.display();

    DynamicArray arr2(3);
    arr2.display();

    // Copy constructor with deep copy
    DynamicArray arr3 = arr2;
    arr3.display();

    // Modify original to show deep copy worked
    arr2.setValue(0, 999);
    cout << "After modifying arr2:" << endl;
    cout << "arr2: ";
    arr2.display();
    cout << "arr3: ";
    arr3.display();

    // Constructor Delegation Example
    cout << "\n--- Constructor Delegation ---" << endl;
    Rectangle r1;
    r1.display();

    Rectangle r2(5.0, 3.0);
    r2.display();

    Rectangle r3(7.0, 4.0, "Blue");
    r3.display();

    return 0;
}

/*
CONSTRUCTOR TYPES EXPLAINED:

1. DEFAULT CONSTRUCTOR:
   - No parameters
   - Called when object is created without arguments
   - If not defined, compiler provides one

2. PARAMETERIZED CONSTRUCTOR:
   - Takes parameters to initialize object
   - Allows different ways to create objects

3. COPY CONSTRUCTOR:
   - Creates object as copy of another object
   - Format: ClassName(const ClassName& other)
   - Used for deep copy with dynamic memory

4. CONSTRUCTOR OVERLOADING:
   - Multiple constructors with different parameters
   - Provides flexibility in object creation

5. CONSTRUCTOR DELEGATION (C++11):
   - One constructor calls another
   - Reduces code duplication

IMPORTANT NOTES:
- If you define any constructor, compiler won't provide default constructor
- Copy constructor is called when:
  - Object is initialized with another object
  - Object is passed by value to function
  - Object is returned by value from function

PRACTICE EXERCISES:

1. Create a Book class with:
   - Default constructor
   - Constructor with title only
   - Constructor with title and author
   - Constructor with all details (title, author, price, pages)
   - Copy constructor

2. Create a Matrix class with dynamic 2D array:
   - Parameterized constructor (rows, cols)
   - Copy constructor with deep copy
   - Methods to set/get values

3. Create a Date class with:
   - Default constructor (current date)
   - Constructor with day, month, year
   - Constructor with month and year (day = 1)
   - Validation in constructors
*/
