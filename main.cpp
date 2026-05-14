
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

// Basic arithmetic operations
double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double mul(double a, double b) { return a * b; }
double divd(double a, double b) { 
    if (b == 0) {
        cout << "Error: division by zero!" << endl;
        return 0;
    }
    return a / b; 
}

// Advanced functions
double power(double a, double b) {
    double result = 1;
    for(int i = 0; i < b; i++) result *= a;
    return result;
}

double square_root(double a) {
    if (a < 0) {
        cout << "Error: square root of negative number!" << endl;
        return 0;
    }
    return sqrt(a);
}

// Calculate expression
double calculate(double x, double y, char op) {
    switch(op) {
        case '+': return add(x, y);
        case '-': return sub(x, y);
        case '*': return mul(x, y);
        case '/': return divd(x, y);
        case '^': return power(x, y);
        case 'r': return square_root(x);
        default: 
            cout << "Unknown operation!" << endl;
            return 0;
    }
}

// Show help
void showHelp() {
    cout << "\n=== SmartCalc v1.0 ===" << endl;
    cout << "Commands:" << endl;
    cout << "  number + number   - addition" << endl;
    cout << "  number - number   - subtraction" << endl;
    cout << "  number * number   - multiplication" << endl;
    cout << "  number / number   - division" << endl;
    cout << "  number ^ number   - power" << endl;
    cout << "  r number          - square root" << endl;
    cout << "  help              - show help" << endl;
    cout << "  exit              - exit" << endl;
    cout << "========================\n" << endl;
}

int main() {
    string input;
    double x, y;
    char op;
    

    cout << "Hello World!!!" << endl;

    cout << "SmartCalc v1.0" << endl;
    cout << "Type 'help' for help, 'exit' to quit\n" << endl;
    
    while(true) {
        cout << "> ";
        getline(cin, input);
        
        if(input == "exit") {
            cout << "Goodbye!" << endl;
            break;
        }
        
        if(input == "help") {
            showHelp();
            continue;
        }
        
        // For square root (r number)
        if(!input.empty() && input[0] == 'r') {
            try {
                x = stod(input.substr(2));
                cout << "Result: " << calculate(x, 0, 'r') << endl;
            } catch(...) {
                cout << "Error: invalid number" << endl;
            }
            continue;
        }
        
        // Parse: number operator number
        stringstream ss(input);
        if(ss >> x >> op >> y) {
            double result = calculate(x, y, op);
            cout << "Result: " << result << endl;
        } else {
            cout << "Error: invalid format. Type 'help' for help." << endl;
        }
    }
    
    return 0;
}

// Привет всем, кто читает 
// пу пу пу 
