#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    //constructor
    Node (int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};


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


Node *buildFromLevelOrder(Node *&root)
{
    queue <Node*> q;

    cout << "Enter data for root: " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter left node data for : " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node data for : " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

int main()           // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 
{
    Node *root = NULL;

    buildFromLevelOrder(root);
    levelorderTraversal(root);

    return 0;
}