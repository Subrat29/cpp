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

/*
Node *solve(vector<int> &preorder, int max, int &i)
{
    if(i >= preorder.size())
    {
        return NULL;
    }

    if(preorder[i] > max)
    {
        return NULL;
    }

    Node *root = new Node(preorder[i++]);   
    root->left = solve(preorder, root->data, i);
    root->right = solve(preorder, max, i);

    return root;
}

Node *preorderToBST(vector<int> &preorder)         //Tc: O(3n) 3 tim
{
    int max = INT_MAX;
    int i=0;
    return solve(preorder, max, i);
}
*/

Node *solve(vector<int> &preorder, int min, int max, int &i)   //& se tle se 99.17 faster ho gya :)
{
    if(i >= preorder.size())
    {
        return NULL;
    }

    if(preorder[i] < min || preorder[i] > max)
    {
        return NULL;
    }

    Node *root = new Node(preorder[i++]); //++
    root->left = solve(preorder, min, root->data, i);
    root->right = solve(preorder, root->data, max, i);

    return root;
}

Node *preorderToBST(vector<int> &preorder)         // Tc: O(3n) 3 times visit node = O(n) optimize than other approaches 
{                                                  // it can also work without min;
    int min = INT_MIN;
    int max = INT_MAX;

    int i=0;
    return solve(preorder, min, max, i);
}

int main() // 50 20 10 30 70 90 110 -1
{
    vector<int> v;
    v.push_back(50);
    v.push_back(20);
    v.push_back(10);
    v.push_back(30);
    v.push_back(70);
    v.push_back(90);
    v.push_back(110);

    Node *ans = preorderToBST(v);
    lot(ans);
}