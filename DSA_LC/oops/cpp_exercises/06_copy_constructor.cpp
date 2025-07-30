/*
==============================================
Exercise 6: Copy Constructor - Shallow vs Deep Copy
==============================================

PROBLEM: Demonstrate the difference between shallow copy and deep copy

Show:
1. Default copy constructor behavior (shallow copy)
2. Problems with shallow copy when dealing with dynamic memory
3. Implementation of deep copy constructor
4. When to use deep copy vs shallow copy

Expected Output:
Shallow copy problem demonstrated
Deep copy solution implemented
Memory properly managed
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// Class to demonstrate SHALLOW COPY problems
class ShallowCopyDemo
{
private:
    char *name;
    int *grades;
    int numGrades;

public:
    // Constructor
    ShallowCopyDemo(const char *n, int num)
    {
        cout << "Constructor called" << endl;

        // Allocate memory for name
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        // Allocate memory for grades
        numGrades = num;
        grades = new int[numGrades];

        // Initialize grades
        for (int i = 0; i < numGrades; i++)
        {
            grades[i] = 50 + i * 10; // 50, 60, 70, etc.
        }

        cout << "Memory allocated for: " << name << endl;
        cout << "Name address: " << (void *)name << endl;
        cout << "Grades address: " << (void *)grades << endl;
    }

    // Default copy constructor (compiler generated - SHALLOW COPY)
    // This would cause problems!
    // ShallowCopyDemo(const ShallowCopyDemo& other) {
    //     name = other.name;        // Just copies pointer!
    //     grades = other.grades;    // Just copies pointer!
    //     numGrades = other.numGrades;
    // }

    void display() const
    {
        cout << "Student: " << name << ", Grades: ";
        for (int i = 0; i < numGrades; i++)
        {
            cout << grades[i] << " ";
        }
        cout << endl;
        cout << "Name address: " << (void *)name << endl;
        cout << "Grades address: " << (void *)grades << endl;
    }

    void modifyGrade(int index, int newGrade)
    {
        if (index >= 0 && index < numGrades)
        {
            grades[index] = newGrade;
        }
    }

    void modifyName(const char *newName)
    {
        delete[] name; // Free old memory
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }

    // Destructor
    ~ShallowCopyDemo()
    {
        cout << "Destructor called for: " << name << endl;
        delete[] name;
        delete[] grades;
    }
};

// Class to demonstrate DEEP COPY solution
class DeepCopyDemo
{
private:
    char *name;
    int *grades;
    int numGrades;

public:
    // Constructor
    DeepCopyDemo(const char *n, int num)
    {
        cout << "Constructor called for DeepCopyDemo" << endl;

        // Allocate memory for name
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        // Allocate memory for grades
        numGrades = num;
        grades = new int[numGrades];

        // Initialize grades
        for (int i = 0; i < numGrades; i++)
        {
            grades[i] = 80 + i * 5; // 80, 85, 90, etc.
        }

        cout << "Memory allocated for: " << name << endl;
    }

    // DEEP COPY CONSTRUCTOR
    DeepCopyDemo(const DeepCopyDemo &other)
    {
        cout << "Deep Copy Constructor called" << endl;

        // Allocate NEW memory for name
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name); // Copy content, not pointer

        // Allocate NEW memory for grades
        numGrades = other.numGrades;
        grades = new int[numGrades];

        // Copy grades content
        for (int i = 0; i < numGrades; i++)
        {
            grades[i] = other.grades[i];
        }

        cout << "Deep copy completed for: " << name << endl;
        cout << "Original name address: " << (void *)other.name << endl;
        cout << "Copied name address: " << (void *)name << endl;
    }

    // Assignment operator (deep copy)
    DeepCopyDemo &operator=(const DeepCopyDemo &other)
    {
        cout << "Deep Copy Assignment operator called" << endl;

        // Self-assignment check
        if (this == &other)
        {
            return *this;
        }

        // Free existing memory
        delete[] name;
        delete[] grades;

        // Allocate new memory and copy
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        numGrades = other.numGrades;
        grades = new int[numGrades];

        for (int i = 0; i < numGrades; i++)
        {
            grades[i] = other.grades[i];
        }

        cout << "Deep copy assignment completed" << endl;
        return *this;
    }

    void display() const
    {
        cout << "Student: " << name << ", Grades: ";
        for (int i = 0; i < numGrades; i++)
        {
            cout << grades[i] << " ";
        }
        cout << endl;
        cout << "Name address: " << (void *)name << endl;
        cout << "Grades address: " << (void *)grades << endl;
    }

    void modifyGrade(int index, int newGrade)
    {
        if (index >= 0 && index < numGrades)
        {
            grades[index] = newGrade;
            cout << "Grade modified in " << name << endl;
        }
    }

    void modifyName(const char *newName)
    {
        delete[] name;
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
        cout << "Name modified to: " << name << endl;
    }

    // Destructor
    ~DeepCopyDemo()
    {
        cout << "Destructor called for: " << name << endl;
        delete[] name;
        delete[] grades;
    }
};

// Class with mixed shallow and deep copy needs
class MixedCopyDemo
{
private:
    int id;         // Primitive - shallow copy OK
    string name;    // String class handles its own copying
    double *scores; // Dynamic memory - needs deep copy
    int numScores;
    static int totalStudents; // Static - not copied

public:
    MixedCopyDemo(int i, const string &n, int num)
    {
        id = i;
        name = n;
        numScores = num;
        scores = new double[numScores];

        // Initialize scores
        for (int i = 0; i < numScores; i++)
        {
            scores[i] = 70.0 + i * 2.5;
        }

        totalStudents++;
        cout << "MixedCopyDemo created. Total students: " << totalStudents << endl;
    }

    // Copy constructor - mixed approach
    MixedCopyDemo(const MixedCopyDemo &other)
    {
        cout << "Mixed copy constructor called" << endl;

        // Shallow copy for primitives and objects that handle their own copying
        id = other.id;     // Primitive - shallow copy
        name = other.name; // String handles its own copying
        numScores = other.numScores;

        // Deep copy for dynamic memory
        scores = new double[numScores];
        for (int i = 0; i < numScores; i++)
        {
            scores[i] = other.scores[i];
        }

        totalStudents++; // Increment for new object
        cout << "Mixed copy completed. Total students: " << totalStudents << endl;
    }

    void display() const
    {
        cout << "ID: " << id << ", Name: " << name << ", Scores: ";
        for (int i = 0; i < numScores; i++)
        {
            cout << scores[i] << " ";
        }
        cout << endl;
    }

    static int getTotalStudents()
    {
        return totalStudents;
    }

    ~MixedCopyDemo()
    {
        delete[] scores;
        totalStudents--;
        cout << "MixedCopyDemo destroyed. Remaining students: " << totalStudents << endl;
    }
};

int MixedCopyDemo::totalStudents = 0;

void demonstrateShallowCopyProblem()
{
    cout << "\n=== SHALLOW COPY PROBLEM DEMONSTRATION ===" << endl;
    cout << "WARNING: This would cause runtime errors with default copy constructor!" << endl;
    cout << "The default copy constructor does shallow copy:" << endl;
    cout << "- Copies pointer values, not the data they point to" << endl;
    cout << "- Multiple objects share same memory" << endl;
    cout << "- Destructor called multiple times on same memory = CRASH!" << endl;

    // We won't actually run this code as it would crash
    // ShallowCopyDemo student1("John", 3);
    // ShallowCopyDemo student2 = student1;  // Shallow copy - DANGEROUS!
    // student1.modifyGrade(0, 100);         // Affects both objects!
}

int main()
{
    cout << "=== Copy Constructor: Shallow vs Deep Copy ===" << endl;

    // Demonstrate the shallow copy problem (explanation only)
    demonstrateShallowCopyProblem();

    // Demonstrate deep copy solution
    cout << "\n=== DEEP COPY SOLUTION ===" << endl;

    { // Block scope to show destructor calls
        cout << "\n--- Creating original object ---" << endl;
        DeepCopyDemo student1("Alice", 3);
        student1.display();

        cout << "\n--- Creating copy using copy constructor ---" << endl;
        DeepCopyDemo student2 = student1; // Deep copy constructor
        student2.display();

        cout << "\n--- Modifying original object ---" << endl;
        student1.modifyGrade(0, 95);
        student1.modifyName("Alice Modified");

        cout << "Original after modification:" << endl;
        student1.display();
        cout << "Copy remains unchanged:" << endl;
        student2.display();

        cout << "\n--- Testing assignment operator ---" << endl;
        DeepCopyDemo student3("Bob", 2);
        student3 = student1; // Deep copy assignment

        cout << "After assignment:" << endl;
        student3.display();

        cout << "\n--- Objects going out of scope (destructors will be called) ---" << endl;
    }

    // Mixed copy demonstration
    cout << "\n=== MIXED COPY DEMONSTRATION ===" << endl;

    {
        MixedCopyDemo student1(1, "Charlie", 2);
        student1.display();

        MixedCopyDemo student2 = student1; // Mixed copy
        student2.display();

        cout << "Total students: " << MixedCopyDemo::getTotalStudents() << endl;
    }

    cout << "Final total students: " << MixedCopyDemo::getTotalStudents() << endl;

    return 0;
}

/*
SHALLOW vs DEEP COPY SUMMARY:

SHALLOW COPY:
- Copies member values directly
- For pointers: copies pointer value (address), not pointed data
- Problem: Multiple objects share same memory
- Destructor called multiple times on same memory → CRASH
- Good for: Objects with no dynamic memory

DEEP COPY:
- Creates new memory for dynamic data
- Copies actual data, not just pointers
- Each object has independent memory
- Safe destruction - no double deletion
- Required for: Objects with dynamic memory allocation

WHEN TO USE EACH:

SHALLOW COPY (Default):
- Objects with only primitive data types
- Objects with stack-based members
- Objects where sharing data is intentional

DEEP COPY (Custom):
- Objects with dynamic memory (new/malloc)
- Objects with file handles, database connections
- Objects where independence is required

IMPLEMENTATION GUIDELINES:

1. If class has dynamic memory → Implement deep copy
2. If class has primitive types only → Default shallow copy is fine
3. Always implement assignment operator if you implement copy constructor
4. Consider move semantics (C++11) for efficiency

PRACTICE EXERCISES:

1. Create a Matrix class with dynamic 2D array:
   - Implement deep copy constructor
   - Test copying and modification independence

2. Create a String class:
   - Dynamic character array
   - Deep copy constructor and assignment operator
   - String concatenation methods

3. Create a Vector class (like std::vector):
   - Dynamic array with capacity management
   - Deep copy for independent vectors
   - Methods: push_back, resize, etc.
*/
