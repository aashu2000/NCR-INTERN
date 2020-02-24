// sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<chrono>
using namespace std;
struct Node {
    string data;
    struct Node* next;
};
Node* head = NULL;
void insert(string val)
{
    Node* newnode = new Node;
    Node* temp = head;
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
   }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void display()
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " "<<endl;
        temp = temp->next;
    }
}
void sortt()
{
    Node* temp1 = head;
    while (temp1->next!= NULL)
    {
        Node* temp2 = temp1->next;
        while (temp2 != NULL)
        {
            if (temp1->data > temp2->data)
            {
                string k;
                k = temp1->data;
                temp1->data = temp2->data;
                temp2->data = k;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    display();


}

int main()
{
    auto start = chrono::steady_clock::now();//gives the start time
    int ch = 4;
    string val;
    cout << "enter any 4 elements to be sorted" << endl;
    while (ch != 0)
    {
        cin >> val;
        insert(val);
        ch = ch - 1;
    }
    cout << "elements before sorting" << endl;
    display();
    cout << "elements after sorting" << endl;
    sortt();
    auto end = chrono::steady_clock::now();//gives the end time
    double time_taken = double(chrono::duration_cast<chrono::nanoseconds>(end - start).count());//difference between start and end times
    cout << "Time taken for the execution is:" << time_taken/1e9<<" seconds"<<endl;


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
