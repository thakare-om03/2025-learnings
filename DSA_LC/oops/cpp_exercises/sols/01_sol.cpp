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

class Book
{
    string title;
    string author;
    int price;
    int pages;

public:
    Book(string title, string author, int price, int pages)
    {
        this->title = title;
        this->author = author;
        this->price = price;
        this->pages = pages;
    }

    void display()
    {
        int discounted = 0;
        if (price > 500 && pages > 500)
        {
            discounted = price - (price * 0.2);
        }
        cout << "Title : " << title << ", Author : " << author << ", Price : " << price << ", Discout : " << discounted << ", Pages : " << pages << endl;
    }
};

class Car
{
    string brand;
    string model;
    int year;
    float mileage;

public:
    Car(string b, string m, int y, float mil)
    {
        this->brand = b;
        this->model = m;
        this->year = y;
        this->mileage = mil;
    }
    float trip()
    {
        float distance;
        cin >> distance;
        float fuel;
        cin >> fuel;
        cout << "Mileage for this trip : " << distance / fuel << "kmpl" << endl;
    }
    void print()
    {
        cout << "Brand : " << brand << ", Model : " << model << ", Year : " << year << ", Mileage : " << mileage << trip() << endl;
    }
};

class Student
{
    string name;
    int rollNumber;
    int marks;

public:
    Student(string name, int rollNumber, int marks)
    {
        this->name = name;
        this->rollNumber = rollNumber;
        this->marks = marks;
    }
    void getinfo()
    {
        cout << "Student : " << name << ", Roll: " << rollNumber << ", Marks: " << marks << endl;
    }
    ~Student() {}
};

class Rectangle
{

    double width;
    double height;

public:
    Rectangle(double width, double height)
    {
        this->width = width;
        this->height = height;
    }

    double area()
    {
        return width * height;
    }
    double perimeter()
    {
        return 2 * (width + height);
    }
    void result()
    {
        cout << "area : " << area() << endl;
        cout << "perimeter : " << perimeter() << endl;
    }
};

int main()
{
    Student s1("Om", 256, 95);
    Student s2("Achal", 257, 96);
    s1.getinfo();
    s2.getinfo();
    Rectangle r1(55, 110);
    r1.result();
    Book b1("money", "om", 600, 800);
    b1.display();
    Car c1("mahindra", "thar roxx", 2025, 12.5);
    c1.print();
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
