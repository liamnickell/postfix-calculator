#include <iostream>
#include <string>
#include "PostfixCalculator.h"

using namespace std;

int main() {
    displayWelcome();

    string expression;
    getline(cin, expression);
    
    while(computeResult(expression)) {
        cout << "Enter your postfix expression, separated by spaces: ";
        getline(cin, expression);
    }

    return 0;
}
