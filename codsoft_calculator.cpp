#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char operation;

    cout << "==============================" << endl;
    cout << "    Welcome to My Calculator  " << endl;
    cout << "==============================" << endl;

    // Take input from user
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    // Ask which operation to perform
    cout << "Select operation (+, -, *, /): ";
    cin >> operation;

    cout << "------------------------------" << endl;

    // Perform calculation based on selected operation
    if (operation == '+') {
        result = num1 + num2;
        cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
    }
    else if (operation == '-') {
        result = num1 - num2;
        cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
    }
    else if (operation == '*') {
        result = num1 * num2;
        cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
    }
    else if (operation == '/') {
        if (num2 != 0) {
            result = num1 / num2;
            cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
        } else {
            cout << "Error: Division by zero is not allowed." << endl;
        }
    }
    else {
        cout << "Invalid operation! Please run again and choose from +, -, *, /." << endl;
    }

    cout << "==============================" << endl;
    cout << "       Thank you for using    " << endl;
    cout << "==============================" << endl;

    return 0;
}
