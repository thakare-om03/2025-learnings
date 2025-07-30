/*
==============================================
Exercise 8: Inheritance
==============================================

PROBLEM: Demonstrate all types of inheritance and inheritance modes

Show:
1. Single Inheritance
2. Multiple Inheritance
3. Multilevel Inheritance
4. Hierarchical Inheritance
5. Hybrid Inheritance
6. Modes of Inheritance (public, protected, private)

Expected Output:
All inheritance types demonstrated
Access control in different inheritance modes shown
Diamond problem and its solution
*/

#include <iostream>
#include <string>
using namespace std;

// ==============================================
// 1. SINGLE INHERITANCE
// ==============================================
class Vehicle
{
protected:
    string brand;
    int year;
    double price;

public:
    Vehicle(string b, int y, double p)
    {
        brand = b;
        year = y;
        price = p;
        cout << "Vehicle constructor called" << endl;
    }

    void displayVehicle()
    {
        cout << "Brand: " << brand << ", Year: " << year << ", Price: $" << price << endl;
    }

    virtual ~Vehicle()
    {
        cout << "Vehicle destructor called" << endl;
    }
};

class Car : public Vehicle
{
private:
    int doors;
    string fuelType;

public:
    Car(string b, int y, double p, int d, string fuel) : Vehicle(b, y, p)
    {
        doors = d;
        fuelType = fuel;
        cout << "Car constructor called" << endl;
    }

    void displayCar()
    {
        displayVehicle();
        cout << "Doors: " << doors << ", Fuel: " << fuelType << endl;
    }

    ~Car()
    {
        cout << "Car destructor called" << endl;
    }
};

// ==============================================
// 2. MULTIPLE INHERITANCE
// ==============================================
class Engine
{
protected:
    int horsepower;
    string engineType;

public:
    Engine(int hp, string type)
    {
        horsepower = hp;
        engineType = type;
        cout << "Engine constructor called" << endl;
    }

    void displayEngine()
    {
        cout << "Engine: " << horsepower << "HP, Type: " << engineType << endl;
    }

    virtual ~Engine()
    {
        cout << "Engine destructor called" << endl;
    }
};

class GPS
{
protected:
    string gpsModel;
    bool satelliteConnected;

public:
    GPS(string model)
    {
        gpsModel = model;
        satelliteConnected = true;
        cout << "GPS constructor called" << endl;
    }

    void displayGPS()
    {
        cout << "GPS Model: " << gpsModel
             << ", Connected: " << (satelliteConnected ? "Yes" : "No") << endl;
    }

    virtual ~GPS()
    {
        cout << "GPS destructor called" << endl;
    }
};

// Multiple Inheritance: inherits from both Engine and GPS
class SmartCar : public Engine, public GPS
{
private:
    string model;
    bool autonomous;

public:
    SmartCar(string m, int hp, string engineType, string gpsModel, bool auto_mode)
        : Engine(hp, engineType), GPS(gpsModel)
    {
        model = m;
        autonomous = auto_mode;
        cout << "SmartCar constructor called" << endl;
    }

    void displaySmartCar()
    {
        cout << "Smart Car Model: " << model << endl;
        displayEngine();
        displayGPS();
        cout << "Autonomous: " << (autonomous ? "Yes" : "No") << endl;
    }

    ~SmartCar()
    {
        cout << "SmartCar destructor called" << endl;
    }
};

// ==============================================
// 3. MULTILEVEL INHERITANCE
// ==============================================
// Vehicle -> Car -> SportsCar (chain of inheritance)
class SportsCar : public Car
{
private:
    int topSpeed;
    bool turbocharged;

public:
    SportsCar(string b, int y, double p, int d, string fuel, int speed, bool turbo)
        : Car(b, y, p, d, fuel)
    {
        topSpeed = speed;
        turbocharged = turbo;
        cout << "SportsCar constructor called" << endl;
    }

    void displaySportsCar()
    {
        displayCar();
        cout << "Top Speed: " << topSpeed << " mph, Turbocharged: "
             << (turbocharged ? "Yes" : "No") << endl;
    }

    ~SportsCar()
    {
        cout << "SportsCar destructor called" << endl;
    }
};

// ==============================================
// 4. HIERARCHICAL INHERITANCE
// ==============================================
// Multiple classes inherit from same base class
class Animal
{
protected:
    string name;
    int age;

public:
    Animal(string n, int a)
    {
        name = n;
        age = a;
        cout << "Animal constructor: " << name << endl;
    }

    virtual void makeSound()
    {
        cout << name << " makes a sound" << endl;
    }

    void displayAnimal()
    {
        cout << "Animal: " << name << ", Age: " << age << endl;
    }

    virtual ~Animal()
    {
        cout << "Animal destructor: " << name << endl;
    }
};

class Dog : public Animal
{
private:
    string breed;

public:
    Dog(string n, int a, string b) : Animal(n, a)
    {
        breed = b;
        cout << "Dog constructor: " << name << endl;
    }

    void makeSound() override
    {
        cout << name << " barks: Woof! Woof!" << endl;
    }

    void displayDog()
    {
        displayAnimal();
        cout << "Breed: " << breed << endl;
    }

    ~Dog()
    {
        cout << "Dog destructor: " << name << endl;
    }
};

class Cat : public Animal
{
private:
    bool indoor;

public:
    Cat(string n, int a, bool indoors) : Animal(n, a)
    {
        indoor = indoors;
        cout << "Cat constructor: " << name << endl;
    }

    void makeSound() override
    {
        cout << name << " meows: Meow! Meow!" << endl;
    }

    void displayCat()
    {
        displayAnimal();
        cout << "Indoor cat: " << (indoor ? "Yes" : "No") << endl;
    }

    ~Cat()
    {
        cout << "Cat destructor: " << name << endl;
    }
};

// ==============================================
// 5. HYBRID INHERITANCE & DIAMOND PROBLEM
// ==============================================
class Device
{
protected:
    string deviceId;
    bool powered;

public:
    Device(string id)
    {
        deviceId = id;
        powered = false;
        cout << "Device constructor: " << deviceId << endl;
    }

    virtual void powerOn()
    {
        powered = true;
        cout << "Device " << deviceId << " powered on" << endl;
    }

    virtual ~Device()
    {
        cout << "Device destructor: " << deviceId << endl;
    }
};

class Phone : virtual public Device
{ // Virtual inheritance
protected:
    string phoneNumber;

public:
    Phone(string id, string number) : Device(id)
    {
        phoneNumber = number;
        cout << "Phone constructor: " << phoneNumber << endl;
    }

    void makeCall()
    {
        cout << "Making call from " << phoneNumber << endl;
    }

    ~Phone()
    {
        cout << "Phone destructor: " << phoneNumber << endl;
    }
};

class Camera : virtual public Device
{ // Virtual inheritance
protected:
    int megapixels;

public:
    Camera(string id, int mp) : Device(id)
    {
        megapixels = mp;
        cout << "Camera constructor: " << megapixels << "MP" << endl;
    }

    void takePhoto()
    {
        cout << "Taking photo with " << megapixels << "MP camera" << endl;
    }

    ~Camera()
    {
        cout << "Camera destructor: " << megapixels << "MP" << endl;
    }
};

// Hybrid inheritance: combines multiple inheritance with multilevel
class Smartphone : public Phone, public Camera
{
private:
    string os;

public:
    Smartphone(string id, string number, int mp, string operating_system)
        : Device(id), Phone(id, number), Camera(id, mp)
    { // Note: Device called once due to virtual inheritance
        os = operating_system;
        cout << "Smartphone constructor: " << os << endl;
    }

    void displaySmartphone()
    {
        cout << "Smartphone ID: " << deviceId << ", OS: " << os << endl;
        cout << "Phone: " << phoneNumber << ", Camera: " << megapixels << "MP" << endl;
    }

    // Using both inherited functionalities
    void useSmartphone()
    {
        powerOn();
        makeCall();
        takePhoto();
    }

    ~Smartphone()
    {
        cout << "Smartphone destructor: " << os << endl;
    }
};

// ==============================================
// 6. INHERITANCE MODES DEMONSTRATION
// ==============================================
class BaseClass
{
public:
    int publicMember;
    void publicMethod() { cout << "Public method called" << endl; }

protected:
    int protectedMember;
    void protectedMethod() { cout << "Protected method called" << endl; }

private:
    int privateMember;
    void privateMethod() { cout << "Private method called" << endl; }

public:
    BaseClass()
    {
        publicMember = 1;
        protectedMember = 2;
        privateMember = 3;
    }
};

// Public Inheritance
class PublicDerived : public BaseClass
{
public:
    void accessMembers()
    {
        cout << "\n--- Public Inheritance ---" << endl;
        publicMember = 10;    // ✓ public → public
        protectedMember = 20; // ✓ protected → protected
        // privateMember = 30;  // ✗ private → not accessible

        publicMethod();    // ✓ accessible
        protectedMethod(); // ✓ accessible
        // privateMethod();     // ✗ not accessible
    }
};

// Protected Inheritance
class ProtectedDerived : protected BaseClass
{
public:
    void accessMembers()
    {
        cout << "\n--- Protected Inheritance ---" << endl;
        publicMember = 10;    // ✓ public → protected
        protectedMember = 20; // ✓ protected → protected
        // privateMember = 30;  // ✗ private → not accessible

        publicMethod();    // ✓ accessible (but now protected)
        protectedMethod(); // ✓ accessible
        // privateMethod();     // ✗ not accessible
    }
};

// Private Inheritance
class PrivateDerived : private BaseClass
{
public:
    void accessMembers()
    {
        cout << "\n--- Private Inheritance ---" << endl;
        publicMember = 10;    // ✓ public → private
        protectedMember = 20; // ✓ protected → private
        // privateMember = 30;  // ✗ private → not accessible

        publicMethod();    // ✓ accessible (but now private)
        protectedMethod(); // ✓ accessible (but now private)
        // privateMethod();     // ✗ not accessible
    }
};

int main()
{
    cout << "=== INHERITANCE TYPES DEMONSTRATION ===" << endl;

    // 1. Single Inheritance
    cout << "\n=== 1. SINGLE INHERITANCE ===" << endl;
    Car myCar("Toyota", 2023, 25000, 4, "Gasoline");
    myCar.displayCar();

    // 2. Multiple Inheritance
    cout << "\n=== 2. MULTIPLE INHERITANCE ===" << endl;
    SmartCar smartCar("Tesla Model X", 500, "Electric", "GPS Pro", true);
    smartCar.displaySmartCar();

    // 3. Multilevel Inheritance
    cout << "\n=== 3. MULTILEVEL INHERITANCE ===" << endl;
    SportsCar ferrari("Ferrari", 2023, 200000, 2, "Gasoline", 220, true);
    ferrari.displaySportsCar();

    // 4. Hierarchical Inheritance
    cout << "\n=== 4. HIERARCHICAL INHERITANCE ===" << endl;
    Dog myDog("Buddy", 3, "Golden Retriever");
    Cat myCat("Whiskers", 2, true);

    myDog.displayDog();
    myDog.makeSound();

    myCat.displayCat();
    myCat.makeSound();

    // 5. Hybrid Inheritance (with virtual inheritance)
    cout << "\n=== 5. HYBRID INHERITANCE ===" << endl;
    Smartphone iPhone("iPhone15", "+1-555-0123", 48, "iOS 17");
    iPhone.displaySmartphone();
    iPhone.useSmartphone();

    // 6. Inheritance Modes
    cout << "\n=== 6. INHERITANCE MODES ===" << endl;
    PublicDerived pubObj;
    pubObj.accessMembers();
    pubObj.publicMethod(); // Still accessible from outside

    ProtectedDerived protObj;
    protObj.accessMembers();
    // protObj.publicMethod();  // Not accessible from outside (now protected)

    PrivateDerived privObj;
    privObj.accessMembers();
    // privObj.publicMethod();  // Not accessible from outside (now private)

    cout << "\n=== Program Ending - Destructors will be called ===" << endl;
    return 0;
}

/*
INHERITANCE SUMMARY:

1. SINGLE INHERITANCE:
   - One derived class, one base class
   - Simple and most common form
   - Derived class inherits all non-private members

2. MULTIPLE INHERITANCE:
   - One class inherits from multiple base classes
   - Can cause ambiguity if same member names exist
   - Use scope resolution (::) to resolve ambiguity

3. MULTILEVEL INHERITANCE:
   - Chain of inheritance (A→B→C)
   - Each level adds more functionality
   - Constructors called from top to bottom, destructors reverse

4. HIERARCHICAL INHERITANCE:
   - Multiple classes inherit from same base
   - Common functionality shared among derived classes
   - Virtual functions enable polymorphism

5. HYBRID INHERITANCE:
   - Combination of multiple inheritance types
   - Can cause diamond problem
   - Use virtual inheritance to solve diamond problem

INHERITANCE MODES:

PUBLIC INHERITANCE:
- public → public
- protected → protected
- private → not accessible
- "IS-A" relationship

PROTECTED INHERITANCE:
- public → protected
- protected → protected
- private → not accessible
- Less common, restricts external access

PRIVATE INHERITANCE:
- public → private
- protected → private
- private → not accessible
- "IMPLEMENTED-IN-TERMS-OF" relationship

DIAMOND PROBLEM:
- Occurs in multiple inheritance when two base classes inherit from same grandparent
- Results in ambiguity and duplicate copies
- Solution: Virtual inheritance ensures single copy of grandparent

PRACTICE EXERCISES:

1. Create a Shape hierarchy:
   - Base: Shape (with area calculation)
   - Derived: Rectangle, Circle, Triangle
   - Test hierarchical inheritance

2. Create a Person-Student-Teacher system:
   - Person (base class)
   - Student and Teacher inherit from Person
   - GraduateStudent inherits from Student (multilevel)

3. Create a media player system:
   - AudioPlayer and VideoPlayer base classes
   - MultimediaPlayer with multiple inheritance
   - Handle diamond problem with virtual inheritance

4. Test all inheritance modes:
   - Create base class with different access levels
   - Show how inheritance mode affects access
*/
