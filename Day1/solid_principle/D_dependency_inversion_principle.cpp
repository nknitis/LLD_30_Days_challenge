#include <iostream>
using namespace std;

/*
   Dependency Inversion Principle (DIP):
   High-level modules should not depend on low-level modules.
   Both should depend on abstractions.
   Depend on abstractions, not on concrete implementations.
*/

// ============== BAD EXAMPLE ==============
// High-level module depends on low-level concrete modules
class MySQLDatabase_Bad {
public:
    void save(string data) {
        cout << "Saving to MySQL: " << data << "\n";
    }
};

class FileSystem_Bad {
public:
    void save(string data) {
        cout << "Saving to File: " << data << "\n";
    }
};

// UserService depends on concrete classes
class UserService_Bad {
private:
    MySQLDatabase_Bad* db;
    
public:
    UserService_Bad() {
        db = new MySQLDatabase_Bad();
    }
    
    void saveUser(string username) {
        db->save(username);  // Tightly coupled to MySQLDatabase
    }
    
    ~UserService_Bad() {
        delete db;
    }
};

// ============== GOOD EXAMPLE ==============
// Both depend on abstraction (interface)
class Database {
public:
    virtual void save(string data) = 0;
    virtual ~Database() {}
};

class MySQLDatabase_Good : public Database {
public:
    void save(string data) override {
        cout << "Saving to MySQL: " << data << "\n";
    }
};

class FileSystem_Good : public Database {
public:
    void save(string data) override {
        cout << "Saving to File: " << data << "\n";
    }
};

class MongoDB_Good : public Database {
public:
    void save(string data) override {
        cout << "Saving to MongoDB: " << data << "\n";
    }
};

// UserService depends on abstraction, not concrete classes
class UserService_Good {
private:
    Database* db;  // Depends on interface, not concrete class
    
public:
    UserService_Good(Database* database) : db(database) {}
    
    void saveUser(string username) {
        db->save(username);  // Works with any Database implementation
    }
    
    void setDatabase(Database* database) {
        db = database;  // Can easily switch databases
    }
};

int main() {
    cout << "========== BAD EXAMPLE ==========\n";
    UserService_Bad service_bad;
    service_bad.saveUser("John");
    // If we want to change to FileSystem, we must modify UserService_Bad!
    
    cout << "\n========== GOOD EXAMPLE ==========\n";
    
    // Using MySQL
    MySQLDatabase_Good mysql;
    UserService_Good service1(&mysql);
    service1.saveUser("John");
    
    // Switch to FileSystem without changing UserService_Good
    FileSystem_Good filedb;
    service1.setDatabase(&filedb);
    service1.saveUser("Jane");
    
    // Switch to MongoDB without changing UserService_Good
    MongoDB_Good mongodb;
    service1.setDatabase(&mongodb);
    service1.saveUser("Bob");
    
    cout << "\nBenefits of DIP:\n";
    cout << "1. Loose coupling between high-level and low-level modules\n";
    cout << "2. Easy to extend with new implementations\n";
    cout << "3. Easy to test with mock implementations\n";
    cout << "4. Following the Dependency Injection pattern\n";
    
    return 0;
}
