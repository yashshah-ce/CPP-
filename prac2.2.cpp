#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int roll;
    string name;
    int m1, m2, m3;
    float average;

    int validateMarks(int m) {
        if (m >= 0 && m <= 100)
            return m;
        else {
            cout << "Invalid marks! Setting to 0.\n";
            return 0;
        }
    }

public:

    Student() {
        roll = 0;
        name = "Test Student";
        m1 = m2 = m3 = 50;
        calculateAverage();
    }

    Student(int r, string n, int a, int b, int c) {
        roll = r;
        name = n;
        m1 = validateMarks(a);
        m2 = validateMarks(b);
        m3 = validateMarks(c);
        calculateAverage();
    }

    void calculateAverage() {
        average = (m1 + m2 + m3) / 3.0;
    }

    float getAverage() {
        return average;
    }

    string getGrade() {
        if (average >= 90) return "A";
        else if (average >= 75) return "B";
        else if (average >= 60) return "C";
        else if (average >= 40) return "D";
        else return "Fail";
    }

    void display() {
        cout << "\nRoll No: " << roll;
        cout << "\nName: " << name;
        cout << "\nMarks: " << m1 << ", " << m2 << ", " << m3;
        cout << "\nAverage: " << average;
        cout << "\nGrade: " << getGrade() << endl;
    }
};

int main() {

    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student s[100];

    for (int i = 0; i < n; i++) {
        int roll, m1, m2, m3;
        string name;

        cout << "\nEnter details for student " << i + 1 << endl;
        cout << "Roll No: ";
        cin >> roll;
        cout << "Name: ";
        cin >> name;
        cout << "Marks in 3 subjects: ";
        cin >> m1 >> m2 >> m3;

        s[i] = Student(roll, name, m1, m2, m3);
    }

    cout << "\n----- Student Records -----\n";

    float highest = 0;
    int topIndex = 0;

    for (int i = 0; i < n; i++) {
        s[i].display();

        if (s[i].getAverage() > highest) {
            highest = s[i].getAverage();
            topIndex = i;
        }
    }

    cout << "\n----- Highest Average -----\n";
    s[topIndex].display();

    return 0;
}
