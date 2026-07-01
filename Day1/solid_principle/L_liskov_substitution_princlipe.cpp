// wrong method

#include <iostream>
#include <vector>

class Account {
public:
    virtual ~Account() = default;
    virtual void withdraw(double amount) = 0;
};

class SavingsAccount : public Account {
private:
    double balance = 500.0;
public:
    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
        }
    }
};

class FixedDepositAccount : public Account {
private:
    double balance = 10000.0;
public:
    void withdraw(double amount) override {
        throw std::runtime_error("Cannot withdraw from Fixed Deposit before maturity");
    }
};

void processWithdrawals(std::vector<Account*>& accounts) {
    for (Account* acc : accounts) {
        acc->withdraw(50.0); 
    }
}


// right 

#include <iostream>
#include <vector>

class Account {
public:
    virtual ~Account() = default;
    virtual bool canWithdraw(double amount) const = 0;
    virtual void withdraw(double amount) = 0;
};

class SavingsAccount : public Account {
private:
    double balance = 500.0;
public:
    bool canWithdraw(double amount) const override {
        return amount <= balance;
    }
    void withdraw(double amount) override {
        if (canWithdraw(amount)) {
            balance -= amount;
        }
    }
};

class FixedDepositAccount : public Account {
private:
    double balance = 10000.0;
public:
    bool canWithdraw(double amount) const override {
        return false; 
    }
    void withdraw(double amount) override {
        if (canWithdraw(amount)) {
            balance -= amount;
        }
    }
};

void processWithdrawals(std::vector<Account*>& accounts) {
    for (Account* acc : accounts) {
        if (acc->canWithdraw(50.0)) {
            acc->withdraw(50.0);
        }
    }
}