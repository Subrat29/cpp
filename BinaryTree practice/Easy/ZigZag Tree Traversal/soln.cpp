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
        return NULL;

    root->left = createTree(root->left);
    root->right = createTree(root->right);

    return root;
}

vector<int> zigZagTraversal(Node *root)
{
    vector<int> result;
    if (root == NULL)
    {
        return result;
    }

    queue<Node *> q;
    q.push(root);

    bool leftToright = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        // level process
        for (int i = 0; i < size; i++)
        {
            Node *frontNode = q.front();
            q.pop();

            // Normal insert or reverse insert
            int index = leftToright ? i : size - i - 1;
            ans[index] = frontNode->data;

            if (frontNode->left)
            {
                q.push(frontNode->left);
            }

            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }

        // direction change kr di
        leftToright = !leftToright;

        for (auto i : ans)
        {
            result.push_back(i);
        }
    }

    return result;
}

int main() // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
{
    Node *root = NULL;
    root = createTree(root);

    vector <int> ans = zigZagTraversal(root);

    for(int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}