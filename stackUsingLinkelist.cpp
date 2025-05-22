#include <iostream>

using namespace std;

// node class representating a single node in the linked list
class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        next = NULL;
    }
};

// stack class
class stack
{
private:
    Node *top; // pointer to the top node of the stack

public:
    stack()
    {
        top = NULL;
    }
    int push(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Push value: " << value << endl;
        return value;
    }

    // pop operation: Remove the topmost element from the stack
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
        }

        Node *temp = top;
        top = top->next;
        cout << "Popped value: " << top->data << endl;
    }

    // peel/top operation: Retrive the value of the topset element witchout removing
    void peek()
    {
        if (top == NULL)
        {
            cout << "List is empty." << endl;
        }
        else
        {
            Node *current = top;
            while (current != NULL)
            {
                cout << current->data << " " << endl;
                current = current->next;
            }
            cout << endl;

        } // return the value of the top node
    }

    // isEmpty operation: check of the stack is empty
    bool isEmpty()
    {
        return top == NULL; // Return true if the top pointer is null, indicating am empty stack
    }
};

int main()
{
    stack stack;

    int choice = 0;
    int value;

    while (choice != 5)
    {

        cout << "1.push\n";
        cout << "2.pop\n";
        cout << "3.peek\n";
        cout << "4.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter the value to push: ";
                cin >> value;
                stack.push(value); // push the entered value onto the stack
                break;
            case 2:
                if (!stack.isEmpty())
                {
                    stack.pop(); // pop the top element from the stack
                }
                else
                {
                    cout << "Stack is empty. Cannot pop." << endl;
                }
                break;
           