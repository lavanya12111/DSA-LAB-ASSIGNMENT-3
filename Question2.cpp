#include <iostream>
using namespace std;

char stack[100];
int top = -1;

void push(char ch)
{
    top++;
    stack[top] = ch;
}

char pop()
{
    char ch = stack[top];
    top--;
    return ch;
}

int main()
{
    string str;

    cout << "Enter a string: ";
    cin >> str;

    // Push each character into stack
    for(int i = 0; i < str.length(); i++)
    {
        push(str[i]);
    }

    cout << "Reversed string: ";

    // Pop characters from stack
    while(top != -1)
    {
        cout << pop();
    }

    cout << endl;

    return 0;
}
