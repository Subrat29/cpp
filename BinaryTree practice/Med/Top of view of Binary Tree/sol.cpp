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
    cout << "Enter data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    // if (root->left)                                    Mistake use this
        root->left = createTree(root->left);
    // if (root->right)
        root->right = createTree(root->right);

    return root;
}

vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    map<int, int> topNode;
    queue<pair<Node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hd = temp.second;

        // if one value is present for a HD, then do nothing
        if (topNode.find(hd) == topNode.end()) //; lga diya tha
            topNode[hd] = frontNode->data;

        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));

        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
    }

    for (auto i : topNode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

int main() // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
{
    Node *root = NULL;
    root = createTree(root);

    vector<int> ans = topView(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}