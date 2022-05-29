#include <iostream>
#include <bits/stdc++.h>
#define MAX_SIZE 1000

using namespace std;

template <class T>
class Node
{
public:
    T val;
    Node *prev = nullptr;
    Node(){};
    Node(T value)
    {
        this->val = value;
    };
};

template <class T>
class Stack
{
    Node<T> *curr;
    Node<T> *head;

public:
    Stack()
    {
        curr = head = nullptr;
    }

    void push(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (head == nullptr)
        {
            head = curr = newNode;
            return;
        }
        newNode->prev = curr;
        curr = newNode;
    }
    T pop()
    {
        if (head == nullptr)
        {
            return 0;
        }
        Node<T> *temp = curr;
        if (head == curr)
        {
            curr = head = nullptr;
        }
        else
        {
            curr = curr->prev;
        }
        T value = temp->val;
        delete temp;
        return value;
    }

    T top()
    {
        if (head == nullptr)
        {
            return 0;
        }
        return curr->val;
    }
    bool isEmpty()
    {
        return head==nullptr;
    }
    void traverse()
    { // all elements will be popped
        while (!isEmpty())
        {
            cout << pop() << '\n';
        }
    }
};

int main()
{
    Stack<string> st = Stack<string>();
    st.push("ab");
    st.push("cd");
    st.push("ef");
    st.traverse();
}
