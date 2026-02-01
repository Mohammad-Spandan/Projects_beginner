#include <iostream>
using namespace std;

int main()
{
    double num1, num2, result;
    char operation;
    char choice;

    cout << "=== Simple Continuous Calculator ===\n";

    do {
        cout << "\nEnter first number: ";
        cin >> num1;

        cout << "Enter an operator (+, -, *, /): ";
        cin >> operation;

        cout << "Enter second number: ";
        cin >> num2;

        switch(operation)
          {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if(num2 != 0) {
                    result = num1 / num2;
                } 
                else 
                {
                    cout << "Error! Division by zero.\n";
                    continue; 
                }
                break;
            default:
                cout << "Invalid operator!\n";
                continue; 
        }

        cout << "Result: " << result << endl;

        cout << "\nDo you want to perform another calculation? (y/n): ";
        cin >> choice;

    }
      while(choice == 'y' || choice == 'Y');

    cout << "Thank you for using the calculator!\n";

    return 0;
}
