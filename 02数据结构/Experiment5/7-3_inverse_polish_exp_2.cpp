#include <bits/stdc++.h>

int calculate_rpn(std::string expression) {
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*") {
            int num2 = stack.top(); stack.pop();
            int num1 = stack.top(); stack.pop();
            if (token == "+") stack.push(num1 + num2);
            else if (token == "-") stack.push(num1 - num2);
            else if (token == "*") stack.push(num1 * num2);
        } else {
            stack.push(std::stoi(token));
        }
    }
    return stack.top();
}

int main() {
    std::string expression;
    std::getline(std::cin, expression);
    std::cout << calculate_rpn(expression) << std::endl;
    return 0;
}