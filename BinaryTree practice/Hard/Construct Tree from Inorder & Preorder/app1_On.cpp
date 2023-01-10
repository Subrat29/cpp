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

int findpos(int in[], int start, int end, int element)  // use pre instead in
{
    for(int i=start; i<=end; i++)   //not n-1    // Blunder: for(i=0; i<=n; i++) 
    {
        if(in[i] == element)
        return i;
    }
}

Node *solve(int in[], int pre[], int &Index, int inorderStart, int inorderEnd, int n)       // Use &Index
{
    // base case
    if (Index >= n || inorderStart > inorderEnd)                                            //i use >= in 2nd case
    {
        return NULL;
    }
    
    int element = pre[Index++];                                                             // Take a elem from Preorder Tree, end me Index ek increase bhi to krna h
    Node *root = new Node(element);
    int position = findpos(in, inorderStart, inorderEnd, element);                                                 // find posn of elem in Inorder Tree

    //recursive calls
    root->left = solve(in, pre, Index, inorderStart, position-1, n);                        //i put 0 instead inorderStart but hm hr baar 0 nhi le skte update wala lege
    root->right = solve(in, pre, Index, position+1, inorderEnd, n);

    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    int preOrderIndex = 0;
    Node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n);
    return ans;
}

void postorder(Node *root)   //LRN           // Mis: i use simple traversal to print
{
    //base case
    if(root == NULL)
    return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    // int in[] = {3, 1, 4, 0, 5, 2};
    // int pre[] = {0, 1, 3, 4, 2, 5};
    // int n = 6;

    // int in[] = {1,6,8,7};      
    // int pre[] = {1,6,7,8};
    // int n = 4;

   int in[] = {7, 3, 11, 1, 17, 3, 18};
   int pre[] = {1, 3, 7, 11, 3, 17, 18};
   int n = 7;
// expected output = 7 11 3 17 18 3 1

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
    postorder(ans);
}