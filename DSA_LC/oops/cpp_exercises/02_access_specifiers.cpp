/*
==============================================
Exercise 2: Access Specifiers
==============================================

PROBLEM: Demonstrate the usage of private, public, and protected access specifiers

Create a base class Person with:
- private: ssn (social security number)
- protected: age
- public: name, display methods

Create a derived class Employee that inherits from Person:
- Show how protected members can be accessed in derived class
- Show how private members cannot be accessed directly

Expected Output:
Person Details:
Name: John Doe
Age: Cannot be accessed directly from outside
Employee Details:
Name: Jane Smith
Age: 28 (accessed through derived class)
Department: IT
*/

#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string ssn; // Private: Can only be accessed within this class

protected:
    int age; // Protected: Can be accessed by derived classes

public:
    string name; // Public: Can be accessed from anywhere

    // Constructor
    Person(string n, int a, string s)
    {
        name = n;
        age = a;
        ssn = s;
    }

    // Public method to access private member
    void setSSN(string s)
    {
        ssn = s;
    }

    // Public method - can be called from outside
    void displayPersonInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "SSN: " << ssn << endl;
    }

    // Protected method - can be accessed by derived classes
protected:
    void displayAge()
    {
        cout << "Age (from protected method): " << age << endl;
    }
};

class Employee : public Person
{
private:
    string department;
    double salary;

public:
    Employee(string n, int a, string s, string dept, double sal)
        : Person(n, a, s)
    {
        department = dept;
        salary = sal;
    }

    void displayEmployeeInfo()
    {
        cout << "=== Employee Information ===" << endl;
        cout << "Name: " << name << endl; // Public member - accessible
        cout << "Age: " << age << endl;   // Protected member - accessible in derived class
        cout << "Department: " << department << endl;

        // We can call protected method from base class
        displayAge();

        // Cannot access private member directly
        // cout << ssn;  // This would cause compilation error
    }

    // Method to demonstrate access levels
    void demonstrateAccess()
    {
        cout << "\n=== Access Demonstration ===" << endl;

        // ✓ Can access public members
        cout << "Public member (name): " << name << endl;

        // ✓ Can access protected members in derived class
        cout << "Protected member (age): " << age << endl;

        // ✗ Cannot access private members directly
        // cout << "Private member (ssn): " << ssn << endl;  // ERROR!

        cout << "Private member (ssn): Cannot be accessed directly!" << endl;
    }
};

int main()
{
    cout << "=== Access Specifiers Demonstration ===" << endl;

    // Creating Person object
    Person person("John Doe", 30, "123-45-6789");

    cout << "\n--- Person Object ---" << endl;
    // ✓ Can access public members
    cout << "Name (public): " << person.name << endl;

    // ✗ Cannot access protected or private members directly
    // cout << person.age;    // ERROR: protected member
    // cout << person.ssn;    // ERROR: private member

    person.displayPersonInfo(); // Public method can access all members

    // Creating Employee object
    Employee emp("Jane Smith", 28, "987-65-4321", "IT", 75000);

    cout << "\n--- Employee Object ---" << endl;
    emp.displayEmployeeInfo();
    emp.demonstrateAccess();

    // Demonstrating external access
    cout << "\n--- External Access Test ---" << endl;
    cout << "Employee name (public): " << emp.name << endl;
    // cout << emp.age;         // ERROR: protected member
    // cout << emp.department;  // ERROR: private member

    return 0;
}

/*
KEY POINTS TO REMEMBER:

1. PRIVATE:
   - Accessible only within the same class
   - Not accessible in derived classes
   - Not accessible from outside the class

2. PROTECTED:
   - Accessible within the same class
   - Accessible in derived classes
   - Not accessible from outside the class

3. PUBLIC:
   - Accessible from anywhere
   - No restrictions

PRACTICE EXERCISES:

1. Create a Vehicle class with private engineNumber, protected speed, and public brand
   Create a Car class that inherits Vehicle and demonstrate access

2. Create a BankAccount class with appropriate access specifiers:
   - Private: accountNumber, balance
   - Protected: interestRate
   - Public: customerName, deposit(), withdraw()

3. Modify the access specifiers and observe compilation errors
*/
