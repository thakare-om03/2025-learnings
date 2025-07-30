/*
==============================================
Exercise 11: Abstraction
==============================================

PROBLEM: Demonstrate abstraction using abstract classes and pure virtual functions

Show:
1. Abstract classes with pure virtual functions
2. Interface design patterns
3. Data abstraction and hiding implementation details
4. Real-world abstraction examples

Expected Output:
Abstract classes preventing direct instantiation
Interface contracts enforced through pure virtual functions
Implementation details hidden from users
*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
using namespace std;

// ==============================================
// 1. BASIC ABSTRACTION WITH ABSTRACT CLASSES
// ==============================================

// Abstract base class for database operations
class Database
{
protected:
    string connectionString;
    bool isConnected;

public:
    Database(string connStr) : connectionString(connStr), isConnected(false)
    {
        cout << "Database base constructor called" << endl;
    }

    // Pure virtual functions - define interface contract
    virtual bool connect() = 0;
    virtual bool disconnect() = 0;
    virtual bool executeQuery(const string &query) = 0;
    virtual vector<string> fetchResults() = 0;
    virtual bool insertRecord(const string &table, const vector<string> &data) = 0;

    // Concrete method (implementation provided)
    virtual bool isConnectionActive()
    {
        return isConnected;
    }

    // Abstract classes can have regular methods
    void printConnectionInfo()
    {
        cout << "Connection String: " << connectionString << endl;
        cout << "Status: " << (isConnected ? "Connected" : "Disconnected") << endl;
    }

    virtual ~Database()
    {
        cout << "Database destructor called" << endl;
    }
};

// Concrete implementation for MySQL
class MySQLDatabase : public Database
{
private:
    string serverVersion;
    vector<string> queryResults;

public:
    MySQLDatabase(string connStr, string version)
        : Database(connStr), serverVersion(version)
    {
        cout << "MySQL Database created" << endl;
    }

    bool connect() override
    {
        cout << "Connecting to MySQL server..." << endl;
        // Simulate connection logic
        isConnected = true;
        cout << "Connected to MySQL " << serverVersion << endl;
        return true;
    }

    bool disconnect() override
    {
        cout << "Disconnecting from MySQL server..." << endl;
        isConnected = false;
        queryResults.clear();
        cout << "Disconnected from MySQL" << endl;
        return true;
    }

    bool executeQuery(const string &query) override
    {
        if (!isConnected)
        {
            cout << "Error: Not connected to database" << endl;
            return false;
        }

        cout << "Executing MySQL query: " << query << endl;

        // Simulate query execution and results
        queryResults.clear();
        if (query.find("SELECT") != string::npos)
        {
            queryResults = {"John,25,Engineer", "Alice,30,Manager", "Bob,28,Developer"};
        }

        cout << "Query executed successfully" << endl;
        return true;
    }

    vector<string> fetchResults() override
    {
        return queryResults;
    }

    bool insertRecord(const string &table, const vector<string> &data) override
    {
        if (!isConnected)
            return false;

        cout << "Inserting into MySQL table '" << table << "': ";
        for (const auto &field : data)
        {
            cout << field << " ";
        }
        cout << endl;
        return true;
    }

    ~MySQLDatabase()
    {
        cout << "MySQL Database destroyed" << endl;
    }
};

// Another concrete implementation for PostgreSQL
class PostgreSQLDatabase : public Database
{
private:
    int maxConnections;
    vector<string> queryResults;

public:
    PostgreSQLDatabase(string connStr, int maxConn)
        : Database(connStr), maxConnections(maxConn)
    {
        cout << "PostgreSQL Database created" << endl;
    }

    bool connect() override
    {
        cout << "Connecting to PostgreSQL server..." << endl;
        isConnected = true;
        cout << "Connected to PostgreSQL (Max connections: " << maxConnections << ")" << endl;
        return true;
    }

    bool disconnect() override
    {
        cout << "Disconnecting from PostgreSQL server..." << endl;
        isConnected = false;
        queryResults.clear();
        cout << "Disconnected from PostgreSQL" << endl;
        return true;
    }

    bool executeQuery(const string &query) override
    {
        if (!isConnected)
            return false;

        cout << "Executing PostgreSQL query: " << query << endl;
        queryResults.clear();
        if (query.find("SELECT") != string::npos)
        {
            queryResults = {"Jane,27,Designer", "Mike,32,Architect"};
        }
        cout << "Query executed with PostgreSQL optimizations" << endl;
        return true;
    }

    vector<string> fetchResults() override
    {
        return queryResults;
    }

    bool insertRecord(const string &table, const vector<string> &data) override
    {
        if (!isConnected)
            return false;

        cout << "Inserting into PostgreSQL table '" << table << "' with ACID compliance: ";
        for (const auto &field : data)
        {
            cout << field << " ";
        }
        cout << endl;
        return true;
    }

    ~PostgreSQLDatabase()
    {
        cout << "PostgreSQL Database destroyed" << endl;
    }
};

// ==============================================
// 2. INTERFACE ABSTRACTION
// ==============================================

// Pure abstract class (Interface) for file operations
class FileHandler
{
public:
    // Pure virtual functions - interface contract
    virtual bool openFile(const string &filename) = 0;
    virtual bool closeFile() = 0;
    virtual string readContent() = 0;
    virtual bool writeContent(const string &content) = 0;
    virtual bool deleteFile() = 0;
    virtual long getFileSize() = 0;

    virtual ~FileHandler() = default;
};

// Concrete implementation for text files
class TextFileHandler : public FileHandler
{
private:
    string filename;
    bool isOpen;
    string content;

public:
    TextFileHandler() : isOpen(false)
    {
        cout << "TextFileHandler created" << endl;
    }

    bool openFile(const string &fname) override
    {
        filename = fname;
        isOpen = true;
        cout << "Opened text file: " << filename << endl;

        // Simulate reading file content
        content = "This is sample text file content.\nLine 2 of the file.\nEnd of file.";
        return true;
    }

    bool closeFile() override
    {
        if (isOpen)
        {
            cout << "Closed text file: " << filename << endl;
            isOpen = false;
            return true;
        }
        return false;
    }

    string readContent() override
    {
        if (!isOpen)
            return "";
        cout << "Reading text file content..." << endl;
        return content;
    }

    bool writeContent(const string &newContent) override
    {
        if (!isOpen)
            return false;
        content = newContent;
        cout << "Written content to text file: " << filename << endl;
        return true;
    }

    bool deleteFile() override
    {
        cout << "Deleted text file: " << filename << endl;
        isOpen = false;
        content.clear();
        return true;
    }

    long getFileSize() override
    {
        return isOpen ? content.length() : 0;
    }

    ~TextFileHandler()
    {
        cout << "TextFileHandler destroyed" << endl;
    }
};

// Another implementation for binary files
class BinaryFileHandler : public FileHandler
{
private:
    string filename;
    bool isOpen;
    vector<unsigned char> binaryData;

public:
    BinaryFileHandler() : isOpen(false)
    {
        cout << "BinaryFileHandler created" << endl;
    }

    bool openFile(const string &fname) override
    {
        filename = fname;
        isOpen = true;
        cout << "Opened binary file: " << filename << endl;

        // Simulate binary data
        binaryData = {0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x00}; // "Hello\0"
        return true;
    }

    bool closeFile() override
    {
        if (isOpen)
        {
            cout << "Closed binary file: " << filename << endl;
            isOpen = false;
            return true;
        }
        return false;
    }

    string readContent() override
    {
        if (!isOpen)
            return "";
        cout << "Reading binary file content..." << endl;

        string result = "Binary data: ";
        for (auto byte : binaryData)
        {
            result += to_string(byte) + " ";
        }
        return result;
    }

    bool writeContent(const string &content) override
    {
        if (!isOpen)
            return false;
        binaryData.clear();
        for (char c : content)
        {
            binaryData.push_back(static_cast<unsigned char>(c));
        }
        cout << "Written binary data to file: " << filename << endl;
        return true;
    }

    bool deleteFile() override
    {
        cout << "Deleted binary file: " << filename << endl;
        isOpen = false;
        binaryData.clear();
        return true;
    }

    long getFileSize() override
    {
        return isOpen ? binaryData.size() : 0;
    }

    ~BinaryFileHandler()
    {
        cout << "BinaryFileHandler destroyed" << endl;
    }
};

// ==============================================
// 3. REAL-WORLD ABSTRACTION EXAMPLE
// ==============================================

// Abstract Payment Processing System
class PaymentProcessor
{
protected:
    double amount;
    string currency;
    string transactionId;

public:
    PaymentProcessor(double amt, const string &curr)
        : amount(amt), currency(curr)
    {
        transactionId = "TXN" + to_string(rand() % 10000);
    }

    // Pure virtual functions
    virtual bool validatePayment() = 0;
    virtual bool processPayment() = 0;
    virtual bool refundPayment() = 0;
    virtual string getPaymentStatus() = 0;

    // Concrete helper methods
    void displayTransactionInfo()
    {
        cout << "Transaction ID: " << transactionId << endl;
        cout << "Amount: " << amount << " " << currency << endl;
    }

    virtual ~PaymentProcessor() = default;
};

// Credit Card Implementation
class CreditCardProcessor : public PaymentProcessor
{
private:
    string cardNumber;
    string expiryDate;
    string cvv;
    bool isProcessed;

public:
    CreditCardProcessor(double amt, const string &curr, const string &cardNum,
                        const string &expiry, const string &cvvCode)
        : PaymentProcessor(amt, curr), cardNumber(cardNum), expiryDate(expiry),
          cvv(cvvCode), isProcessed(false)
    {
        cout << "Credit Card Processor initialized" << endl;
    }

    bool validatePayment() override
    {
        cout << "Validating credit card..." << endl;

        // Simulate validation logic
        if (cardNumber.length() != 16)
        {
            cout << "Invalid card number length" << endl;
            return false;
        }

        if (cvv.length() != 3)
        {
            cout << "Invalid CVV" << endl;
            return false;
        }

        cout << "Credit card validation successful" << endl;
        return true;
    }

    bool processPayment() override
    {
        if (!validatePayment())
            return false;

        cout << "Processing credit card payment..." << endl;
        cout << "Contacting credit card network..." << endl;
        cout << "Payment authorized and processed" << endl;

        isProcessed = true;
        return true;
    }

    bool refundPayment() override
    {
        if (!isProcessed)
        {
            cout << "No payment to refund" << endl;
            return false;
        }

        cout << "Processing credit card refund..." << endl;
        cout << "Refund initiated, will appear in 3-5 business days" << endl;
        return true;
    }

    string getPaymentStatus() override
    {
        return isProcessed ? "Completed" : "Pending";
    }
};

// PayPal Implementation
class PayPalProcessor : public PaymentProcessor
{
private:
    string email;
    string password;
    bool isLoggedIn;
    bool isProcessed;

public:
    PayPalProcessor(double amt, const string &curr, const string &userEmail,
                    const string &userPassword)
        : PaymentProcessor(amt, curr), email(userEmail), password(userPassword),
          isLoggedIn(false), isProcessed(false)
    {
        cout << "PayPal Processor initialized" << endl;
    }

    bool validatePayment() override
    {
        cout << "Validating PayPal account..." << endl;

        // Simulate login
        if (email.find("@") == string::npos)
        {
            cout << "Invalid email format" << endl;
            return false;
        }

        cout << "Logging into PayPal..." << endl;
        isLoggedIn = true;
        cout << "PayPal validation successful" << endl;
        return true;
    }

    bool processPayment() override
    {
        if (!validatePayment())
            return false;

        cout << "Processing PayPal payment..." << endl;
        cout << "Connecting to PayPal servers..." << endl;
        cout << "Payment processed through PayPal" << endl;

        isProcessed = true;
        return true;
    }

    bool refundPayment() override
    {
        if (!isProcessed)
            return false;

        cout << "Processing PayPal refund..." << endl;
        cout << "Refund completed instantly to PayPal balance" << endl;
        return true;
    }

    string getPaymentStatus() override
    {
        return isProcessed ? "Completed" : "Pending";
    }
};

// ==============================================
// ABSTRACTION UTILITY FUNCTIONS
// ==============================================

// Function that works with any database implementation
void performDatabaseOperations(Database *db)
{
    cout << "\n--- Database Operations ---" << endl;

    db->printConnectionInfo();

    if (db->connect())
    {
        db->executeQuery("SELECT * FROM users");

        vector<string> results = db->fetchResults();
        cout << "Query Results:" << endl;
        for (const auto &row : results)
        {
            cout << "  " << row << endl;
        }

        vector<string> newRecord = {"Charlie", "35", "Analyst"};
        db->insertRecord("users", newRecord);

        db->disconnect();
    }
}

// Function that works with any file handler
void performFileOperations(FileHandler *handler, const string &filename)
{
    cout << "\n--- File Operations ---" << endl;

    if (handler->openFile(filename))
    {
        cout << "File size: " << handler->getFileSize() << " bytes" << endl;

        string content = handler->readContent();
        cout << "Current content: " << content << endl;

        handler->writeContent("New content added through abstraction!");
        cout << "New file size: " << handler->getFileSize() << " bytes" << endl;

        handler->closeFile();
    }
}

// Function that works with any payment processor
void processPayment(PaymentProcessor *processor)
{
    cout << "\n--- Payment Processing ---" << endl;

    processor->displayTransactionInfo();

    if (processor->processPayment())
    {
        cout << "Payment Status: " << processor->getPaymentStatus() << endl;

        // Simulate refund scenario
        cout << "\nInitiating refund..." << endl;
        processor->refundPayment();
    }
}

int main()
{
    cout << "=== ABSTRACTION DEMONSTRATION ===" << endl;

    // 1. Database Abstraction
    cout << "\n=== 1. DATABASE ABSTRACTION ===" << endl;

    unique_ptr<Database> mysqlDb = make_unique<MySQLDatabase>("mysql://localhost:3306", "8.0");
    unique_ptr<Database> postgresDb = make_unique<PostgreSQLDatabase>("postgres://localhost:5432", 100);

    performDatabaseOperations(mysqlDb.get());
    performDatabaseOperations(postgresDb.get());

    // 2. File Handler Abstraction
    cout << "\n=== 2. FILE HANDLER ABSTRACTION ===" << endl;

    unique_ptr<FileHandler> textHandler = make_unique<TextFileHandler>();
    unique_ptr<FileHandler> binaryHandler = make_unique<BinaryFileHandler>();

    performFileOperations(textHandler.get(), "document.txt");
    performFileOperations(binaryHandler.get(), "data.bin");

    // 3. Payment Processing Abstraction
    cout << "\n=== 3. PAYMENT PROCESSING ABSTRACTION ===" << endl;

    unique_ptr<PaymentProcessor> creditCard =
        make_unique<CreditCardProcessor>(99.99, "USD", "1234567890123456", "12/25", "123");

    unique_ptr<PaymentProcessor> paypal =
        make_unique<PayPalProcessor>(49.99, "USD", "user@example.com", "password123");

    processPayment(creditCard.get());
    processPayment(paypal.get());

    // 4. Demonstrate that abstract classes cannot be instantiated
    cout << "\n=== 4. ABSTRACT CLASS INSTANTIATION TEST ===" << endl;
    cout << "The following would cause compilation errors:" << endl;
    cout << "// Database db;              // ERROR: Cannot instantiate abstract class" << endl;
    cout << "// FileHandler fh;           // ERROR: Cannot instantiate abstract class" << endl;
    cout << "// PaymentProcessor pp;      // ERROR: Cannot instantiate abstract class" << endl;

    cout << "\n=== Program Ending ===" << endl;
    return 0;
}

/*
ABSTRACTION SUMMARY:

1. WHAT IS ABSTRACTION:
   - Hiding implementation details while showing only functionality
   - Providing a simplified interface to complex systems
   - Focusing on WHAT an object does, not HOW it does it

2. IMPLEMENTATION METHODS:

   a) ABSTRACT CLASSES:
   - Classes with one or more pure virtual functions
   - Cannot be instantiated directly
   - Provide partial implementation and interface contract
   - Used as base classes for concrete implementations

   b) PURE VIRTUAL FUNCTIONS:
   - virtual function() = 0;
   - Must be implemented in derived classes
   - Define interface contracts
   - Make containing class abstract

3. BENEFITS OF ABSTRACTION:

   - SIMPLIFIED INTERFACE: Users don't need to know implementation details
   - FLEXIBILITY: Can change implementation without affecting client code
   - MAINTAINABILITY: Implementation changes don't break existing code
   - POLYMORPHISM: Different implementations through same interface
   - MODULARITY: Clear separation between interface and implementation

4. REAL-WORLD EXAMPLES:

   - Database Connections: Different databases, same interface
   - File Operations: Text/Binary files, same operations
   - Payment Processing: Credit Card/PayPal, same workflow
   - Graphics APIs: DirectX/OpenGL, same drawing functions

5. DESIGN PATTERNS USING ABSTRACTION:

   - Strategy Pattern: Different algorithms, same interface
   - Template Method: Common workflow, variable steps
   - Factory Pattern: Create objects through abstract interface
   - Observer Pattern: Abstract notification system

6. LEVELS OF ABSTRACTION:

   - DATA ABSTRACTION: Hide internal data representation
   - PROCEDURAL ABSTRACTION: Hide algorithm implementation
   - OBJECT ABSTRACTION: Hide object internals, show interface

7. ABSTRACTION vs OTHER CONCEPTS:

   - ENCAPSULATION: Data hiding within a class
   - ABSTRACTION: Hiding complexity, showing essential features
   - INHERITANCE: Code reuse and IS-A relationships
   - POLYMORPHISM: Multiple forms through same interface

BEST PRACTICES:

1. Design abstract interfaces before concrete implementations
2. Keep abstract interfaces stable and minimal
3. Use pure virtual functions for contracts that must be implemented
4. Provide virtual destructors in abstract base classes
5. Consider using interfaces (pure abstract classes) for maximum flexibility

COMMON MISTAKES:

1. Making abstract classes too complex
2. Changing abstract interfaces frequently
3. Not making destructor virtual in abstract classes
4. Exposing implementation details through interface
5. Creating abstractions that are too granular or too broad

PRACTICE EXERCISES:

1. Create a Media Player abstraction:
   - Abstract MediaPlayer class
   - Implementations: AudioPlayer, VideoPlayer, StreamingPlayer
   - Common interface: play(), pause(), stop(), seek()

2. Create a Logging System:
   - Abstract Logger class
   - Implementations: FileLogger, ConsoleLogger, DatabaseLogger
   - Common interface: log(), setLevel(), getLevel()

3. Create a Sorting Algorithm abstraction:
   - Abstract Sorter class
   - Implementations: QuickSort, MergeSort, BubbleSort
   - Common interface: sort(), compare(), swap()

4. Create a Network Protocol abstraction:
   - Abstract NetworkProtocol class
   - Implementations: HTTP, FTP, SMTP
   - Common interface: connect(), send(), receive(), disconnect()
*/
