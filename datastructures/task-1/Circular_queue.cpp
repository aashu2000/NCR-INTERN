// Circular_queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* front = NULL;
Node* rear = NULL;
static int n;
void enqueue(int val){
   Node* newnode = new Node;
   newnode->data = val;
   newnode->next = NULL;
   if (rear == NULL)
   {
       front = rear = newnode;
       rear->next = front;
   }
   else if (n==0)
   {
       cout << "Queue is full" << endl;
   }
   else
   {
       rear->next = newnode;
       rear = newnode;
       rear->next = front;
   }

}
void dequeue()
{
    Node* temp = front;
    if (front == NULL && rear == NULL)
    {
        cout << "UNDERFLOW" << endl;
    }
    else if (front == rear)
    {
        front = NULL;
        rear = NULL;
        delete(temp);
        n = n + 1;
    }
    else {
        front = front->next;
        rear->next = front;
        delete(temp);
        n = n + 1;
    }
}
void peek()
{
    if (rear == NULL && front == NULL)
    {
        cout << "UNDERFLOW" << endl;
    }
    else {
        cout << "Peek element is:" << front->data << endl;
    }
}
void display()
{
    Node* temp = front;
    if (rear == NULL && front == NULL)
    {
        cout << "UNDERFLOW" << endl;
    }
    else {
        while (temp->next != front)
        {
            cout << temp->data<<endl;
            temp = temp->next;
        }
        cout << temp->data << endl;
    }

}

int main()
{
    int ch, val;
    cout << "enter the no of elements to be in the queue" << endl;
    cin >> n;
    do {
        cout << "enter 1 to enqueue...enter 2 to dequeue...enter 3 to peek...enter 4 to display...enter 5 to quit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1: {
            while (n != 0) {
                cout << "enter the value" << endl;
                cin >> val;
                enqueue(val);
                n = n - 1;
            }
            //display();
            if (n == 0)
            {
                cout << "Queue is full" << endl;
            }
            break;
        }
        case 2: {
            cout << "dequeue operation" << endl;
            //n = n - 1;
            dequeue();
            break;
        }
        case 3:
        {
            cout << "peek operation" << endl;
            peek();
            break;
        }
        case 4:
        {
            cout << "displaying elements" << endl;
            display();
            break;
        }
        case 5:
        {
            cout << "exit" << endl;
            break;
        }
        default:
        {
            cout << "Invalid input" << endl;
        }
           
        }
    } while (ch != 5);
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
