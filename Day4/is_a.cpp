// is a realtions have soem common 
// 1 like they  ,child class is a type of parent class 
// 2 for exampel cat is animal, paytm is s type of payment,


#include<bits/stdc++.h>
using namespace std;

class animal {
    public:
void eat(){
    cout<<"eating "<<endl;
}
};
 

class Dog:public animal{
    public:
    void bark(){
    cout<<"barking"<<endl;
    }
};
int main(){
    Dog d;
    d.eat();
    d.bark();
return 0;
}


// strogest type of relationship
