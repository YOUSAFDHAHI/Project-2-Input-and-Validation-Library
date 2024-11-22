#include <iostream>
#include "clsInputValidate.h"
using namespace std;

int main()
{
    cout << clsInputValidate::IsNumberBetween(5, 1, 10) << endl;
    cout << clsInputValidate::IsNumberBetween(5.5, 1.3, 10.8) << endl;
    cout << clsInputValidate::IsDateBetween(clsDate(), clsDate(30, 11, 2024), clsDate(5, 11, 2024)) << endl;

    cout << clsInputValidate::IsDateBetween(clsDate(), clsDate(5, 11, 2024), clsDate(30, 11, 2024)) << endl;

    cout << "\nPlease Enter a Number? \n";
    int x = clsInputValidate::ReadIntNumber("Invalid Number, enter again\n");
    cout << "x=" << x << endl;

    cout << "\nPlease Enter a Number between 1 and 5:\n";
    cout << clsInputValidate::ReadIntNumberBetween(1, 5, "\nNumber is NOT within range, enter again\n");

    cout << "\nPlease Enter a Double Number? \n";
    double a = clsInputValidate::ReadDblNumber("Invalid Number, enter again\n");
    cout << "a=" << a << endl;

    cout << "\nPlease Enter a Double Number between 1 and 5:\n";
    cout << clsInputValidate::ReadDblNumberBetween(1, 5, "\nNumber is NOT within range, enter again\n");

    cout << "\n"
         << clsInputValidate::IsValideDate(clsDate(33, 11, 2024));
}