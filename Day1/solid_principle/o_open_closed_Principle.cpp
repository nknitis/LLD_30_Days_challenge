// always open for extension -  kabhi bhi extend kar sakte h
// but baaaar baar edit  karne se baaki devloepsrs ko problem hoskat eh  islye modeifation k liye cloded so
// here we will use poly morphism


// wrong way - if we add more it will becoem heay in sinlge class and diifult read;
#include<bits/stdc++.h>
using namespace std;


class AreaCalculator {
public:
    void Payment(string method,int amount) {
        transform(method.begin(),method.end(),method.begin(),::tolower);
        if (method == "upi") cout<<"payment by  UPI";
        else if (method == "debit") cout<<"payment by debit";
        // Naya shape add karna ho to yaha if-else badhana padega
        return ;
    }
};




// right way

#include <bits/stdc++.h>
using namespace std;

class PaymentMethod {
public:
  
    virtual void processPayment(int amount) = 0; 
    virtual ~PaymentMethod() {} 
};


class UpiPayment : public PaymentMethod {
public:
    void processPayment(int amount) override {
        cout << "Payment of " << amount << " done by UPI." << endl;
    }
};


class DebitCardPayment : public PaymentMethod {
public:
    void processPayment(int amount) override {
        cout << "Payment of " << amount << " done by Debit Card." << endl;
    }
};



int main() {
  
    PaymentMethod* payment = nullptr;

    
    payment = new UpiPayment();
    payment->processPayment(500); 
    delete payment;


    return 0;
}