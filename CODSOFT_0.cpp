#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char op;

    cout << "------Simple Calculator------\n";
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> num2;

    switch(op) {
        case '+':
            cout << "Result:The addition is: " << num1 + num2 << endl;
            break;

        case '-':
            cout << "Result:The subtraction is: " << num1 - num2 << endl;
            break;

        case '*':
            cout << "Result:The multiplication is: " << num1 * num2 << endl;
            break;

        case '/':
            if(num2 != 0)
                cout << "Result:The Division is :" << num1 / num2 << endl;
            else
                cout << "Error: Division by zero is not allowed." << endl;
            break;

        default:
            cout << "Error: Invalid operator." << endl;
    }

    return 0;
}
