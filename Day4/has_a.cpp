// in this relations ship  A claas contaion class B
// like car has a engine
//order has a payment
//home has a room

// /amazon   
// customer --addres,cart,orders

// has a-  aggreation,compostion aacosind to need ans couling needs
//  uses - a asscoation 
//compaostion -very strong
// aggregaton - strong
//assocaiton - very weak

// Engine engine;          // Composition

// Engine* engine;         // Aggregation / ownership depending on design

// Engine& engine;         // Association

// shared_ptr<Engine>      // Shared ownership

// unique_ptr<Engine>      // Exclusive ownership



#include<bits/stdc++.h>
using namespace std;
class Engine{
    public:
    void start(){
        cout<<"engines start\n";
    }
};
class Car {
    Engine E;
    public:
    void startCar(){
        cout<<"place the key"<<endl;
        E.start();
        cout<<"car started succesfully"<<endl;
        }
};
int main(){
    Car c;
    c.startCar();
    return 0;
}