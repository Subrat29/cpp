#include <bits/stdc++.h> //tc: O(n*k logk)   sc: O(k)
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

//create custom comprator // i dont know what is this hehehe??
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
    priority_queue<Node<int> *, vector<Node<int> *>, compare> minHeap;

    int k = listArray.size();

    if (k == 0)
        return NULL;

    Node<int> *head = NULL;
    Node<int> *tail = NULL;

    // step1: creating k heap with the head of k given Linked List
    for (int i = 0; i < k; i++)
    {
        if (listArray[i] != NULL)
        {
            minHeap.push(listArray[i]);
        }
    }

    while (minHeap.size() > 0)
    {
        Node<int> *top = minHeap.top();
        minHeap.pop();

        if (top->next != NULL)     //mis: top to tail
        {
            minHeap.push(top->next);
        }

        if (head == NULL) // checking if its the 1st most element
        {
            head = top;
            tail = top;
        }
        else // for rest of elements
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