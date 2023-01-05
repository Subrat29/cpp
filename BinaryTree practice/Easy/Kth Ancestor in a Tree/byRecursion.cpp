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
    {
        return NULL;
    }

    root->left = createTree(root->left);
    root->right = createTree(root->right);

    return root;
}

Node *solve(Node *root, int &k, int node)
{
    //base case
    if (root == NULL)
    {

        return NULL;
    }

    if (root->data == node)
    {
        return root;
    }

    Node *leftAns = solve(root->left, k, node);
    Node *rightAns = solve(root->right, k, node);

    if(leftAns != NULL && rightAns == NULL)
    {
        k--;
        if(k <= 0)
        {
            //answer lock
            k = INT_MAX;           // k ko aisa integer bna do jo bahut bada ho isse baad me k-- krte samay ye phir se k<=0 na ho jaye
            return root;
        }
        return leftAns;
    }

    if(leftAns == NULL && rightAns != NULL)
    {
        k--;
        if(k <= 0)
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }

    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    Node *ans = solve(root, k, node);
    
    if(ans == NULL || ans->data == node)   //2nd condn edge case is imp: In ques 1<=k<=100, therefore 'k' ki value 1 to rhegi hi but if node root node aa gya then return -1.
    {                                      //mistake: use &&
        return -1;
    }
    else
    {
        return ans->data;
    }
}

int main()    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
{
    Node *root = NULL;
    root = createTree(root);

    int k = 2;
    int node = 7;
    cout << kthAncestor(root, k, node);

    return 0;
}
//bro aaj 5 jan h kesa h tu? pyaar tughse krta ko studio me record krane ki soch rha hu dekhte h.dekhte nii jaata hu studio
// Bro kuch din se depressed tha pta nii aise hi jyada content consume kro but kuch action nhi lo to ye hota hi h its general.
//but now i am good doing dsa happy bye...
