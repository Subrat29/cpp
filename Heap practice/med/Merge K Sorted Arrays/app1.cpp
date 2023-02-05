#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    int i;
    int j;

    Node(int data, int row, int col)
    {
        this->data = data;
        i = row;
        j = col;
    }
};

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)   // tc: O(n*k log(k))    sc: O(n*k)
{
    priority_queue<Node *, vector<Node *>, compare> min;

    // Step1: push first elem of all arrays
    for (int i = 0; i < k; i++)
    {
        Node *temp = new Node(kArrays[i][0], i, 0);
        min.push(temp);
    }

    vector<int> ans;

    // step2: min ka top ans me daal do & push next elem of array into heap if present.
    while (min.size() > 0)
    {
        Node *temp = min.top();

        ans.push_back(temp->data);
        min.pop();

        int i = temp->i;
        int j = temp->j;

        // check agle elem ka index chota hona chahiye array ke size se then push
        if (j + 1 < kArrays[i].size())
        {
            Node *next = new Node(kArrays[i][j + 1], i, j + 1);
            min.push(next);
        }
    }
    return ans;
}

int main()
{
    return 0;
}
