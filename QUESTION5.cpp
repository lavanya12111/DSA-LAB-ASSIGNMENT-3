#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

int evaluatePostfix(const string& expression) {
    stack<int> s;

    for (int i = 0; i < expression.length(); i++) {
        // Skip whitespace characters
        if (expression[i] == ' ') continue;

        // If character is a digit, handle multi-digit numbers
        if (isdigit(expression[i])) {
            int num = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--; // Adjust index due to outer loop increment
            s.push(num);
        }
        // If character is an operator, pop two operands
        else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();

            switch (expression[i]) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': s.push(pow(val1, val2)); break;
            }
        }
    }

    return s.top();
}

int main() {
    string expressions[] = {
        "2 3 1 * + 9 -",          // Equivalent to 2 + (3 * 1) - 9 = -4
        "100 200 + 2 / 5 * 7 +",   // Equivalent to ((100 + 200) / 2) * 5 + 7 = 757
        "2 3 2 ^ ^"                // Equivalent to 2 ^ (3 ^ 2) = 512
    };

    for (const auto& expr : expressions) {
        cout << "Postfix: " << expr << "\n";
        cout << "Result:  " << evaluatePostfix(expr) << "\n\n";
    }

    return 0;
}
