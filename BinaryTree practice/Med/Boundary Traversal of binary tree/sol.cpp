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

Node *createTree(Node *root)
{
    cout << "Enter root data : " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
        return NULL;

    root->left = createTree(root->left);
    root->right = createTree(root->right);

    return root;
}

void levelorderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
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

void traverseLeft(Node *root, vector<int> &ans)
{
    // base case
    if ((root == NULL) || (root->left == NULL && root->right == NULL)) // second part for leaf node
    {
        return;
    }
    ans.push_back(root->data);

    if (root->left)
    {
        traverseLeft(root->left, ans);
    }
    else // if left exist hi nhi krta then right pr jao
    {
        traverseLeft(root->right, ans);
    }
}

void traverseLeaf(Node *root, vector<int> &ans)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // Condition for leaf Node
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return; // forget this
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(Node *root, vector<int> &ans)
{
    // base case
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    if (root->right) // mistake: root->left phle daal diya tha
    {
        traverseRight(root->right, ans);
    }
    else // if right exist hi nhi krta then right pr jao
    {
        traverseRight(root->left, ans);
    }

    // wapas aate samay store kr lo data ko
    ans.push_back(root->data);
}

vector<int> boundary(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    ans.push_back(root->data);

    // left part traverse and store
    traverseLeft(root->left, ans);

    // leaf Node traverse and store
    //   left/right subtree
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);

    // right part traverse and store
    traverseRight(root->right, ans);

    return ans;
}

int main() // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
{
    Node *root = NULL;
    root = createTree(root);

    cout << "Level order traversal : ";
    levelorderTraversal(root);

    cout << endl;

    cout << "Boundry Traversal :     ";
    vector<int> ans = boundary(root);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}