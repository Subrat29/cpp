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
    if (root == NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

Node *inorderToBST(int s, int e, vector<int> &inorder)
{
    // base case
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2; // not s+e / 2;
    Node *root = new Node(inorder[mid]);

    root->left = inorderToBST(s, mid - 1, inorder);
    root->right = inorderToBST(mid + 1, e, inorder);

    return root;
}

vector<int> merge(vector<int> a, vector<int> b)
{
    vector<int> ans;

    int i = 0, j = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            ans.push_back(a[i]);
            i++;
        }
        else
        {
            ans.push_back(b[j]);
            j++;
        }
    }

    while (i < a.size()) //  i did this: while (!a.empty()) not work bc we not pop a items
    {
        ans.push_back(a[i++]);
    }

    while (j < b.size())
    {
        ans.push_back(b[j++]);
    }

    return ans;
}

Node *mergeBST(Node *root1, Node *root2) // tc: O(m+n) & sc: O(m+n)
{
    // if (root1 == NULL && root2 == NULL)         // No need of this part
    //     return NULL;

    // if (root1 == NULL)
    //     return root2;

    // if (root2 == NULL)
    //     return root1;

    // step1: Store inorders
    vector<int> in1, in2;
    inorder(root1, in1);
    inorder(root2, in2);

    // step2: Merge inorders
    vector<int> v = merge(in1, in2);

    // step3: Use merge inorder to build bst
    Node *ans = inorderToBST(0, v.size() - 1, v);

    return ans;
}

int main() // 50 20 10 30 70 90 110 -1     9 11 14 33 -1
{
    Node *root1 = NULL;
    inputBST(root1);

    Node *root2 = NULL;
    inputBST(root2);

    Node *ans = mergeBST(root1, root2);
    cout << "Ans: " << endl;
    lot(ans);
}