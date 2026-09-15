#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isRightAssociative(char op) {
    return op == '^';
}

string infixToPostfix(const string& infix) {
    string postfix = "";
    stack<char> s;

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } 
        else if (ch == '(') {
            s.push(ch);
        } 
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop();
        } 
        else {
            while (!s.empty() && s.top() != '(' &&
                  (precedence(s.top()) > precedence(ch) ||
                  (precedence(s.top()) == precedence(ch) && !isRightAssociative(ch)))) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string expressions[] = {
        "A+B*C",
        "(A+B)*C",
        "A+B*(C^D-E)",
        "a+b*(c^d-e)^(f+g*h)-i"
    };

    for (const auto& expr : expressions) {
        cout << "Infix:   " << expr << "\n";
        cout << "Postfix: " << infixToPostfix(expr) << "\n\n";
    }

    return 0;
}
