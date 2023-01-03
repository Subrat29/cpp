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
    cout << "Enter a data" << endl;
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
// tc = O(n)
pair<int, int> diameterFast(Node *root) // pair <diameter, height>  for access these use first, second
{
    // base case
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1; // forget 1

    return ans;
}

int diameter(Node *root)
{
    return diameterFast(root).first;
}

int main() // Input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
{
    Node *root = NULL;
    root = createTree(root);
    levelorderTraversal(root);

    cout << "Diameter of Tree: " << diameter(root) << endl; // forget (root)

    return 0;
}
