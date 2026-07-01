class Base {
public:
    virtual void show() { cout << "Base\n"; } 
};

class Derived : public Base {
public:
    void show() override { cout << "Derived\n"; } 
};

// Usage:
Base* ptr = new Derived();
ptr->show(); 