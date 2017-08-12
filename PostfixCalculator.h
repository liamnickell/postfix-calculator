#ifndef _postfixcalculator_h
#define _postfixcalculator_h

#include <stack>
#include <string>

void displayWelcome();
bool computeResult(const std::string& expression);
bool isDigits(const std::string& str);
void pushValue(const std::string& element, std::stack<double>& values);
void performOperation(const std::string& operation, std::stack<double>& values);

#endif
