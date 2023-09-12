#include <iostream>
#include <cmath>
using namespace std;
double calculations(int number1, int number2, char Operation);
int main()
{
    system("cls");
    double number1, number2;
    char Operation;
    cout << "*********************************************************" << endl;
    cout << "**************Welcome to my Calculator*******************" << endl;
    cout << "*********************************************************" << endl
         << endl
         << endl;
    cout << "Calculate Me" << endl
         << endl;
    cout << "Enter First number in order to perform calculations   ";
    cin >> number1;
    cout << endl;
    cout << "Enter Second number in order to perform calculations   ";
    cin >> number2;
    cout << endl;
    cout << "Enter Operation in order to perform calculations on your numbers" << endl;
    cout << "Here are the list of the operations that you can use" << endl;
    cout << " + " << endl;
    cout << " - " << endl;
    cout << " x " << endl;
    cout << " / " << endl;
    cout << " % " << endl;
    cout << "Enter your choice : ";
    cin >> Operation;
    cout << endl;

    cout << "Your result is:"
         << calculations(number1, number2, Operation);
}
double calculations(int number1, int number2, char Operation)
{
    double result = 0;
    if (Operation == '+')
    {
        result = number1 + number2;
    }
    else if (Operation == '-')
    {
        result = number1 - number2;
    }
    else if (Operation == 'x')
    {
        result = number1 * number2;
    }
    else if (Operation == '/')
    {
        result = number1 / number2;
    }
    else if (Operation == '%')
    {
        result = number1 % number2;
    }
    return result;
}