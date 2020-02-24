// sort_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//self adjusting linked list

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
struct Node* head=NULL;
struct Node* head1 = NULL;
void insert1(int val)
{
    Node* temp = head;
    Node* newnode = new Node;
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL)
    {
        //newnode->next = NULL;
        head = newnode;

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
    Node* temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void del(int c)
{
    int i = 1;
    Node* temp = head;
    while (i < c)
    {
        temp = temp->next;
        i++;
    }
    Node* t = temp;
    t = temp->next;
    temp->next = temp->next->next;
    delete(t);
    display1();
}
void find(int p)
{
    //cout << "in find";
    int c = 1;
    Node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == p)
        {
            //temp->next = head;
            //head = temp;
            
            Node* n = new Node;
            n->data = p;
            n->next = head;
            head=n;
            //del(c);
            break;
         
        }
        else {
            //cout <<c;
            temp = temp->next;
            c++;
             }
       
    }
    //cout << "hi";
     del(c);
    //display1();


}


int main()
{
    int ch = 5, val;
    cout << "enter the values " << endl;;
    while (ch != 0)
    {
        cin >> val;
        insert1(val);
        //display1();
        ch = ch - 1;
    }
    int k;
    cout << "enter an element to be searched" << endl;
    cin >> k;
    find(k);
    
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
