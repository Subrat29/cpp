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

int findpos(int in[], int element, int n)  // use pre insted in
{
    for(int i=0; i<n; i++)   //not n-1
    {
        if(in[i] == element)
        return i;
    }
    return -1;
}

Node *solve(int in[], int pre[], int &Index, int inorderStart, int inorderEnd, int n) // Use &Index
{
    // base case
    if (Index >= n || inorderStart > inorderEnd)  //i use >= in 2nd case
    {
        return NULL;
    }
    
    int element = pre[Index++];                  // Take a elem from Preorder Tree, end me Index ek increase bhi to krna h
    Node *root = new Node(element);
    int position = findpos(in, element, n);     // find posn of elem in Inorder Tree

    //recursive calls
    root->left = solve(in, pre, Index, inorderStart, position-1, n);   //i put 0 instead inorderStart but hm hr baar 0 nhi le skte update wala lege
    root->right = solve(in, pre, Index, position+1, inorderEnd, n);

    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    int preOrderIndex = 0;
    Node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n);
    return ans;
}

void Traversal(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if (temp->right)
        {
            q.push(temp->right);
        }

        if (temp->left)
        {
            q.push(temp->left);
        }
    }
}

int main()
{
    int in[] = {3, 1, 4, 0, 5, 2};
    int pre[] = {0, 1, 3, 4, 2, 5};
    int n = 6;

    cout << "Inorder: ";
    for(int i=0; i<n; i++)
    {
        cout << in[i] << " ";
    }cout << endl;

    cout << "Preorder: ";
    for(int i=0; i<n; i++)
    {
        cout << pre[i] << " ";
    }cout << endl;

    Node *ans = buildTree(in, pre, n);
    cout << "Post order: ";
    Traversal(ans);
}