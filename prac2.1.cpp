#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l = 1, double w = 1) {
        setDimensions(l, w);
    }

    void setDimensions(double l, double w) {
        if (l > 0 && w > 0) {
            length = l;
            width = w;
        } else {
            cout << "Invalid dimensions! Setting default (1,1)\n";
            length = 1;
            width = 1;
        }
    }

    double getLength() { return length; }
    double getWidth() { return width; }

    double area() {
        return length * width;
    }

    double perimeter() {
        return 2 * (length + width);
    }

    bool isSquare() {
        return length == width;
    }

    bool isLargerThan(Rectangle r) {
        return area() > r.area();
    }

    void display() {
        cout << "\nLength: " << length;
        cout << "\nWidth: " << width;
        cout << "\nArea: " << area();
        cout << "\nPerimeter: " << perimeter();
        if (isSquare())
            cout << "\nThis rectangle is a Square.";
        cout << "\n---------------------------\n";
    }
};

int main() {
    int n;

    cout << "Enter number of rectangles: ";
    cin >> n;

    Rectangle rect[n];

    for (int i = 0; i < n; i++) {
        double l, w;
        cout << "\nEnter length and width for rectangle " << i + 1 << ": ";
        cin >> l >> w;
        rect[i].setDimensions(l, w);
    }

    for (int i = 0; i < n; i++) {
        cout << "\nRectangle " << i + 1;
        rect[i].display();
    }

    if (n >= 2) {
        if (rect[0].isLargerThan(rect[1]))
            cout << "\nRectangle 1 has larger area than Rectangle 2\n";
        else
            cout << "\nRectangle 2 has larger or equal area than Rectangle 1\n";
    }

    return 0;
}
