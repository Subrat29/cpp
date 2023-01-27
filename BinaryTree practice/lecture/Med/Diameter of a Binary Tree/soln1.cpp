#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree(Node *root)
{
    cout << "Enter data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    root->left = createTree(root->left);
    root->right = createTree(root->right);

    return root;
}

void levelorderTraversal(Node *root) 
{                                    
    queue<Node *> q;                 
    q.push(root);
    q.push(NULL); // seperator for LOT

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        // Aur jese hi seperator mil jaye to ENTER maar do

        if (temp == NULL) // purana level complete traverse ho chuka h
        {
            cout << endl;

            if (!q.empty()) // queue still have some child nodes
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int height(Node *root)
{
    //base case
    if(root == NULL)
    return 0;

    int right = height(root->right);
    int left = height(root->left);
    int ans = max(right, left) + 1;
    return ans;
}

int diameter(Node *root)                                //TC : O(n^2) bc calling height with diameter
{
    //base case
    if(root == NULL)
    return 0;

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + height(root->right) + 1;

    int ans = max(op1, max(op2, op3) );
    return ans;
}

int main() // Input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
{
    Node *root = NULL;
    root =  createTree(root);
    levelorderTraversal(root);

    cout << "Diameter of Tree: " << diameter(root) << endl;

    return 0;
}