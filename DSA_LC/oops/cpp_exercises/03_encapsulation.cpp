/*
==============================================
Exercise 3: Encapsulation
==============================================

PROBLEM: Demonstrate encapsulation principles

Create a BankAccount class that properly encapsulates data:
- Private data members that cannot be accessed directly
- Public methods to interact with the data safely
- Data validation in setter methods
- Proper getter methods

Expected Output:
Account created successfully!
Initial Balance: 1000
After deposit of 500: 1500
After withdrawal of 200: 1300
Invalid withdrawal amount!
Current Balance: 1300
Account holder: John Doe
*/

#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    // Private data members - encapsulated
    string accountNumber;
    string accountHolderName;
    double balance;
    string accountType;

    // Private helper method
    bool isValidAmount(double amount)
    {
        return amount > 0;
    }

public:
    // Constructor
    BankAccount(string accNum, string name, double initialBalance, string type)
    {
        accountNumber = accNum;
        accountHolderName = name;
        accountType = type;

        // Validate initial balance
        if (initialBalance >= 0)
        {
            balance = initialBalance;
            cout << "Account created successfully!" << endl;
        }
        else
        {
            balance = 0;
            cout << "Invalid initial balance. Set to 0." << endl;
        }
    }

    // Public interface methods (encapsulation in action)

    // Deposit money with validation
    bool deposit(double amount)
    {
        if (isValidAmount(amount))
        {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
            return true;
        }
        else
        {
            cout << "Invalid deposit amount!" << endl;
            return false;
        }
    }

    // Withdraw money with validation
    bool withdraw(double amount)
    {
        if (!isValidAmount(amount))
        {
            cout << "Invalid withdrawal amount!" << endl;
            return false;
        }

        if (amount > balance)
        {
            cout << "Insufficient funds!" << endl;
            return false;
        }

        balance -= amount;
        cout << "Withdrawn: $" << amount << endl;
        return true;
    }

    // Getter methods (controlled access to private data)
    double getBalance() const
    {
        return balance;
    }

    string getAccountNumber() const
    {
        return accountNumber;
    }

    string getAccountHolderName() const
    {
        return accountHolderName;
    }

    string getAccountType() const
    {
        return accountType;
    }

    // Method to display account information
    void displayAccountInfo() const
    {
        cout << "\n=== Account Information ===" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Current Balance: $" << balance << endl;
    }

    // Transfer money to another account
    bool transferTo(BankAccount &targetAccount, double amount)
    {
        if (!isValidAmount(amount))
        {
            cout << "Invalid transfer amount!" << endl;
            return false;
        }

        if (amount > balance)
        {
            cout << "Insufficient funds for transfer!" << endl;
            return false;
        }

        // Withdraw from this account and deposit to target account
        balance -= amount;
        targetAccount.balance += amount;

        cout << "Transferred $" << amount << " to " << targetAccount.accountHolderName << endl;
        return true;
    }
};

// Example of a more complex encapsulated class
class Student
{
private:
    string studentId;
    string name;
    int age;
    double *grades; // Dynamic array for grades
    int numSubjects;
    double gpa;

    // Private method to calculate GPA
    void calculateGPA()
    {
        if (numSubjects == 0)
        {
            gpa = 0.0;
            return;
        }

        double sum = 0;
        for (int i = 0; i < numSubjects; i++)
        {
            sum += grades[i];
        }
        gpa = sum / numSubjects;
    }

public:
    // Constructor
    Student(string id, string n, int a, int subjects)
    {
        studentId = id;
        name = n;
        age = (a > 0) ? a : 18; // Default age validation
        numSubjects = subjects;
        grades = new double[numSubjects];

        // Initialize grades to 0
        for (int i = 0; i < numSubjects; i++)
        {
            grades[i] = 0.0;
        }
        gpa = 0.0;
    }

    // Destructor for proper memory management
    ~Student()
    {
        delete[] grades;
    }

    // Method to add grade with validation
    bool addGrade(int subjectIndex, double grade)
    {
        if (subjectIndex < 0 || subjectIndex >= numSubjects)
        {
            cout << "Invalid subject index!" << endl;
            return false;
        }

        if (grade < 0 || grade > 100)
        {
            cout << "Grade must be between 0 and 100!" << endl;
            return false;
        }

        grades[subjectIndex] = grade;
        calculateGPA(); // Recalculate GPA
        return true;
    }

    // Getter methods
    string getName() const { return name; }
    double getGPA() const { return gpa; }

    void displayStudentInfo() const
    {
        cout << "\n=== Student Information ===" << endl;
        cout << "Student ID: " << studentId << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "GPA: " << gpa << endl;
        cout << "Grades: ";
        for (int i = 0; i < numSubjects; i++)
        {
            cout << grades[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    cout << "=== Encapsulation Demonstration ===" << endl;

    // Bank Account Example
    cout << "\n--- Bank Account Example ---" << endl;
    BankAccount account1("12345", "John Doe", 1000, "Savings");

    cout << "Initial Balance: " << account1.getBalance() << endl;

    account1.deposit(500);
    cout << "After deposit of 500: " << account1.getBalance() << endl;

    account1.withdraw(200);
    cout << "After withdrawal of 200: " << account1.getBalance() << endl;

    account1.withdraw(2000); // Should fail
    cout << "Current Balance: " << account1.getBalance() << endl;

    cout << "Account holder: " << account1.getAccountHolderName() << endl;

    // Create another account for transfer demo
    BankAccount account2("67890", "Jane Smith", 500, "Checking");

    cout << "\n--- Transfer Example ---" << endl;
    cout << "Before transfer:" << endl;
    cout << "Account1 Balance: " << account1.getBalance() << endl;
    cout << "Account2 Balance: " << account2.getBalance() << endl;

    account1.transferTo(account2, 300);

    cout << "After transfer:" << endl;
    cout << "Account1 Balance: " << account1.getBalance() << endl;
    cout << "Account2 Balance: " << account2.getBalance() << endl;

    // Student Example
    cout << "\n--- Student Example ---" << endl;
    Student student("S001", "Alice Johnson", 20, 3);

    student.addGrade(0, 85.5); // Subject 1
    student.addGrade(1, 92.0); // Subject 2
    student.addGrade(2, 88.5); // Subject 3

    student.displayStudentInfo();

    // Try invalid operations
    student.addGrade(5, 95);  // Invalid index
    student.addGrade(1, 105); // Invalid grade

    return 0;
}

/*
ENCAPSULATION PRINCIPLES DEMONSTRATED:

1. DATA HIDING:
   - Private data members cannot be accessed directly
   - Only through public methods (controlled access)

2. DATA VALIDATION:
   - Setter methods validate input before modifying data
   - Prevents invalid states

3. ABSTRACTION:
   - Users don't need to know internal implementation
   - Simple interface hides complexity

4. SECURITY:
   - Protected access to sensitive data
   - Prevents unauthorized modifications

PRACTICE EXERCISES:

1. Create an Employee class with proper encapsulation:
   - Private: salary, employeeId, performance rating
   - Public methods: give raise (with validation), get info, etc.

2. Create a Library class that manages books:
   - Encapsulate book collection
   - Methods: add book, remove book, search book
   - Validate operations

3. Create a Temperature class:
   - Store temperature in Celsius (private)
   - Public methods to get/set in Celsius, Fahrenheit, Kelvin
   - Validate temperature ranges
*/
