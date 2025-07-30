/*
==============================================
Exercise 7: Destructor
==============================================

PROBLEM: Demonstrate destructor usage and memory management

Show:
1. Automatic destructor calls
2. Memory management with dynamic allocation
3. Destructor call order
4. Importance of virtual destructors in inheritance

Expected Output:
Constructors and destructors called in proper order
Memory allocated and deallocated properly
No memory leaks demonstrated
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Simple class to demonstrate basic destructor
class SimpleStudent
{
private:
    string name;
    int rollNumber;

public:
    SimpleStudent(string n, int roll)
    {
        name = n;
        rollNumber = roll;
        cout << "SimpleStudent constructor: " << name << " created" << endl;
    }

    // Destructor
    ~SimpleStudent()
    {
        cout << "SimpleStudent destructor: " << name << " destroyed" << endl;
    }

    void display()
    {
        cout << "Student: " << name << ", Roll: " << rollNumber << endl;
    }
};

// Class with dynamic memory - demonstrates memory management
class DynamicArray
{
private:
    int *data;
    int size;
    string arrayName;

public:
    DynamicArray(string name, int s)
    {
        arrayName = name;
        size = s;
        data = new int[size]; // Dynamic memory allocation

        // Initialize array
        for (int i = 0; i < size; i++)
        {
            data[i] = i * 10;
        }

        cout << "DynamicArray constructor: " << arrayName
             << " created with size " << size << endl;
        cout << "Memory allocated at address: " << data << endl;
    }

    // Copy constructor (deep copy)
    DynamicArray(const DynamicArray &other)
    {
        arrayName = other.arrayName + "_copy";
        size = other.size;
        data = new int[size]; // Allocate new memory

        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }

        cout << "DynamicArray copy constructor: " << arrayName << " created" << endl;
    }

    // Destructor - CRITICAL for memory management
    ~DynamicArray()
    {
        cout << "DynamicArray destructor: " << arrayName << " being destroyed" << endl;
        cout << "Freeing memory at address: " << data << endl;
        delete[] data; // Free dynamically allocated memory
        cout << "Memory freed for " << arrayName << endl;
    }

    void display()
    {
        cout << arrayName << ": ";
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void setValue(int index, int value)
    {
        if (index >= 0 && index < size)
        {
            data[index] = value;
        }
    }
};

// Class to demonstrate constructor/destructor order
class Component
{
private:
    string componentName;
    int componentId;

public:
    Component(string name, int id)
    {
        componentName = name;
        componentId = id;
        cout << "  Component constructor: " << componentName << " (ID: " << componentId << ")" << endl;
    }

    ~Component()
    {
        cout << "  Component destructor: " << componentName << " (ID: " << componentId << ")" << endl;
    }

    void operate()
    {
        cout << "  " << componentName << " is operating" << endl;
    }
};

class ComplexSystem
{
private:
    Component comp1;
    Component comp2;
    DynamicArray *dynamicData;
    string systemName;

public:
    ComplexSystem(string name) : comp1("Engine", 1), // Member initialization list
                                 comp2("Transmission", 2),
                                 systemName(name)
    {

        cout << "ComplexSystem constructor: " << systemName << " starting" << endl;

        // Dynamic allocation
        dynamicData = new DynamicArray("SystemData", 3);

        cout << "ComplexSystem constructor: " << systemName << " completed" << endl;
    }

    ~ComplexSystem()
    {
        cout << "ComplexSystem destructor: " << systemName << " starting cleanup" << endl;

        // Clean up dynamic memory
        delete dynamicData;

        cout << "ComplexSystem destructor: " << systemName << " completed" << endl;
        // Note: comp1 and comp2 destructors will be called automatically
        // in reverse order of construction
    }

    void operate()
    {
        cout << "System " << systemName << " operating:" << endl;
        comp1.operate();
        comp2.operate();
        dynamicData->display();
    }
};

// Base class for virtual destructor demonstration
class Base
{
protected:
    string baseName;
    int *baseData;

public:
    Base(string name)
    {
        baseName = name;
        baseData = new int[5];
        for (int i = 0; i < 5; i++)
        {
            baseData[i] = i;
        }
        cout << "Base constructor: " << baseName << endl;
    }

    // Virtual destructor - IMPORTANT for proper cleanup
    virtual ~Base()
    {
        cout << "Base destructor: " << baseName << endl;
        delete[] baseData;
    }

    virtual void display()
    {
        cout << "Base: " << baseName << endl;
    }
};

class Derived : public Base
{
private:
    string derivedName;
    double *derivedData;

public:
    Derived(string bName, string dName) : Base(bName)
    {
        derivedName = dName;
        derivedData = new double[3];
        for (int i = 0; i < 3; i++)
        {
            derivedData[i] = i * 1.5;
        }
        cout << "Derived constructor: " << derivedName << endl;
    }

    // Destructor will be virtual due to base class virtual destructor
    ~Derived()
    {
        cout << "Derived destructor: " << derivedName << endl;
        delete[] derivedData;
    }

    void display() override
    {
        cout << "Derived: " << baseName << " - " << derivedName << endl;
    }
};

// Function to demonstrate automatic destructor calls
void demonstrateAutomaticDestruction()
{
    cout << "\n=== Automatic Destruction Demo ===" << endl;
    cout << "Creating objects in function scope..." << endl;

    SimpleStudent s1("Alice", 101);
    SimpleStudent s2("Bob", 102);

    s1.display();
    s2.display();

    cout << "Function ending - objects will be destroyed automatically..." << endl;
    // Destructors called automatically when function ends
    // Order: s2 destroyed first (last created, first destroyed)
}

// Function to demonstrate memory leak (what NOT to do)
void demonstrateMemoryLeak()
{
    cout << "\n=== Memory Leak Demo (What NOT to do) ===" << endl;

    DynamicArray *arr = new DynamicArray("LeakyArray", 4);
    arr->display();

    // MEMORY LEAK: We allocated with 'new' but never called 'delete'
    // The object's destructor won't be called automatically
    // This would cause memory leak in real program

    cout << "WARNING: Memory leak created! Destructor not called for LeakyArray" << endl;
    cout << "In real program, you must call: delete arr;" << endl;

    // Proper cleanup:
    delete arr; // This calls the destructor
}

int main()
{
    cout << "=== Destructor Demonstration ===" << endl;

    // 1. Basic destructor demonstration
    demonstrateAutomaticDestruction();

    // 2. Memory management with destructors
    cout << "\n=== Memory Management Demo ===" << endl;
    {
        cout << "Creating DynamicArray in block scope..." << endl;
        DynamicArray arr1("BlockArray", 5);
        arr1.display();

        // Copy to demonstrate deep copy destructors
        DynamicArray arr2 = arr1;
        arr2.setValue(0, 999);
        arr2.display();

        cout << "Block ending - destructors will be called..." << endl;
    } // Both arr1 and arr2 destructors called here

    // 3. Complex object destruction order
    cout << "\n=== Complex Object Destruction Order ===" << endl;
    {
        cout << "Creating ComplexSystem..." << endl;
        ComplexSystem system("MainSystem");
        system.operate();
        cout << "Block ending - complex destruction begins..." << endl;
    } // ComplexSystem destructor called here

    // 4. Virtual destructor demonstration
    cout << "\n=== Virtual Destructor Demo ===" << endl;
    {
        cout << "Creating objects through base pointer..." << endl;
        Base *basePtr = new Derived("BaseObj", "DerivedObj");
        basePtr->display();

        cout << "Deleting through base pointer..." << endl;
        delete basePtr; // Virtual destructor ensures proper cleanup

        // Without virtual destructor, only Base destructor would be called
        // This would cause memory leak in Derived class
    }

    // 5. Array of objects destruction
    cout << "\n=== Array Destruction Demo ===" << endl;
    {
        cout << "Creating array of objects..." << endl;
        SimpleStudent students[] = {
            SimpleStudent("John", 1),
            SimpleStudent("Jane", 2),
            SimpleStudent("Jack", 3)};

        for (int i = 0; i < 3; i++)
        {
            students[i].display();
        }

        cout << "Array going out of scope..." << endl;
    } // Destructors called for all array elements in reverse order

    // 6. Memory leak demonstration
    demonstrateMemoryLeak();

    cout << "\n=== Program Ending ===" << endl;
    return 0;
}

/*
DESTRUCTOR KEY CONCEPTS:

1. AUTOMATIC CALLS:
   - Called automatically when object goes out of scope
   - Called when 'delete' is used on dynamically allocated object
   - Called in reverse order of construction

2. MEMORY MANAGEMENT:
   - Critical for cleaning up dynamic memory (new/delete)
   - Prevents memory leaks
   - Should free all resources acquired by object

3. VIRTUAL DESTRUCTORS:
   - Required when using inheritance with polymorphism
   - Ensures derived class destructor is called
   - Always make base class destructor virtual if class has virtual functions

4. DESTRUCTOR RULES:
   - No parameters, no return type
   - Cannot be overloaded (only one destructor per class)
   - If not provided, compiler generates default destructor
   - Should not throw exceptions

5. CALL ORDER:
   - Local objects: reverse order of creation
   - Member objects: reverse order of construction
   - Inheritance: derived first, then base

COMMON MISTAKES:

1. Not implementing destructor for classes with dynamic memory
2. Not making destructor virtual in base classes
3. Calling delete on same memory multiple times
4. Throwing exceptions from destructor
5. Accessing object members after destruction

PRACTICE EXERCISES:

1. Create a FileManager class:
   - Opens file in constructor
   - Closes file in destructor
   - Demonstrate proper resource cleanup

2. Create a LinkedList class:
   - Dynamic node allocation
   - Destructor should free all nodes
   - Prevent memory leaks

3. Create inheritance hierarchy:
   - Base class with virtual destructor
   - Derived classes with their own resources
   - Test proper cleanup through base pointer

4. Create a SmartPointer class:
   - Manages memory automatically
   - Destructor deletes managed object
   - Reference counting (advanced)
*/
