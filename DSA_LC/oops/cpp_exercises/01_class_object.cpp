/*
==============================================
Exercise 1: Class & Object Basics
==============================================

PROBLEM 1: Create a Student class
- Create a Student class with private data members: name, rollNumber, marks
- Create public member functions to set and get these values
- Create objects and demonstrate their usage

Expected Output:
Student 1: John, Roll: 101, Marks: 85.5
Student 2: Alice, Roll: 102, Marks: 92.0

PROBLEM 2: Rectangle class
- Create a Rectangle class with length and width
- Add methods to calculate area and perimeter
- Create multiple objects and display their properties

Expected Output:
Rectangle 1: Length=5, Width=3, Area=15, Perimeter=16
Rectangle 2: Length=7, Width=4, Area=28, Perimeter=22
*/

#include <iostream>
#include <string>
using namespace std;

// SOLUTION FOR PROBLEM 1
class Student
{
private:
    string name;
    int rollNumber;
    double marks;

public:
    // Setter methods
    void setName(string n)
    {
        name = n;
    }

    void setRollNumber(int roll)
    {
        rollNumber = roll;
    }

    void setMarks(double m)
    {
        marks = m;
    }

    // Getter methods
    string getName()
    {
        return name;
    }

    int getRollNumber()
    {
        return rollNumber;
    }

    double getMarks()
    {
        return marks;
    }

    // Display method
    void display()
    {
        cout << "Student: " << name << ", Roll: " << rollNumber
             << ", Marks: " << marks << endl;
    }
};

// SOLUTION FOR PROBLEM 2
class Rectangle
{
private:
    double length;
    double width;

public:
    void setDimensions(double l, double w)
    {
        length = l;
        width = w;
    }

    double calculateArea()
    {
        return length * width;
    }

    double calculatePerimeter()
    {
        return 2 * (length + width);
    }

    void display()
    {
        cout << "Rectangle: Length=" << length << ", Width=" << width
             << ", Area=" << calculateArea() << ", Perimeter=" << calculatePerimeter() << endl;
    }
};

int main()
{
    cout << "=== PROBLEM 1: Student Class ===" << endl;

    // Creating Student objects
    Student s1, s2;

    s1.setName("John");
    s1.setRollNumber(101);
    s1.setMarks(85.5);

    s2.setName("Alice");
    s2.setRollNumber(102);
    s2.setMarks(92.0);

    s1.display();
    s2.display();

    cout << "\n=== PROBLEM 2: Rectangle Class ===" << endl;

    // Creating Rectangle objects
    Rectangle r1, r2;

    r1.setDimensions(5, 3);
    r2.setDimensions(7, 4);

    r1.display();
    r2.display();

    return 0;
}

/*
PRACTICE EXERCISES (Try these on your own):

1. Create a Book class with title, author, price, and pages
   - Add methods to apply discount and display book info

2. Create a BankAccount class with accountNumber, balance
   - Add methods for deposit, withdraw, and check balance
   - Ensure balance cannot go negative

3. Create a Car class with brand, model, year, mileage
   - Add methods to calculate fuel cost for a given distance
*/
