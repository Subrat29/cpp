#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
        this->next = NULL;
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

void convertBST_intoSortedDLL(Node *root, Node *&head) //&
{
    // base case
    if (root == NULL)
        return;

    // convert right part
    convertBST_intoSortedDLL(root->right, head);

    // root node se jo list return hokr aayi h usse link krwa do
    root->right = head; // head = root->right;

    if (head != NULL)
    {
        head->left = root;
    }
    head = root;

    // convert left part
    convertBST_intoSortedDLL(root->left, head);
}

Node *mergeLinkedlist(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail; // rem
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL)
    {
                tail->right = head1;
                head1->left = tail; 
                tail = head1;
                head1 = head1->right;
    }

    while (head2 != NULL)
    {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
    }

    return head;
}

int noOfNodes(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

Node *sortedDLL_toBST(Node *&head, int n)       //if rempve & then it not run
{
    if(n <= 0 || head == NULL)
    {
        return NULL;
    }

    Node *left = sortedDLL_toBST(head, n/2);

    Node *root = head;
    root->left = left;
    head = head->right; //rem

    root->right = sortedDLL_toBST(head, n-n/2-1);

    return root;
}

Node *mergeBST(Node *root1, Node *root2) // tc: O(m+n) & sc: O(h)
{
    //step1: convert bst into sorted DLL in-place (no new memory use)
    Node *head1 = NULL;
    convertBST_intoSortedDLL(root1, head1);
    head1->left = NULL;

    Node *head2 = NULL;
    convertBST_intoSortedDLL(root2, head2);
    head2->left = NULL;

    //step2: merge linked list
    Node *head = mergeLinkedlist(head1, head2);

    //step3: convert sorted DLL to BST 
    Node *ans = sortedDLL_toBST(head, noOfNodes(head));

    return ans;
}

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
}

void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() // 50 20 10 30 70 90 110 -1     9 11 14 33 -1                //CS pr to chal rha h ye
{
    Node *root1 = NULL;
    inputBST(root1);

    Node *root2 = NULL;
    inputBST(root2);

    Node *ans = mergeBST(root1, root2);
    cout << "Ans: " << endl;

    lot(ans);

    // inorder(ans);

    // print(ans);

}