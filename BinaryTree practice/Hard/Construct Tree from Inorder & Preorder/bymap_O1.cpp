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

void mapping(int in[], map <int, int> &nodeToIndex, int n)  
{
    for(int i=0; i<n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
}

Node *solve(int in[], int pre[], int &Index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex) 
{
    // base case
    if (Index >= n || inorderStart > inorderEnd)       
    {
        return NULL;
    }

    int element = pre[Index++];                        
    Node *root = new Node(element);
    int position = nodeToIndex[element];

    // recursive calls
    root->left = solve(in, pre, Index, inorderStart, position - 1, n, nodeToIndex);  
    root->right = solve(in, pre, Index, position + 1, inorderEnd, n, nodeToIndex);

    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    //create a map for mapping node to index
    map <int, int> nodeToIndex;
    mapping(in, nodeToIndex, n);

    int preOrderIndex = 0;
    Node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n, nodeToIndex);

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
    // int in[] = {3, 1, 4, 0, 5, 2};     // this case run
    // int pre[] = {0, 1, 3, 4, 2, 5};    
    // int n = 6;

    // int in[] = {1,6,8,7};              // this case run
    // int pre[] = {1,6,7,8};
    // int n = 4;

   int in[] = {7, 3, 11, 1, 17, 3, 18};   // this case not run in map bec it has repeated value '3', jisse map dono ka same ho jayega.
   int pre[] = {1, 3, 7, 11, 3, 17, 18};
   int n = 7;
// expected output = 7 11 3 17 18 3 1

    cout << "Inorder: ";
    for (int i = 0; i < n; i++)
    {
        cout << in[i] << " ";
    }
    cout << endl;

    cout << "Preorder: ";
    for (int i = 0; i < n; i++)
    {
        cout << pre[i] << " ";
    }
    cout << endl;

    Node *ans = buildTree(in, pre, n);
    cout << "Post order: ";
    postorder(ans);
}