#include <cctype>
#include <exception>
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include "PostfixCalculator.h"

using namespace std;

void displayWelcome() {
    cout << endl << "Welcome to the Postfix Calculator! Postfix expressions are written\n"
                    "such that operators come after the operands to which they apply. Use\n"
                    "\"+\" for addition, \"-\" for subtraction, \"*\" for multiplication,\n"
                    "and \"/\" for division. Enter to quit." << endl << endl;
    cout << "Enter your postfix expression, separated by spaces: ";
}

bool computeResult(const string& expression) {
    if(expression == "") {
        return false;
    }

    stack<double> values;
    istringstream expressionStream(expression);
    
    string element;
    while(expressionStream >> element) {
        if(element == "+" && values.size() >= 2) {
            performOperation("add", values);
        } else if(element == "-" && values.size() >= 2) {
            performOperation("sub", values);
        } else if(element == "*" && values.size() >= 2) {
            performOperation("mult", values);
        } else if(element == "/" && values.size() >= 2) {
            try {
                performOperation("div", values);
            } catch(string exception) {
                cout << exception << endl << endl;
                return true;
            }
        } else if(isDigits(element)) {
            pushValue(element, values);
        } else {
            cout << "Invalid postfix expression, please try again." << endl << endl;
            return true;
        }
    }

    if(values.size() != 1) {
        cout << "Invalid postfix expression, please try again." << endl << endl;
        return true;
    } else {
        cout << "Result: " << values.top() << endl << endl;
        return true;
    }
}

bool isDigits(const string& str) {
    return str.find_first_not_of("0123456789") == string::npos;
}

void pushValue(const string& value, stack<double>& values) {
    istringstream iss(value);
    
    double num;
    iss >> num;

    values.push(num);
}

void performOperation(const string& operation, stack<double>& values) {
    double firstNum = values.top();
    values.pop();
    
    double secondNum = values.top();
    values.pop();

    if(operation == "add") {
        values.push(secondNum + firstNum);
    } else if(operation == "sub") {
        values.push(secondNum - firstNum);
    } else if(operation == "mult") {
        values.push(secondNum * firstNum);
    } else if(operation == "div") {
        if(firstNum == 0) {
            string exception = "Can't divide by zero.";
            throw exception;
        }

        values.push(secondNum / firstNum);
    }
}
