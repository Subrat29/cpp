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

int findpos(int in[], int start, int end, int element) 
{
    for(int i=start; i<=end; i++) 
    {
        if(in[i] == element)
        return i;
    }
}

Node *solve(int in[], int post[], int &Index, int inorderStart, int inorderEnd, int n)      
{
    // base case
    if (Index < 0  || inorderStart > inorderEnd)     // first case change                                   
    {
        return NULL;
    }

    int element = post[Index--];      // yha --                                                    
    Node *root = new Node(element);
    int position = findpos(in, inorderStart, inorderEnd, element);                                              

    //recursive calls
    root->right = solve(in, post, Index, position+1, inorderEnd, n);   // is ques me root ke right wala part phle build hoga ans left part baad me
    root->left = solve(in, post, Index, inorderStart, position-1, n);                     

    return root;
}

Node *buildTree(int in[], int post[], int n)
{
    int postOrderIndex = n-1;        // yha change
    Node *ans = solve(in, post, postOrderIndex, 0, n - 1, n);
    return ans;
}

void preorder(Node *root)   //LRN         
{
    //base case
    if(root == NULL)
    return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
//  Output: 1 2 4 8 5 3 6 7
    int n = 8;

    cout << "Inorder: ";
    for(int i=0; i<n; i++)
    {
        cout << in[i] << " ";
    }cout << endl;

    cout << "Postorder: ";
    for(int i=0; i<n; i++)
    {
        cout << post[i] << " ";
    }cout << endl;

    Node *ans = buildTree(in, post, n);

    cout << "Pre order: ";
    preorder(ans);
}