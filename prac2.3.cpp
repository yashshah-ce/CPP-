#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string name;
    int id;
    double balance;

public:

    Account(string n, int i, double b = 0) {
        name = n;
        id = i;
        balance = (b >= 0) ? b : 0;
    }

    void deposit(double amount) {
        balance += (amount > 0) ? amount : 0;
        cout << (amount > 0 ? "Deposit Successful\n" : "Invalid Deposit\n");
    }

    void withdraw(double amount) {
        balance -= (amount > 0 && amount <= balance) ? amount : 0;
        cout << (amount > 0 && amount <= balance ?
                "Withdrawal Successful\n" :
                "Withdrawal Failed\n");
    }

    void display() {
        cout << "\nAccount Summary\n";
        cout << "Name: " << name << endl;
        cout << "Account ID: " << id << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {

    Account a1("Yash", 101, 1000);
    Account a2("Rahul", 102);
    Account a3("Priya", 103, 500);


    a1.deposit(200);
    a1.withdraw(1500);
    a1.withdraw(300);

    a2.deposit(400);
    a2.withdraw(100);

    a3.deposit(100);
    a3.withdraw(700);

    a1.display();
    a2.display();
    a3.display();

    return 0;
}
