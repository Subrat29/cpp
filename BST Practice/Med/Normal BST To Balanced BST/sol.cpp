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

void insertInBST(Node *&root, int x)
{
    if (root == NULL)
    {
        root = new Node(x);
    }

    else if (root->data > x)
    {
        insertInBST(root->left, x);
    }

    else
    {
        insertInBST(root->right, x);
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

void lot(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

void inorder(Node *root, vector<int> &v)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

Node *solve(vector<int> &v, int s, int e)   // Amazing: & lgane se CS me (19% faster,25ms) se (99.77 faster,20ms) ho gya 
{
    //base case
    if(s > e)
    {
        return NULL;
    }

    int mid = (s+e)/2;

    Node *root = new Node(v[mid]);
    root->left = solve(v, s, mid-1);
    root->right = solve(v, mid+1, e);
    
    return root;
}

Node *balancedBst(Node *root)
{
    vector<int> v;
    inorder(root, v);

    return solve(v, 0, v.size()-1);
}

int main() // 50 20 10 30 70 90 110 -1
{
    Node *root = NULL;
    inputBST(root);

    cout << "BST: " << endl;
    lot(root);

    Node *ans = balancedBst(root);
    cout << "Balanced BST: " << endl;
    lot(ans);
}