#include <bits/stdc++.h> 

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

Node *merge(Node *a, Node *b) 
{
    if(a == NULL)
    {
        return b;
    }

    if(b == NULL)
    {
        return a;
    }

    Node *ans = NULL;

    if(a->data < b->data)
    {
        ans = a;
        ans->child = merge(a->child ,b); 
    }
    else
    {
        ans = b;
        ans->child = merge(a, b->child); 
    }

    ans->next = nullptr;  
    return ans;
}

Node* flattenLinkedList(Node* head)   
{
    if(head == NULL && head->next == NULL)
    {
        return head;
    }

    // return merge(head, flattenLinkedList(head->next));

    // Recur on next node
    head->next = flattenLinkedList(head->next);

    // Merge with the current
    head = merge(head, head->next);

    return head;
}
