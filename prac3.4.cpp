#include <iostream>
using namespace std;

template <class T>
T findMax(T arr[], int n)
{
    T max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

template <class T>
void reverseArray(T arr[], int n)
{
    for (int i = 0; i < n / 2; i++) {
        T temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

template <class T>
void display(T arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;

    cout << "Enter size: ";
    cin >> n;

    int arr[100];

    cout << "Enter elements (int): ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nArray: ";
    display(arr, n);

    cout << "Maximum: " << findMax(arr, n) << endl;

    reverseArray(arr, n);

    cout << "Reversed Array: ";
    display(arr, n);

    return 0;
}
