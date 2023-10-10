#include<iostream>
#include<vector>
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

void inorder(Node *root, vector<int> &store)
{
    if (root == NULL)
        return;

    inorder(root->left, store);

    cout << root->data << " ";

    store.push_back(root->data);

    inorder(root->right, store);
}

bool validateBST(Node *root)    // this code run fine on gfg but not in ninja bc uske input 1 2 3 4 -1 -1 -1 aise input hote h
{
    vector<int> store;
    inorder(root, store);

    for (int i = 0; i < store.size() - 1; i++)
    {
        if (store[i] > store[i + 1])
            return false;
    }
    return true;
}

int main() // 50 20 10 30 70 90 110 -1
{
    Node *root = NULL;

    inputBST(root);

    if (validateBST(root))
    {
        cout << endl << "Valid BST";
    }
    else
    {
        cout << endl << "Not Valid BST";
    }
}