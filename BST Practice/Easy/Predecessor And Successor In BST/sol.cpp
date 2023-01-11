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

pair<int, int> predecessorSuccessor(Node *root, int key)
{
    Node *temp = root;
    int pred = -1;
    int succ = -1;

    while (temp->data != key)
    {
        if (temp->data > key)
        {
            succ = temp->data; // yha kyu use kiya ya
            temp = temp->left;
        }
        else
        {
            pred = temp->data;
            temp = temp->right;
        }
    }

    // predecessor
    Node *leftTree = temp->left;            // ye temp = key hi h;
    while (leftTree != NULL)
    {
        pred = leftTree->data;              // left subtree me max element
        leftTree = leftTree->right;
    }

    Node *rightTree = temp->right;
    while (rightTree != NULL)
    {
        succ = rightTree->data;             // right subtree me min element
        rightTree = rightTree->left;
    }

    // pair <int , int> p = make_pair(pred, succ);
    // return p;

    return {pred, succ};
}

int main() // 50 20 10 30 70 90 110 -1
{
    Node *root = NULL;
    inputBST(root);

    int key = 30;
    pair<int, int> ans = predecessorSuccessor(root, key);

    cout << "pred: " << ans.first << endl;
    cout << "succ: " << ans.second << endl;

}