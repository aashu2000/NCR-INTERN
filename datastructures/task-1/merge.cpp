// merge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* head = NULL;
Node* head1 = NULL;
void insert1(int val)
{
    Node* temp = head;
    Node* newnode = new Node;
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;

    }
    else {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void insert2(int val)
{
    Node* temp = head1;
    Node* newnode = new Node;
    newnode->data = val;
    newnode->next = NULL;
    if (head1 == NULL)
    {
        //newnode->next = NULL;
        head1 = newnode;

    }
    else {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        //newnode->data = val;
        //newnode->next = NULL;
        temp->next = newnode;
    }
}
void display1()
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void display2()
{
    Node* temp = head1;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void merger(int p)
{
    Node* temp = head;
    Node* temp1 = head;
    int c = 0;
    while (temp != NULL)
    {
        temp1 = temp1->next;//to point to next elements after position p in linked list
        c++;
        if (c == p)
        {
            break;
        }
        temp = temp->next;//this pointer will pointed to that specified position
       // temp1 = temp1->next;

    }
   // Node* temp1 = temp->next;
    temp->next = head1;//linking list1 with head of list 2
   // cout << temp1->data << " " << temp1->next->data;
    while (temp->next!= NULL)
    {
        //cout << temp->data << endl;
        temp = temp->next;//traversing till the end after concatenating
    }
    temp->next = temp1;//joining the remaining elements of list1 with concatenated list
    

    

    display1();

}

int main()
{
    int ch = 5, val;
    cout << "elements of list 1" << endl;
    while (ch != 0)
    {
        cin >> val;
        insert1(val);
        ch = ch - 1;
    }
    display1();
    ch = 5;
    cout << "elements of list 2" << endl;
    while (ch != 0)
    {
        cin >> val;
        insert2(val);
        ch = ch - 1;
    }
    display2();
    cout << "enter the position of list1 to be concatenated with list2" << endl;
    int k;
    cin >> k;
    merger(k);

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
