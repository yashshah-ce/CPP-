#include <iostream>
#include <cmath>
using namespace std;

class Loan
{
    int loanID, months;
    string name;
    double amount, annualRate;

public:

    Loan() : loanID(0), name("Unknown"), amount(0), annualRate(0), months(0) {}

    Loan(int id, string n, double amt, double rate, int m)
    {
        loanID = id;
        name = n;
        amount = amt;
        annualRate = rate;
        months = m;
    }

    double calculateEMI()
    {
        double R = annualRate / (12 * 100);
        double T = months;

        return (amount * R * pow(1 + R, T)) /
               (pow(1 + R, T) - 1);
    }


    void display()
    {
        cout << "\nLoan ID: " << loanID
             << "\nName: " << name
             << "\nAmount: " << amount
             << "\nInterest Rate: " << annualRate
             << "\nMonths: " << months
             << "\nEMI: " << calculateEMI() << endl;
    }
};

int main() {
    Loan l1;
    Loan l2(101, "Yash", 50000, 10, 12); // parameterized

    cout << "Default Loan:";
    l1.display();

    cout << "\n\nParameterized Loan:";
    l2.display();

    return 0;
}
