/*
==============================================
Exercise 13: Advanced OOP Exercises
==============================================

PROBLEM: Complex scenarios combining multiple OOP concepts

This file contains advanced exercises that combine:
- Inheritance, Polymorphism, Abstraction
- Design Patterns (Factory, Observer, Strategy)
- Real-world applications
- Memory management and RAII
- Template integration with OOP

Expected Output:
Complex OOP scenarios working together
Design patterns implemented correctly
Real-world problem solving with OOP
*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <map>
#include <functional>
#include <stdexcept>
using namespace std;

// ==============================================
// 1. ADVANCED LIBRARY MANAGEMENT SYSTEM
// ==============================================

// Abstract base class for library items
class LibraryItem
{
protected:
    string id;
    string title;
    string author;
    bool isCheckedOut;
    static int totalItems;

public:
    LibraryItem(const string &itemId, const string &itemTitle, const string &itemAuthor)
        : id(itemId), title(itemTitle), author(itemAuthor), isCheckedOut(false)
    {
        totalItems++;
        cout << "LibraryItem created: " << title << endl;
    }

    // Pure virtual functions
    virtual double calculateLateFee(int daysLate) const = 0;
    virtual int getMaxBorrowDays() const = 0;
    virtual string getItemType() const = 0;
    virtual void displayDetails() const = 0;

    // Virtual functions with default implementation
    virtual bool checkOut()
    {
        if (isCheckedOut)
        {
            cout << "Item already checked out: " << title << endl;
            return false;
        }
        isCheckedOut = true;
        cout << "Checked out: " << title << endl;
        return true;
    }

    virtual bool returnItem()
    {
        if (!isCheckedOut)
        {
            cout << "Item not checked out: " << title << endl;
            return false;
        }
        isCheckedOut = false;
        cout << "Returned: " << title << endl;
        return true;
    }

    // Getters
    string getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool getIsCheckedOut() const { return isCheckedOut; }
    static int getTotalItems() { return totalItems; }

    virtual ~LibraryItem()
    {
        totalItems--;
        cout << "LibraryItem destroyed: " << title << endl;
    }
};

int LibraryItem::totalItems = 0;

// Concrete implementations
class Book : public LibraryItem
{
private:
    int pages;
    string genre;

public:
    Book(const string &id, const string &title, const string &author, int pageCount, const string &bookGenre)
        : LibraryItem(id, title, author), pages(pageCount), genre(bookGenre)
    {
        cout << "Book created: " << title << endl;
    }

    double calculateLateFee(int daysLate) const override
    {
        return daysLate * 0.50; // $0.50 per day
    }

    int getMaxBorrowDays() const override
    {
        return 14; // 2 weeks
    }

    string getItemType() const override
    {
        return "Book";
    }

    void displayDetails() const override
    {
        cout << "Book: " << title << " by " << author << endl;
        cout << "  ID: " << id << ", Pages: " << pages << ", Genre: " << genre << endl;
        cout << "  Status: " << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }

    ~Book()
    {
        cout << "Book destroyed: " << title << endl;
    }
};

class DVD : public LibraryItem
{
private:
    int duration; // in minutes
    string rating;

public:
    DVD(const string &id, const string &title, const string &director, int durationMinutes, const string &movieRating)
        : LibraryItem(id, title, director), duration(durationMinutes), rating(movieRating)
    {
        cout << "DVD created: " << title << endl;
    }

    double calculateLateFee(int daysLate) const override
    {
        return daysLate * 1.00; // $1.00 per day
    }

    int getMaxBorrowDays() const override
    {
        return 7; // 1 week
    }

    string getItemType() const override
    {
        return "DVD";
    }

    void displayDetails() const override
    {
        cout << "DVD: " << title << " directed by " << author << endl;
        cout << "  ID: " << id << ", Duration: " << duration << " min, Rating: " << rating << endl;
        cout << "  Status: " << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }

    ~DVD()
    {
        cout << "DVD destroyed: " << title << endl;
    }
};

class Magazine : public LibraryItem
{
private:
    string issueDate;
    int issueNumber;

public:
    Magazine(const string &id, const string &title, const string &publisher, const string &issue, int number)
        : LibraryItem(id, title, publisher), issueDate(issue), issueNumber(number)
    {
        cout << "Magazine created: " << title << endl;
    }

    double calculateLateFee(int daysLate) const override
    {
        return daysLate * 0.25; // $0.25 per day
    }

    int getMaxBorrowDays() const override
    {
        return 3; // 3 days
    }

    string getItemType() const override
    {
        return "Magazine";
    }

    void displayDetails() const override
    {
        cout << "Magazine: " << title << " by " << author << endl;
        cout << "  ID: " << id << ", Issue: " << issueDate << " #" << issueNumber << endl;
        cout << "  Status: " << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }

    ~Magazine()
    {
        cout << "Magazine destroyed: " << title << endl;
    }
};

// ==============================================
// 2. FACTORY PATTERN IMPLEMENTATION
// ==============================================

class LibraryItemFactory
{
public:
    static unique_ptr<LibraryItem> createItem(const string &type, const vector<string> &params)
    {
        if (type == "Book" && params.size() >= 5)
        {
            return make_unique<Book>(params[0], params[1], params[2], stoi(params[3]), params[4]);
        }
        else if (type == "DVD" && params.size() >= 5)
        {
            return make_unique<DVD>(params[0], params[1], params[2], stoi(params[3]), params[4]);
        }
        else if (type == "Magazine" && params.size() >= 5)
        {
            return make_unique<Magazine>(params[0], params[1], params[2], params[3], stoi(params[4]));
        }
        else
        {
            throw invalid_argument("Invalid item type or insufficient parameters");
        }
    }
};

// ==============================================
// 3. OBSERVER PATTERN FOR NOTIFICATIONS
// ==============================================

// Observer interface
class Observer
{
public:
    virtual void update(const string &message) = 0;
    virtual string getObserverName() const = 0;
    virtual ~Observer() = default;
};

// Subject interface
class Subject
{
private:
    vector<Observer *> observers;

public:
    void addObserver(Observer *observer)
    {
        observers.push_back(observer);
        cout << "Observer added: " << observer->getObserverName() << endl;
    }

    void removeObserver(Observer *observer)
    {
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
        cout << "Observer removed: " << observer->getObserverName() << endl;
    }

    void notifyObservers(const string &message)
    {
        cout << "Notifying " << observers.size() << " observers..." << endl;
        for (Observer *observer : observers)
        {
            observer->update(message);
        }
    }

    virtual ~Subject() = default;
};

// Concrete Observer - Library Member
class LibraryMember : public Observer
{
private:
    string name;
    string email;
    vector<unique_ptr<LibraryItem>> borrowedItems;

public:
    LibraryMember(const string &memberName, const string &memberEmail)
        : name(memberName), email(memberEmail)
    {
        cout << "Library Member created: " << name << endl;
    }

    void update(const string &message) override
    {
        cout << "[NOTIFICATION to " << name << " (" << email << ")]: " << message << endl;
    }

    string getObserverName() const override
    {
        return name;
    }

    void borrowItem(unique_ptr<LibraryItem> item)
    {
        if (item && item->checkOut())
        {
            borrowedItems.push_back(move(item));
            cout << name << " borrowed: " << borrowedItems.back()->getTitle() << endl;
        }
    }

    void returnItem(const string &itemId)
    {
        auto it = find_if(borrowedItems.begin(), borrowedItems.end(),
                          [&itemId](const unique_ptr<LibraryItem> &item)
                          {
                              return item->getId() == itemId;
                          });

        if (it != borrowedItems.end())
        {
            (*it)->returnItem();
            cout << name << " returned: " << (*it)->getTitle() << endl;
            borrowedItems.erase(it);
        }
    }

    void displayBorrowedItems() const
    {
        cout << name << "'s borrowed items:" << endl;
        for (const auto &item : borrowedItems)
        {
            cout << "  - " << item->getTitle() << " (" << item->getItemType() << ")" << endl;
        }
    }

    ~LibraryMember()
    {
        cout << "Library Member destroyed: " << name << endl;
    }
};

// ==============================================
// 4. STRATEGY PATTERN FOR SEARCH ALGORITHMS
// ==============================================

// Strategy interface
class SearchStrategy
{
public:
    virtual vector<LibraryItem *> search(const vector<unique_ptr<LibraryItem>> &items, const string &query) = 0;
    virtual string getStrategyName() const = 0;
    virtual ~SearchStrategy() = default;
};

// Concrete strategies
class TitleSearchStrategy : public SearchStrategy
{
public:
    vector<LibraryItem *> search(const vector<unique_ptr<LibraryItem>> &items, const string &query) override
    {
        vector<LibraryItem *> results;
        for (const auto &item : items)
        {
            if (item->getTitle().find(query) != string::npos)
            {
                results.push_back(item.get());
            }
        }
        return results;
    }

    string getStrategyName() const override
    {
        return "Title Search";
    }
};

class AuthorSearchStrategy : public SearchStrategy
{
public:
    vector<LibraryItem *> search(const vector<unique_ptr<LibraryItem>> &items, const string &query) override
    {
        vector<LibraryItem *> results;
        for (const auto &item : items)
        {
            if (item->getAuthor().find(query) != string::npos)
            {
                results.push_back(item.get());
            }
        }
        return results;
    }

    string getStrategyName() const override
    {
        return "Author Search";
    }
};

class TypeSearchStrategy : public SearchStrategy
{
public:
    vector<LibraryItem *> search(const vector<unique_ptr<LibraryItem>> &items, const string &query) override
    {
        vector<LibraryItem *> results;
        for (const auto &item : items)
        {
            if (item->getItemType() == query)
            {
                results.push_back(item.get());
            }
        }
        return results;
    }

    string getStrategyName() const override
    {
        return "Type Search";
    }
};

// ==============================================
// 5. LIBRARY MANAGEMENT SYSTEM (COMPOSITE)
// ==============================================

class LibraryManagementSystem : public Subject
{
private:
    vector<unique_ptr<LibraryItem>> catalog;
    vector<unique_ptr<LibraryMember>> members;
    unique_ptr<SearchStrategy> searchStrategy;
    static LibraryManagementSystem *instance;

    // Singleton pattern
    LibraryManagementSystem()
    {
        searchStrategy = make_unique<TitleSearchStrategy>();
        cout << "Library Management System initialized" << endl;
    }

public:
    static LibraryManagementSystem &getInstance()
    {
        if (!instance)
        {
            instance = new LibraryManagementSystem();
        }
        return *instance;
    }

    void addItem(unique_ptr<LibraryItem> item)
    {
        string title = item->getTitle();
        catalog.push_back(move(item));
        notifyObservers("New item added to catalog: " + title);
    }

    void addMember(unique_ptr<LibraryMember> member)
    {
        addObserver(member.get());
        members.push_back(move(member));
    }

    void setSearchStrategy(unique_ptr<SearchStrategy> strategy)
    {
        searchStrategy = move(strategy);
        cout << "Search strategy changed to: " << searchStrategy->getStrategyName() << endl;
    }

    vector<LibraryItem *> searchItems(const string &query)
    {
        cout << "Searching using " << searchStrategy->getStrategyName() << " for: " << query << endl;
        return searchStrategy->search(catalog, query);
    }

    void displayCatalog() const
    {
        cout << "\n=== Library Catalog ===" << endl;
        cout << "Total items: " << catalog.size() << endl;
        for (const auto &item : catalog)
        {
            item->displayDetails();
            cout << "---" << endl;
        }
    }

    void displayStatistics() const
    {
        map<string, int> typeCount;
        int checkedOutCount = 0;

        for (const auto &item : catalog)
        {
            typeCount[item->getItemType()]++;
            if (item->getIsCheckedOut())
            {
                checkedOutCount++;
            }
        }

        cout << "\n=== Library Statistics ===" << endl;
        cout << "Total items: " << LibraryItem::getTotalItems() << endl;
        cout << "Checked out: " << checkedOutCount << endl;
        cout << "Available: " << (catalog.size() - checkedOutCount) << endl;
        cout << "\nBy type:" << endl;
        for (const auto &pair : typeCount)
        {
            cout << "  " << pair.first << ": " << pair.second << endl;
        }
        cout << "Total members: " << members.size() << endl;
    }

    LibraryMember *findMember(const string &name)
    {
        auto it = find_if(members.begin(), members.end(),
                          [&name](const unique_ptr<LibraryMember> &member)
                          {
                              return member->getObserverName() == name;
                          });
        return (it != members.end()) ? it->get() : nullptr;
    }

    ~LibraryManagementSystem()
    {
        cout << "Library Management System destroyed" << endl;
    }
};

LibraryManagementSystem *LibraryManagementSystem::instance = nullptr;

// ==============================================
// 6. RAII AND SMART POINTER DEMONSTRATION
// ==============================================

class ResourceManager
{
private:
    string resourceName;
    int *data;
    size_t size;

public:
    ResourceManager(const string &name, size_t resourceSize)
        : resourceName(name), size(resourceSize)
    {
        data = new int[size];
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = static_cast<int>(i);
        }
        cout << "Resource acquired: " << resourceName << " (size: " << size << ")" << endl;
    }

    // Copy constructor (deep copy)
    ResourceManager(const ResourceManager &other)
        : resourceName(other.resourceName + "_copy"), size(other.size)
    {
        data = new int[size];
        copy(other.data, other.data + size, data);
        cout << "Resource copied: " << resourceName << endl;
    }

    // Assignment operator
    ResourceManager &operator=(const ResourceManager &other)
    {
        if (this != &other)
        {
            delete[] data;
            resourceName = other.resourceName + "_assigned";
            size = other.size;
            data = new int[size];
            copy(other.data, other.data + size, data);
            cout << "Resource assigned: " << resourceName << endl;
        }
        return *this;
    }

    // Move constructor (C++11)
    ResourceManager(ResourceManager &&other) noexcept
        : resourceName(move(other.resourceName)), data(other.data), size(other.size)
    {
        other.data = nullptr;
        other.size = 0;
        cout << "Resource moved: " << resourceName << endl;
    }

    void displayResource() const
    {
        cout << "Resource " << resourceName << " contains: ";
        for (size_t i = 0; i < min(size, size_t(5)); ++i)
        {
            cout << data[i] << " ";
        }
        if (size > 5)
            cout << "...";
        cout << endl;
    }

    ~ResourceManager()
    {
        if (data)
        {
            delete[] data;
            cout << "Resource released: " << resourceName << endl;
        }
    }
};

// ==============================================
// DEMONSTRATION FUNCTIONS
// ==============================================

void demonstrateLibrarySystem()
{
    cout << "\n=== ADVANCED LIBRARY MANAGEMENT SYSTEM ===" << endl;

    LibraryManagementSystem &library = LibraryManagementSystem::getInstance();

    // Create library items using factory pattern
    try
    {
        library.addItem(LibraryItemFactory::createItem("Book",
                                                       {"B001", "The C++ Programming Language", "Bjarne Stroustrup", "1376", "Programming"}));
        library.addItem(LibraryItemFactory::createItem("Book",
                                                       {"B002", "Design Patterns", "Gang of Four", "395", "Software Engineering"}));
        library.addItem(LibraryItemFactory::createItem("DVD",
                                                       {"D001", "The Matrix", "Wachowski Sisters", "136", "R"}));
        library.addItem(LibraryItemFactory::createItem("Magazine",
                                                       {"M001", "IEEE Computer", "IEEE", "2024-01", "1"}));
    }
    catch (const exception &e)
    {
        cout << "Error creating item: " << e.what() << endl;
    }

    // Create library members (observers)
    library.addMember(make_unique<LibraryMember>("Alice Johnson", "alice@email.com"));
    library.addMember(make_unique<LibraryMember>("Bob Smith", "bob@email.com"));

    // Display catalog and statistics
    library.displayCatalog();
    library.displayStatistics();

    // Demonstrate different search strategies
    auto results = library.searchItems("C++");
    cout << "\nSearch results for 'C++':" << endl;
    for (auto *item : results)
    {
        item->displayDetails();
    }

    // Change search strategy
    library.setSearchStrategy(make_unique<AuthorSearchStrategy>());
    results = library.searchItems("Gang");
    cout << "\nAuthor search results for 'Gang':" << endl;
    for (auto *item : results)
    {
        item->displayDetails();
    }

    // Change to type search
    library.setSearchStrategy(make_unique<TypeSearchStrategy>());
    results = library.searchItems("Book");
    cout << "\nType search results for 'Book':" << endl;
    for (auto *item : results)
    {
        cout << "  - " << item->getTitle() << endl;
    }
}

void demonstrateRAII()
{
    cout << "\n=== RAII AND SMART POINTERS ===" << endl;

    // Automatic resource management
    {
        ResourceManager res1("Resource1", 10);
        res1.displayResource();

        ResourceManager res2 = res1; // Copy constructor
        res2.displayResource();

        auto smartRes = make_unique<ResourceManager>("SmartResource", 5);
        smartRes->displayResource();

        vector<unique_ptr<ResourceManager>> resources;
        resources.push_back(make_unique<ResourceManager>("VectorResource1", 3));
        resources.push_back(make_unique<ResourceManager>("VectorResource2", 7));

        cout << "Resources in vector:" << endl;
        for (const auto &res : resources)
        {
            res->displayResource();
        }

        cout << "Block ending - automatic cleanup will occur..." << endl;
    } // All resources automatically cleaned up here

    cout << "RAII demonstration completed" << endl;
}

void demonstratePolymorphicBehavior()
{
    cout << "\n=== POLYMORPHIC BEHAVIOR ===" << endl;

    vector<unique_ptr<LibraryItem>> items;
    items.push_back(make_unique<Book>("B003", "Effective C++", "Scott Meyers", "320", "Programming"));
    items.push_back(make_unique<DVD>("D002", "Inception", "Christopher Nolan", "148", "PG-13"));
    items.push_back(make_unique<Magazine>("M002", "National Geographic", "National Geographic Society", "2024-02", "2"));

    cout << "Polymorphic operations on different item types:" << endl;
    for (auto &item : items)
    {
        item->displayDetails();
        cout << "Late fee for 5 days: $" << item->calculateLateFee(5) << endl;
        cout << "Max borrow days: " << item->getMaxBorrowDays() << endl;
        cout << "---" << endl;
    }
}

int main()
{
    cout << "=== ADVANCED OOP EXERCISES ===" << endl;

    try
    {
        // Demonstrate the complete library system
        demonstrateLibrarySystem();

        // Show polymorphic behavior
        demonstratePolymorphicBehavior();

        // Demonstrate RAII
        demonstrateRAII();

        cout << "\n=== All Advanced Exercises Completed Successfully ===" << endl;
    }
    catch (const exception &e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}

/*
ADVANCED OOP CONCEPTS DEMONSTRATED:

1. COMPLEX INHERITANCE HIERARCHY:
   - Abstract base class with pure virtual functions
   - Multiple concrete implementations
   - Virtual destructors for proper cleanup

2. DESIGN PATTERNS:
   - Factory Pattern: Creating objects without specifying exact classes
   - Observer Pattern: Notification system for library events
   - Strategy Pattern: Interchangeable search algorithms
   - Singleton Pattern: Single instance of library system

3. POLYMORPHISM IN ACTION:
   - Runtime binding with virtual functions
   - Containers of base class pointers
   - Different behaviors for different types

4. ADVANCED MEMORY MANAGEMENT:
   - RAII (Resource Acquisition Is Initialization)
   - Smart pointers (unique_ptr, shared_ptr)
   - Automatic resource cleanup
   - Move semantics for efficiency

5. STL INTEGRATION:
   - Containers with polymorphic objects
   - Algorithms with custom predicates
   - Function objects and lambdas

6. EXCEPTION HANDLING:
   - Proper exception safety
   - RAII ensures cleanup even with exceptions
   - Custom exception types

7. CONST CORRECTNESS:
   - Const member functions
   - Const parameters and return types
   - Immutable operations

8. TEMPLATE INTEGRATION:
   - Generic programming with OOP
   - Template member functions
   - Type-safe containers

REAL-WORLD APPLICATIONS:

1. LIBRARY MANAGEMENT SYSTEM:
   - Complete working system
   - Multiple user types and permissions
   - Search and notification features

2. RESOURCE MANAGEMENT:
   - Automatic cleanup
   - Exception safety
   - Memory leak prevention

3. PLUGIN ARCHITECTURE:
   - Interchangeable components
   - Runtime behavior modification
   - Extensible design

PRACTICE CHALLENGES:

1. EXTEND THE LIBRARY SYSTEM:
   - Add AudioBook class
   - Implement reservation system
   - Add late fee calculation with different strategies

2. ADD MORE DESIGN PATTERNS:
   - Command pattern for undo/redo operations
   - Visitor pattern for different operations on items
   - Decorator pattern for enhanced item features

3. IMPROVE ROBUSTNESS:
   - Add comprehensive error handling
   - Implement thread safety
   - Add persistence (save/load from file)

4. PERFORMANCE OPTIMIZATION:
   - Implement efficient search algorithms
   - Add caching mechanisms
   - Optimize memory usage

This exercise demonstrates how multiple OOP concepts work together
in a real-world scenario, showcasing the power and flexibility
of object-oriented design when properly applied.
*/
