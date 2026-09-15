#include <iostream>
using namespace std;

int stack[5];
int top = -1;

void push()
{
    int value;

    if(top == 4)
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        cout << "Enter value: ";
        cin >> value;

        top++;
        stack[top] = value;

        cout << "Value pushed" << endl;
    }
}

void pop()
{
    if(top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Deleted value: " << stack[top] << endl;
        top--;
    }
}

void isEmpty()
{
    if(top == -1)
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;
}

void isFull()
{
    if(top == 4)
        cout << "Stack is full" << endl;
    else
        cout << "Stack is not full" << endl;
}

void peek()
{
    if(top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Top element: " << stack[top] << endl;
    }
}

void display()
{
    if(top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack elements: ";

        for(int i = top; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }

        cout << endl;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. isEmpty";
        cout << "\n4. isFull";
        cout << "\n5. Display";
        cout << "\n6. Peek";
        cout << "\n7. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                isEmpty();
                break;

            case 4:
                isFull();
                break;

            case 5:
                display();
                break;

            case 6:
                peek();
                break;

            case 7:
                cout << "Program ended" << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }

    } while(choice != 7);

    return 0;
}
