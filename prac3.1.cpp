#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    double basicSalary, bonus;

public:
    // Constructor with default bonus
    Employee(string n = "", double b = 0, double bo = 1000)
        : name(n), basicSalary(b), bonus(bo) {}

    // Inline function
    inline double totalSalary() {
        return basicSalary + bonus;
    }

    // Display
    void display() {
        cout << "\nName: " << name
             << "\nBasic: " << basicSalary
             << "\nBonus: " << bonus
             << "\nTotal: " << totalSalary() << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    Employee* emp = new Employee[n];

    for (int i = 0; i < n; i++) {
        string name;
        double basic, bonus;

        cout << "\nEnter Name: ";
        cin >> name;
        cout << "Enter Basic Salary: ";
        cin >> basic;
        cout << "Enter Bonus (0 for default): ";
        cin >> bonus;

        // No if-else (using ternary)
        emp[i] = (bonus == 0) ? Employee(name, basic)
                             : Employee(name, basic, bonus);
    }

    cout << "\n--- Employee Details ---\n";

    for (int i = 0; i < n; i++)
        emp[i].display();

    delete[] emp;
    return 0;
}
