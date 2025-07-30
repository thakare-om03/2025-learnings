/*
==============================================
Exercise 12: Static Keyword
==============================================

PROBLEM: Demonstrate static variables and static member functions

Show:
1. Static member variables
2. Static member functions
3. Static local variables
4. Static global variables
5. Static initialization and destruction order

Expected Output:
Static variables shared among all objects
Static functions accessible without objects
Proper initialization and cleanup of static members
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ==============================================
// 1. STATIC MEMBER VARIABLES
// ==============================================
class Student
{
private:
    string name;
    int rollNumber;
    double marks;

    // Static member variables (shared by all objects)
    static int totalStudents;     // Count of students
    static double totalMarks;     // Sum of all marks
    static string schoolName;     // Common school name
    static const int maxStudents; // Constant static member

public:
    Student(string n, int roll, double m)
    {
        name = n;
        rollNumber = roll;
        marks = m;

        // Update static variables
        totalStudents++;
        totalMarks += marks;

        cout << "Student created: " << name << " (Total students: " << totalStudents << ")" << endl;
    }

    // Copy constructor - also affects static variables
    Student(const Student &other)
    {
        name = other.name + "_copy";
        rollNumber = other.rollNumber;
        marks = other.marks;

        totalStudents++;
        totalMarks += marks;

        cout << "Student copied: " << name << " (Total students: " << totalStudents << ")" << endl;
    }

    // Destructor - updates static variables
    ~Student()
    {
        totalStudents--;
        totalMarks -= marks;
        cout << "Student destroyed: " << name << " (Remaining students: " << totalStudents << ")" << endl;
    }

    // Regular member function accessing static variables
    void displayInfo() const
    {
        cout << "Name: " << name << ", Roll: " << rollNumber << ", Marks: " << marks << endl;
        cout << "School: " << schoolName << ", Total Students: " << totalStudents << endl;
    }

    // Static member functions
    static int getTotalStudents()
    {
        // Static functions can only access static members
        return totalStudents;
    }

    static double getAverageMarks()
    {
        if (totalStudents == 0)
            return 0;
        return totalMarks / totalStudents;
    }

    static void setSchoolName(const string &school)
    {
        schoolName = school;
    }

    static string getSchoolName()
    {
        return schoolName;
    }

    static void displayStatistics()
    {
        cout << "\n=== School Statistics ===" << endl;
        cout << "School Name: " << schoolName << endl;
        cout << "Total Students: " << totalStudents << endl;
        cout << "Total Marks: " << totalMarks << endl;
        cout << "Average Marks: " << getAverageMarks() << endl;
        cout << "Max Students Allowed: " << maxStudents << endl;

        // Static function cannot access non-static members directly
        // cout << name;  // ERROR: non-static member
        // displayInfo(); // ERROR: non-static member function
    }

    // Static function to create students with validation
    static Student *createStudent(const string &name, int roll, double marks)
    {
        if (totalStudents >= maxStudents)
        {
            cout << "Cannot create student: Maximum capacity reached!" << endl;
            return nullptr;
        }

        if (marks < 0 || marks > 100)
        {
            cout << "Cannot create student: Invalid marks!" << endl;
            return nullptr;
        }

        return new Student(name, roll, marks);
    }
};

// Static member variable definitions (MUST be defined outside class)
int Student::totalStudents = 0;
double Student::totalMarks = 0.0;
string Student::schoolName = "Default School";
const int Student::maxStudents = 1000;

// ==============================================
// 2. STATIC LOCAL VARIABLES
// ==============================================
class Counter
{
public:
    static int getNextId()
    {
        // Static local variable - initialized only once
        static int nextId = 1000; // Initialized only on first call

        cout << "Getting next ID (current static value: " << nextId << ")" << endl;
        return nextId++;
    }

    static void demonstrateStaticLocal()
    {
        // Static array - retains values between function calls
        static int callHistory[10] = {0}; // Initialized to all zeros once
        static int callCount = 0;

        if (callCount < 10)
        {
            callHistory[callCount] = getNextId();
            callCount++;
        }

        cout << "Call history: ";
        for (int i = 0; i < callCount; i++)
        {
            cout << callHistory[i] << " ";
        }
        cout << endl;
    }
};

// ==============================================
// 3. SINGLETON PATTERN USING STATIC
// ==============================================
class Logger
{
private:
    string logFile;
    int logLevel;

    // Private constructor for Singleton pattern
    Logger(const string &file) : logFile(file), logLevel(1)
    {
        cout << "Logger instance created with file: " << file << endl;
    }

    // Prevent copying
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;

public:
    // Static function to get single instance
    static Logger &getInstance()
    {
        // Static local object - created only once
        static Logger instance("application.log");
        return instance;
    }

    void log(const string &message, int level = 1)
    {
        if (level >= logLevel)
        {
            cout << "[LOG] " << message << " (to " << logFile << ")" << endl;
        }
    }

    void setLogLevel(int level)
    {
        logLevel = level;
        cout << "Log level set to: " << level << endl;
    }

    static void logMessage(const string &message)
    {
        // Static function using singleton instance
        getInstance().log(message);
    }
};

// ==============================================
// 4. STATIC INITIALIZATION ORDER
// ==============================================
class InitializationDemo
{
private:
    static int staticVar1;
    static int staticVar2;
    static int staticVar3;

public:
    static void displayValues()
    {
        cout << "staticVar1: " << staticVar1 << endl;
        cout << "staticVar2: " << staticVar2 << endl;
        cout << "staticVar3: " << staticVar3 << endl;
    }

    static int initializeVar2()
    {
        cout << "Initializing staticVar2 with function call" << endl;
        return 200;
    }
};

// Static initialization with different methods
int InitializationDemo::staticVar1 = 100;                                  // Direct initialization
int InitializationDemo::staticVar2 = InitializationDemo::initializeVar2(); // Function call
int InitializationDemo::staticVar3 = staticVar1 + 50;                      // Using other static variable

// ==============================================
// 5. STATIC CONSTANTS AND UTILITIES
// ==============================================
class MathUtils
{
public:
    // Static constants
    static const double PI;
    static const double E;
    static constexpr int MAX_ITERATIONS = 1000; // Compile-time constant

    // Static utility functions
    static double circleArea(double radius)
    {
        return PI * radius * radius;
    }

    static double circleCircumference(double radius)
    {
        return 2 * PI * radius;
    }

    static long factorial(int n)
    {
        // Static variable to cache results
        static vector<long> cache = {1}; // cache[0] = 0! = 1

        // Extend cache if needed
        while (cache.size() <= n)
        {
            cache.push_back(cache.back() * cache.size());
        }

        return cache[n];
    }

    static void displayCache()
    {
        cout << "Factorial cache contains " << factorial(0) << " values" << endl;
    }
};

// Static constant definitions
const double MathUtils::PI = 3.14159265359;
const double MathUtils::E = 2.71828182846;

// ==============================================
// 6. STATIC MEMBER FUNCTION OVERLOADING
// ==============================================
class Calculator
{
public:
    // Static function overloading
    static int add(int a, int b)
    {
        cout << "Adding integers: ";
        return a + b;
    }

    static double add(double a, double b)
    {
        cout << "Adding doubles: ";
        return a + b;
    }

    static string add(const string &a, const string &b)
    {
        cout << "Concatenating strings: ";
        return a + b;
    }

    // Static template function
    template <typename T>
    static T multiply(T a, T b)
    {
        cout << "Multiplying (template): ";
        return a * b;
    }
};

// ==============================================
// DEMONSTRATION FUNCTIONS
// ==============================================
void demonstrateStaticMembers()
{
    cout << "\n=== STATIC MEMBER VARIABLES AND FUNCTIONS ===" << endl;

    // Access static members without creating objects
    cout << "Initial total students: " << Student::getTotalStudents() << endl;
    Student::setSchoolName("MIT University");
    cout << "School name: " << Student::getSchoolName() << endl;

    // Create objects and see static variables change
    Student s1("Alice", 101, 85.5);
    Student s2("Bob", 102, 78.0);
    Student s3("Charlie", 103, 92.0);

    // Display statistics
    Student::displayStatistics();

    // Create a copy and see static variables update
    {
        Student s4 = s1; // Copy constructor called
        cout << "After creating copy:" << endl;
        Student::displayStatistics();
    } // s4 destructor called here

    cout << "After copy destructor:" << endl;
    Student::displayStatistics();

    // Use static factory function
    Student *s5 = Student::createStudent("Diana", 104, 88.5);
    if (s5)
    {
        s5->displayInfo();
        delete s5;
    }
}

void demonstrateStaticLocal()
{
    cout << "\n=== STATIC LOCAL VARIABLES ===" << endl;

    cout << "First call to getNextId(): " << Counter::getNextId() << endl;
    cout << "Second call to getNextId(): " << Counter::getNextId() << endl;
    cout << "Third call to getNextId(): " << Counter::getNextId() << endl;

    cout << "\nDemonstrating static local array:" << endl;
    Counter::demonstrateStaticLocal();
    Counter::demonstrateStaticLocal();
    Counter::demonstrateStaticLocal();
}

void demonstrateSingleton()
{
    cout << "\n=== SINGLETON PATTERN WITH STATIC ===" << endl;

    // Get singleton instance
    Logger &logger1 = Logger::getInstance();
    Logger &logger2 = Logger::getInstance();

    // Verify they're the same instance
    cout << "logger1 address: " << &logger1 << endl;
    cout << "logger2 address: " << &logger2 << endl;
    cout << "Same instance: " << (&logger1 == &logger2) << endl;

    // Use the logger
    logger1.log("First message");
    logger2.log("Second message");
    logger1.setLogLevel(2);
    logger2.log("Low level message", 1);  // Won't be logged
    logger2.log("High level message", 2); // Will be logged

    // Use static convenience function
    Logger::logMessage("Message through static function");
}

void demonstrateStaticUtilities()
{
    cout << "\n=== STATIC UTILITIES ===" << endl;

    // Math utilities
    cout << "PI: " << MathUtils::PI << endl;
    cout << "E: " << MathUtils::E << endl;
    cout << "Circle area (radius=5): " << MathUtils::circleArea(5) << endl;
    cout << "Circle circumference (radius=5): " << MathUtils::circleCircumference(5) << endl;

    // Cached factorial calculation
    cout << "5! = " << MathUtils::factorial(5) << endl;
    cout << "7! = " << MathUtils::factorial(7) << endl;
    cout << "3! = " << MathUtils::factorial(3) << endl; // Should use cached value

    // Calculator static functions
    cout << Calculator::add(5, 3) << endl;
    cout << Calculator::add(2.5, 3.7) << endl;
    cout << Calculator::add(string("Hello"), string("World")) << endl;
    cout << Calculator::multiply(4, 5) << endl;
    cout << Calculator::multiply(2.5, 4.0) << endl;
}

int main()
{
    cout << "=== STATIC KEYWORD DEMONSTRATION ===" << endl;

    // Show static initialization order
    cout << "\n=== STATIC INITIALIZATION ===" << endl;
    InitializationDemo::displayValues();

    // Demonstrate different aspects of static keyword
    demonstrateStaticMembers();
    demonstrateStaticLocal();
    demonstrateSingleton();
    demonstrateStaticUtilities();

    cout << "\n=== Program Ending ===" << endl;
    cout << "Final student count: " << Student::getTotalStudents() << endl;

    return 0;
}

/*
STATIC KEYWORD SUMMARY:

1. STATIC MEMBER VARIABLES:
   - Shared by all objects of the class
   - Only one copy exists regardless of number of objects
   - Must be defined outside the class (except constexpr)
   - Initialized before main() function
   - Lifetime: Entire program duration

2. STATIC MEMBER FUNCTIONS:
   - Can be called without creating class objects
   - Cannot access non-static members directly
   - Cannot use 'this' pointer
   - Cannot be virtual
   - Useful for utility functions and factory methods

3. STATIC LOCAL VARIABLES:
   - Declared inside functions
   - Initialized only once (first time function is called)
   - Retain values between function calls
   - Useful for caching and maintaining state

4. STATIC GLOBAL VARIABLES:
   - Limited to file scope (internal linkage)
   - Not accessible from other files
   - Alternative to global variables with better encapsulation

5. MEMORY ASPECTS:
   - Static variables stored in data segment (not stack/heap)
   - Initialized before main() execution
   - Destroyed after main() completion
   - Zero-initialized by default if not explicitly initialized

6. USE CASES:

   COUNTERS AND STATISTICS:
   - Count objects created
   - Track usage statistics
   - Maintain global state

   UTILITY FUNCTIONS:
   - Mathematical calculations
   - String operations
   - Factory methods

   SINGLETON PATTERN:
   - Ensure single instance
   - Global access point
   - Lazy initialization

   CACHING:
   - Store computed results
   - Avoid repeated calculations
   - Performance optimization

7. INITIALIZATION ORDER:
   - Static variables initialized in order of definition within file
   - Order undefined across different files
   - Use initialization on first use for complex dependencies

8. BEST PRACTICES:
   - Use static for truly shared data
   - Prefer static local variables over global static
   - Initialize static members explicitly
   - Consider thread safety in multi-threaded applications
   - Use const/constexpr for static constants

9. COMMON MISTAKES:
   - Forgetting to define static member variables outside class
   - Trying to access non-static members from static functions
   - Relying on initialization order across files
   - Not considering thread safety
   - Overusing static variables

10. ALTERNATIVES:
    - Namespaces for utility functions
    - Dependency injection instead of singletons
    - Member variables instead of static when appropriate

PRACTICE EXERCISES:

1. Create a BankAccount class:
   - Static variable to track total money in all accounts
   - Static function to get bank statistics
   - Static interest rate shared by all accounts

2. Create a IDGenerator class:
   - Static function to generate unique IDs
   - Different ID sequences for different types
   - Thread-safe ID generation

3. Create a Configuration class:
   - Static variables for application settings
   - Static functions to load/save configuration
   - Singleton pattern for global access

4. Create a MemoryPool class:
   - Static memory pool for object allocation
   - Static functions for memory management
   - Track allocation statistics
*/
