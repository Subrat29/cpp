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

Node *buildTree(Node *root)
{
    cout << "Enter data: " << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new Node(data);
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

// create mapping
// return target node
Node *createParentMapping(Node *root, int target, map<Node *, Node *> &nodeToParent)
{
    Node *res = NULL;

    queue<Node *> q;
    q.push(root);
    nodeToParent[root] = NULL; // root ka parent null

    while (!q.empty()) // level order traversal
    {
        Node *front = q.front();
        q.pop();

        if (front->data == target)
        {
            res = front;
        }

        if (front->left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }

        if (front->right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

int burnTree(Node *root, map<Node *, Node *> &nodeToParent)
{
    map<Node *, bool> visited;
    queue<Node *> q;

    q.push(root);
    visited[root] = true;

    int ans = 0;

    while (!q.empty())
    {
        bool flag = 0; // to know addition in queue
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();

            if (front->left && !visited[front->left])
            {
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }

            if (front->right && !visited[front->right])
            {
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }

            if (nodeToParent[front] && !visited[nodeToParent[front]])
            {
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1; // forget =1
            }
        }
        if (flag == 1)
            ans++;
    }
    return ans;
}

int minTime(Node *root, int target)                                      // sc - O(n), tc - O(n)
{
    // step 1: create nodeToParent mapping
    // step 2: find target node
    // step 3: burn the tree in min time

    map<Node *, Node *> nodeToParent;
    Node *targetNode = createParentMapping(root, target, nodeToParent);

    int ans = burnTree(targetNode, nodeToParent);

    return ans;
}

int main()   //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
{
    Node *root = NULL;
    root = buildTree(root);

    int target = 11;
    cout << "Time to burn: " << minTime(root, target);

    return 0;
}