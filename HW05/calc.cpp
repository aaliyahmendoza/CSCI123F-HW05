
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

// funct prototypes for operators
int add(int num1, int num2);
int subtract(int num1, int num2);
int multiply(int num1, int num2);
int divide(int num1, int num2, int& remainder);

int main() {
    // answer = char (either 'Y', 'y', 'N', or 'n')
    char answer;

    do { // to bring user back -> program if 'y' = chosen
        int num1, num2;
        cout << "Please enter two integer values separated by whitespace: ";
        cin >> num1 >> num2;

        cout << "\nHere are the results: \n";

        // funct operators
        int sum = add(num1, num2);
        int difference = subtract(num1, num2);
        int multiplication = multiply(num1, num2);
        int division, modulos;

        // check if dividing by zero
        // if != 0, print all operations
        if (num2 != 0) {
            division = divide(num1, num2, modulos);
            cout << num1 << " + " << num2 << " = " << sum << endl;
            cout << num1 << " - " << num2 << " = " << difference << endl;
            cout << num1 << " * " << num2 << " = " << multiplication << endl;
            cout << num1 << " / " << num2 << " = " << division << " with a remainder of " << modulos << endl;
        } else { // if num2 == 0, it's und...
            cout << num1 << " + " << num2 << " = " << sum << endl;
            cout << num1 << " - " << num2 << " = " << difference << endl;
            cout << num1 << " * " << num2 << " = " << multiplication << endl;
            cout << "Division by zero is undefined..." << endl;
        }
        // prompt user option (Y/N)
        cout << "\nWould you like to try different numbers (Y/N)? ";
        cin >> answer; // answer = char

        // while loop -> if != specified char(s), INVALID
        while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n') {
            cout << "Invalid input, please type (Y/N): ";
            cin >> answer;
        }
    
    } while (answer == 'Y' || answer == 'y'); // if 'Y', this will prompt user back to 
                                              // beginning of program (enter 2 nums)

    if (answer == 'N' || answer == 'n') {
        // exit the program if ans = 'N'
        return 0;
    }
}

// funct for operators 
int add(int num1, int num2) {
    return num1 + num2;
}

int subtract(int num1, int num2) {
    return num1 - num2;
}

int multiply(int num1, int num2) {
    return num1 * num2;
}

int divide(int num1, int num2, int& remainder) {
    remainder = num1 % num2;
    return num1 / num2;
}
