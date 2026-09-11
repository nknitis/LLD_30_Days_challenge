#include <bits/stdc++.h>
using namespace std;
class automobile{
     virtual void start()=0;
};
class Car:public automobile{
    void start () override {
        cout<<"start";
    }
}
class Factory {
public:
    virtual unique_ptr<automobile> create() = 0;
};

class CarFactory : public Factory {
public:
    unique_ptr<> create() override {
        return make_unique<A>();
    }
};

class BCreator : public Creator {
public:
    unique_ptr<Product> create() override {
        return make_unique<B>();
    }
};
int main(){
    return 0;
}