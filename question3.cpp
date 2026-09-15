#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

bool isBalanced(const string& expression) {
    stack<char> s;
    unordered_map<char, char> matching_bracket = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } 
        else if (matching_bracket.count(ch)) {
            if (s.empty() || s.top() != matching_bracket[ch]) {
                return false;
            }
            s.pop();
        }
    }

    return s.empty();
}

int main() {
    string test_cases[] = {
        "{[()]}",
        "{[(])}",
        "((())",
        "a + (b * [c - d])"
    };

    for (const auto& expr : test_cases) {
        cout << "'" << expr << "': " 
             << (isBalanced(expr) ? "Balanced" : "Unbalanced") 
             << endl;
    }

    return 0;
}
