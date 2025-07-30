/*
==============================================
Exercise 5: This Pointer
==============================================

PROBLEM: Demonstrate the usage and importance of 'this' pointer

Show how 'this' pointer is used:
1. To resolve naming conflicts between parameters and member variables
2. To return reference to current object (method chaining)
3. To pass current object to other functions
4. To compare objects

Expected Output:
Name set to: John
Age set to: 25
Chaining: John is 25 years old and works in IT
Object addresses: Same object used in chaining
Self-assignment detected and avoided
*/

#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name;
    int age;
    string department;

public:
    // Constructor
    Person(string name = "", int age = 0, string department = "")
    {
        // Using 'this' pointer to resolve naming conflict
        this->name = name;
        this->age = age;
        this->department = department;
        cout << "Person created: " << this->name << endl;
    }

    // Method using 'this' to resolve parameter name conflict
    void setName(string name)
    {
        cout << "Setting name using 'this' pointer" << endl;
        this->name = name; // this->name refers to member variable
                           // name refers to parameter
        cout << "Name set to: " << this->name << endl;
    }

    void setAge(int age)
    {
        cout << "Setting age using 'this' pointer" << endl;
        this->age = age;
        cout << "Age set to: " << this->age << endl;
    }

    // Method chaining using 'this' pointer
    Person &setNameChain(string name)
    {
        this->name = name;
        return *this; // Return reference to current object
    }

    Person &setAgeChain(int age)
    {
        this->age = age;
        return *this; // Return reference to current object
    }

    Person &setDepartmentChain(string department)
    {
        this->department = department;
        return *this; // Return reference to current object
    }

    // Display method
    void display() const
    {
        cout << this->name << " is " << this->age
             << " years old and works in " << this->department << endl;
    }

    // Method to compare objects using 'this'
    bool isSameAs(const Person &other) const
    {
        return this == &other; // Compare addresses
    }

    // Assignment operator using 'this' for self-assignment check
    Person &operator=(const Person &other)
    {
        cout << "Assignment operator called" << endl;

        // Self-assignment check using 'this'
        if (this == &other)
        {
            cout << "Self-assignment detected and avoided" << endl;
            return *this;
        }

        // Copy data from other object
        this->name = other.name;
        this->age = other.age;
        this->department = other.department;

        cout << "Assignment completed" << endl;
        return *this; // Return reference to current object
    }

    // Method to print object address
    void printAddress() const
    {
        cout << "Object address: " << this << endl;
    }

    // Method that passes 'this' to another function
    void processPerson()
    {
        cout << "Processing person: " << this->name << endl;
        helperFunction(this); // Pass current object to helper
    }

private:
    // Helper function that receives object pointer
    void helperFunction(Person *person)
    {
        cout << "Helper function received person: " << person->name << endl;
        cout << "Object address in helper: " << person << endl;
    }
};

// Free function to demonstrate passing objects
void printPersonInfo(const Person &person)
{
    cout << "Free function - Person info: ";
    person.display();
}

// Class to demonstrate 'this' in different contexts
class Counter
{
private:
    int count;
    static int totalObjects;

public:
    Counter(int initialCount = 0)
    {
        this->count = initialCount;
        totalObjects++;
        cout << "Counter object created. Address: " << this << endl;
    }

    // Prefix increment returning reference
    Counter &operator++()
    {
        ++this->count;
        return *this; // Return reference for chaining
    }

    // Postfix increment returning copy
    Counter operator++(int)
    {
        Counter temp = *this; // Create copy of current object
        ++this->count;
        return temp; // Return copy (not reference)
    }

    // Method to add another counter to this one
    Counter &add(const Counter &other)
    {
        this->count += other.count;
        return *this;
    }

    // Method to demonstrate 'this' with static context
    static void printTotalObjects()
    {
        cout << "Total objects created: " << totalObjects << endl;
        // Note: 'this' cannot be used in static methods
        // cout << this->count;  // ERROR: 'this' not available in static context
    }

    void display() const
    {
        cout << "Count: " << this->count << " (Address: " << this << ")" << endl;
    }

    int getCount() const
    {
        return this->count;
    }
};

// Initialize static member
int Counter::totalObjects = 0;

int main()
{
    cout << "=== This Pointer Demonstration ===" << endl;

    // 1. Resolving naming conflicts
    cout << "\n--- Naming Conflict Resolution ---" << endl;
    Person person1;
    person1.setName("John");
    person1.setAge(25);

    // 2. Method chaining using 'this'
    cout << "\n--- Method Chaining ---" << endl;
    Person person2;
    person2.setNameChain("Alice")
        .setAgeChain(30)
        .setDepartmentChain("IT");

    cout << "Chaining result: ";
    person2.display();

    // Show that same object is used in chaining
    cout << "Object addresses in chaining:" << endl;
    person2.printAddress();

    // 3. Self-assignment demonstration
    cout << "\n--- Self-Assignment Check ---" << endl;
    person2 = person2; // Self-assignment

    // 4. Object comparison using 'this'
    cout << "\n--- Object Comparison ---" << endl;
    Person person3 = person2; // Copy constructor
    cout << "person2 same as person2: " << person2.isSameAs(person2) << endl;
    cout << "person2 same as person3: " << person2.isSameAs(person3) << endl;

    // 5. Passing 'this' to other functions
    cout << "\n--- Passing 'this' to Functions ---" << endl;
    person2.processPerson();

    // 6. Counter class demonstration
    cout << "\n--- Counter Class with 'this' ---" << endl;
    Counter c1(10);
    Counter c2(20);

    c1.display();
    c2.display();

    // Method chaining with operators
    cout << "After ++c1: ";
    (++c1).display();

    cout << "After c1.add(c2): ";
    c1.add(c2).display();

    Counter::printTotalObjects();

    // 7. Demonstrating copy vs reference return
    cout << "\n--- Copy vs Reference Return ---" << endl;
    Counter c3(5);
    Counter c4 = ++c3; // Prefix: returns reference
    Counter c5 = c3++; // Postfix: returns copy

    cout << "c3: ";
    c3.display();
    cout << "c4: ";
    c4.display();
    cout << "c5: ";
    c5.display();

    return 0;
}

/*
'THIS' POINTER KEY CONCEPTS:

1. WHAT IS 'THIS':
   - Implicit pointer available in non-static member functions
   - Points to the object that called the member function
   - Type: ClassName* const (constant pointer)

2. WHEN TO USE 'THIS':
   - Resolve naming conflicts between parameters and members
   - Method chaining (return *this)
   - Self-assignment check in operators
   - Pass current object to other functions

3. IMPORTANT NOTES:
   - 'this' is not available in static member functions
   - 'this' is a const pointer (address cannot be changed)
   - 'this' cannot be assigned to
   - 'this' is implicitly used even when not written

4. METHOD CHAINING:
   - Return *this from methods to enable chaining
   - Allows obj.method1().method2().method3()

5. SELF-ASSIGNMENT:
   - Check if (this == &other) in assignment operator
   - Prevents issues with self-assignment

PRACTICE EXERCISES:

1. Create a String class with:
   - Methods that use 'this' for parameter name conflicts
   - Method chaining for string operations
   - Assignment operator with self-assignment check

2. Create a Calculator class:
   - Methods: add(), subtract(), multiply(), divide()
   - Use method chaining: calc.add(5).multiply(2).subtract(3)
   - Each method returns *this

3. Create a Student class:
   - Method to compare grades with another student
   - Method to copy data from another student (avoiding self-copy)
   - Display method showing object address using 'this'
*/
