// As Name Stand Single work in single class


// wrong way 
#include <bits/stdc++.h>
using namespace std;
class monetory{
public:
void Upi(){
    cout<<"payment by upi";
}
void Billcalculate(int x){
    cout<<x<<" item " <<" price - 10 " << "toatal price = "<<x*10<<endl;
}
};


//  right way is to give one responsbilty to one class

class Payment{
    public:
    void Upi(){
    cout<<"payment by upi";
}
};
class invoice{
    public:
void Billcalculate(int x){
    cout<<x<<" item " <<" price - 10 " << "toatal price = "<<x*10<<endl;
}
};
int main(){
    monetory p;
    p.Billcalculate(5);
    p.Upi();

    Payment u;
    u.Upi();
    return 0;
}

