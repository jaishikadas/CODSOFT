#include <iostream>
using namespace std;
void base() {
    cout << "Simple Calculator" << endl << "-----------------" << endl;
    cout << "1. Addition" << endl << "2. Subtraction" << endl << "3. Multiplication" << endl << "4. Division" << endl << "5. Exit" << endl;
    cout << "Choose an operation: ";
}
int main() {
    int choice;
    double num1, num2, result;
    while (1) {
        base();
        cin >> choice;
        if (choice == 5) {
            cout << "Exiting the program." << endl;
            break;
        }
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;
        switch (choice) {
            case 1:result = num1 + num2;
                cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
                break;
            case 2:result = num1 - num2;
                cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
                break;
            case 3:result = num1 * num2;
                cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
                break;
            case 4:     if (num2 != 0) {
                            result = num1 / num2;
                            cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
                     }  else {
                            cout << "Error: Division by zero is not allowed." << endl;
                     }
                break;
            default:
                cout << "Invalid choice. Please choose a valid operation." << endl;
        }
    cout << endl;
    }
    return 0;
}
