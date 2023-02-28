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

void insertInBST(Node *&root, int data)   // forget &                                tc: of insertion is O(logn), sc: O(h)
{
    if (root == NULL)
    {
        root = new Node(data);
    }

    else if (data < root->data)      // insert in left part   //Note IMP: i use elseif not if
    {
        insertInBST(root->left, data);
    }

    else                             // insert in right part
    {
        insertInBST(root->right, data);
    }
}

void inputBST(Node *&root)             
{
    cout << "Enter data: ";
    int data;
    cin >> data;                      //Here data input nhi loge to aage compare kise karaoge, 0 ko bhi ni kra skte vrna vo input me chla jayega

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

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)   //forget
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

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

void inorder(Node *root)  // LNR          //Very Imp: Gives sorted bst
{
    if(root == NULL)                      //forget this
    return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)  // NLR
{
    if(root == NULL)
    return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)  // LRN
{
    if(root == NULL)      
    return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()  // 50 20 10 30 70 90 110 -1
{
    Node *root = NULL;

    inputBST(root);

    cout << "LevelOrder Traversal: " << endl;
    lot(root);

    cout << endl << "InOrder Traversal: " << endl;
    inorder(root);
    cout << endl << endl;

    cout << "PreOrder Traversal: " << endl;
    preorder(root);
    cout << endl << endl;

    cout << "PostOrder Traversal: " << endl;
    postorder(root);
    cout << endl << endl;

    return 0;
}