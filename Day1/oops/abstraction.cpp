class Vehicle { 
public:
    virtual void startEngine() = 0; 
};

class Car : public Vehicle {
public:
    void startEngine() override {  }
};