#include <iostream>
using namespace std;

/* 
   Interface Segregation Principle (ISP):
   Clients should not be forced to depend on interfaces they do not use.
   Instead of one big interface, create smaller, specific interfaces.
*/

// ============== BAD EXAMPLE ==============
// One large interface that forces implementation of unwanted methods
class Worker_Bad {
public:
    virtual void work() = 0;
    virtual void eat() = 0;  // Robot doesn't need to eat!
    virtual ~Worker_Bad() {}
};

class Human_Bad : public Worker_Bad {
public:
    void work() override {
        cout << "Human is working\n";
    }
    void eat() override {
        cout << "Human is eating\n";
    }
};

class Robot_Bad : public Worker_Bad {
public:
    void work() override {
        cout << "Robot is working\n";
    }
    void eat() override {
        // Robot doesn't eat, but forced to implement!
        cout << "Robot cannot eat\n";
    }
};

// ============== GOOD EXAMPLE ==============
// Segregated, specific interfaces
class Workable {
public:
    virtual void work() = 0;
    virtual ~Workable() {}
};

class Eatable {
public:
    virtual void eat() = 0;
    virtual ~Eatable() {}
};

class Human_Good : public Workable, public Eatable {
public:
    void work() override {
        cout << "Human is working\n";
    }
    void eat() override {
        cout << "Human is eating\n";
    }
};

class Robot_Good : public Workable {
public:
    void work() override {
        cout << "Robot is working\n";
    }
};

int main() {
    cout << "========== BAD EXAMPLE ==========\n";
    Robot_Bad robot_bad;
    robot_bad.work();
    robot_bad.eat();  // Forced to implement even though robots don't eat
    
    cout << "\n========== GOOD EXAMPLE ==========\n";
    Robot_Good robot_good;
    robot_good.work();  // Only implements what it needs
    
    Human_Good human;
    human.work();
    human.eat();
    
    return 0;
}
