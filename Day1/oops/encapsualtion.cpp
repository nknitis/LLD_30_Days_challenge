class Account {
private:
    double balance; 

public:
    void deposit(double amount) { 
        if(amount > 0) balance += amount; 
    }
    double getBalance() const { return balance; } 
};