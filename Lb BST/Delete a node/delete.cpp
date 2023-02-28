#include<iostream>
#include<queue>
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
    // if(root == NULL)   not use this
    // return;
      
    queue <Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if(temp == NULL)   // forget
        {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";

            if(temp->left)
            q.push(temp->left);

            if(temp->right)
            q.push(temp->right);
        }
    }
}

int rightMinVal(Node *root)
{
    Node *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

Node *deleteFromBST(Node *root, int x)                   //tc = O(h), sc: O(n)   // del code is very imp for interview
{ 
    // base case
    if (root == NULL)
    {
        return root; // not null   //why??
    }

    if (root->data == x)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            // Node *temp = root;
            delete root;
            return NULL;
            // return temp;
        }

        // 1 child

        // left child
        if (root->left != NULL && root->right == NULL)
        {
            // Node *temp = root;
            // delete root->left;
            // return temp;
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child                                             (2 ways : find max value from left || min val from right)
        if (root->left != NULL && root->right != NULL)
        {
            // step1: find mini
            int mini = rightMinVal(root->right);                 //but why need min in right part bst me to phle se hi sort hua hote h seedhe root ka right kyu nii uthaya??

            // step2: copy mini
            root->data = mini;

            // step3: delete mini
            root->right = deleteFromBST(root->right, mini);

            // delete mini; <-mistake

            return root;
        }
    }

    if (root->data > x) // left me jao re
    {
        root->left = deleteFromBST(root->left, x);
        return root;
    }

    else // right me jao   // not if(root->data < x)
    {
        root->right = deleteFromBST(root->right, x);
        return root;
    }
}

int main()  // 50 20 10 30 70 90 110 -1                                
{
    Node *root = NULL;
    int nodeToDelete = 50;

    inputBST(root);

    lot(root);
    cout << endl << "Delete: " << nodeToDelete << endl << endl;

    deleteFromBST(root, nodeToDelete);

    lot(root);
}