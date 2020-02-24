// stack1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* top = NULL;
void push(int val) {
    Node* newnode = new Node;
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}
void pop()
{
    if (top == NULL)
    {
        cout << "Underflow" << endl;
    }
    else
    {
        cout << "Popped element is:" << top->data << endl;
        top = top->next;
    }
}
void display()
{
    if (top == NULL)
    {
        cout << "stack empty" << endl;
    }
    else
    {
        Node* p = top;
        while (p != NULL)
        {
            cout << p->data << " ";
            p=p->next;
        }
        cout << endl;
    }
}

int main()
{
    int val;
    char ch;
    cout << "a) Push into the stack "<<endl;
    cout << "b) Pop from the stack " << endl;
    cout << "c) Display stack " << endl;
    cout << "d) Exit " << endl;
    do {
        cout << "Enter your choice:" << endl;
        cin >> ch;
        switch (ch)
        {
        case 'a': {
            cout << "enter the value to be pushed" << endl;
            cin >> val;
            push(val);
            break;
        }
        case 'b': {
            pop();
            break;
        }
        case 'c': {
            display();
            break;
        }
        case 'd': {
            cout << "Exit" << endl;
            break;
        }
        default: {
            cout << "Invalid choice" << endl;
        }
        }
    } while (ch != 'd');
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
