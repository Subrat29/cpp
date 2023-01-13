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

void inOrder(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;

    inOrder(root->left, v);
    v.push_back(root->data);
    inOrder(root->right, v);
}

bool twoSumInBST(Node *root, int target)                         //tc: O(n), sc: O(n)
{
    vector<int> v;
    inOrder(root, v);

    int s = 0;
    int e = v.size() - 1;

    while (s < e)
    {
        int sum = v[s] + v[e];

        if(sum == target)
        {
            return true;
        }

        else if (sum > target)
        {
            e--;
        }

        else
        {
            s++;
        }
    }

    return false;
}

int main() // 50 20 10 30 70 90 110 -1
{
    Node *root = NULL;
    inputBST(root);

    int target = 120;
    twoSumInBST(root, target);

    if (twoSumInBST)
        cout << "Two sum found" << endl;
    else
        cout << "Two sum not found" << endl;
}