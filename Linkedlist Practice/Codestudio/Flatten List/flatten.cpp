#include <bits/stdc++.h>
#include <bits/stdc++.h>

class Node
{
public:
    int data;
    Node *next;
    Node *bottom;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->bottom = NULL;
    }
};

Node *merge(Node *a, Node *b)
{
    if (a == NULL)
    {
        return b;
    }

    if (b == NULL)
    {
        return a;
    }

    Node *ans;

    if (a->data < b->data)
    {
        ans = a;
        ans->bottom = merge(a->bottom, b); // a ko ans me dalkr, a ko bottom ki taraf bhej do
    }
    else
    {
        ans = b;
        ans->bottom = merge(a, b->bottom);
    }

    ans->next = NULL; // when u dry run u know that only bottom is exist, next not exist.
    return ans;
}

Node *flattenLinkedList(Node *head) // if not get then watch video and dry run // Yogesh & Shailesh (CodeLibrary)
{
    if (head == NULL || head->next == NULL)      //mistake: i use && 
    {
        return head;
    }

    // Recur on next node
    head->next = flattenLinkedList(head->next);    //ye peeche bhejta jayega & hm peeche se merge krna start krege

    // Merge with the current
    head = merge(head, head->next);

    return head;

    // return merge(head, flattenLinkedList(head->next));  
}

int main()
{
    return 0;
}
