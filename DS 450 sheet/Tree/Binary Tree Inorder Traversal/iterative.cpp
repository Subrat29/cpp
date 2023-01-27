#include <bits/stdc++.h>  // Iterative solution using stack --- O(n) time and O(n) space;
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

vector<int> inorderTraversal(Node *root)  //using stack
{
    vector<int> ans;
    stack<Node*> s;

    while (root || !s.empty())
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }

        root = s.top();
        s.pop();
        ans.push_back(root->data);
        root = root->right;
    }
    return ans;
}

int main()
{
    Node *root = NULL;

    return 0;
}