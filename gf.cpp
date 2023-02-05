#include <bits/stdc++.h> //tc: O(n*k logk)   sc: O(k)
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
class compare
{
public:
    bool operator()(Node<int> *a, Node<int> *b)
    {
        return a->data > b->data;
    }
};
Node<int> *mergeKLists(vector<Node<int> *> &listArray)
{
    priority_queue<Node<int> *, vector<Node<int> *>, compare> minheap;
    int k = listArray.size();
    if (k == 0)
        return NULL;
    Node<int> *head = NULL;
    Node<int> *tail = NULL;
    // creating k heap with the head of k given Linked List
    for (int i = 0; i < k; i++)
    {
        Node<int> *temp = listArray[i];
        if (temp != NULL)
            minheap.push(temp);
    }
    while (minheap.size() > 0)
    {
        Node<int> *top = minheap.top();
        minheap.pop();
        if (top->next != NULL)
        {
            minheap.push(top->next);
        }
        // checking if its the 1st most element
        if (head == NULL)
        {
            head = top;
            tail = top;
        }
        // for rest of elements
        else
        {
            tail->next = top;
            tail = top;
        }
    }
    return head;
}

int main()
{
    return 0;
}