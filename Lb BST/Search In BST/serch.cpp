#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void insertInBST(Node *&root, int data)                       
{
    if (root == NULL)
    {
        root = new Node(data);
    }

    else if (data < root->data)    
    {
        insertInBST(root->left, data);
    }

    else                            
    {
        insertInBST(root->right, data);
    }
}

void inputBST(Node *&root)             
{
    cout << "Enter data: ";
    int data;
    cin >> data;                     

    while (data != -1)
    {
        insertInBST(root, data);
        cin >> data;
    }
}

bool searchInBST1(Node *root, int x)     //  tc: O(h), worst case: O(n)   &  sc: O(h)
{
    if(root == NULL)
        return false;
    
    if(root->data == x)
        return true;
    
    if(root->data < x)
       return searchInBST1(root->right, x);
    if(root->data > x)
       return searchInBST1(root->left, x);  
}

bool searchInBST2(Node *root, int x)     //  tc: O(h), worst case: O(n)   &  sc: O(1)
{
    Node *temp = root;

    while (temp != NULL)
    {
        if(temp->data == x)
        return true;

        if(temp->data > x)
        {
            temp = temp->left;
        }

        else
        {
            temp = temp->right;
        }
    }
    return false;
}

int main()   //last me -1 dalna mat bhoolna vro                               
{
    Node *root = NULL;

    inputBST(root);
    
    int x = 5;
    if(searchInBST2(root, x))
    {
        cout << "Search Found";
    }
    else
    {
        cout << "Search not found";
    }

    return 0;
}