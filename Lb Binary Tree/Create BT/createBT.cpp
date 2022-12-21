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

    cout << "Enter data for inserting in left of: " << data << endl;
    root->left = createTree(root->left);

    cout << "Enter data for inserting in right of: " << data << endl;
    root->right = createTree(root->right);

    return root;
}

// void levelorderTraversal(Node *root)       // Output:    1 3 5 7 11 17
// {
//     queue <Node*> q;
//     q.push(root);

//     while (!q.empty())
//     {
//         Node *temp = q.front();
//         cout << temp->data << " ";
//         q.pop();

//         if(temp->left)
//         {
//             q.push(temp->left);
//         }

//         if(temp->right)
//         {
//             q.push(temp->right);
//         }
//     }
// }

void levelorderTraversal(Node *root)      //Output:        //  1
{                                                          //  3 5
    queue <Node*> q;                                       //  7 11 17
    q.push(root);
    q.push(NULL); // seperator for LOT

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        //Aur jese hi seperator mil jaye to ENTER maar do

        if (temp == NULL)     //purana level complete traverse ho chuka h
        {
            cout << endl;

            if (!q.empty())   //queue still have some child nodes
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    Node *root = NULL; // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    root = createTree(root);
    cout << "Printing the level order traversal output" << endl;
    levelorderTraversal(root);

    return 0;
}