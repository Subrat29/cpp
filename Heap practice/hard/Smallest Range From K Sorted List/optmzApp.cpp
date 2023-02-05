#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    int row;
    int col;

    // constructor
    Node(int d, int r, int c)
    {
        data = d;
        row = r;
        col = c;
    }
};

// create custom comprator // i dont know what is this hehehe??
class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n)
{
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<Node *, vector<Node *>, compare> minHeap;

    // step1: create a min heap for starting element of each list and tracking mini, maxi value
    for (int i = 0; i < k; i++)
    {
        int elem = a[i][0];
        mini = min(mini, elem);
        maxi = max(maxi, elem);
        minHeap.push(new Node(elem, i, 0));
    }

    int start = mini, end = maxi;

    // process ranges
    while (!minHeap.empty())
    {
        Node *temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        // ranges or answer updation
        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }

        // next element exists
        if (temp->col + 1 < n)
        {
            maxi = max(maxi, a[temp->row][temp->col + 1]);
            minHeap.push(new Node(a[temp->row][temp->col + 1], temp->row, temp->col + 1));
        }
        else
        {
            // next elem does not exist
            break;
        }
    }
    // return the difference of range
    return end - start + 1;
}

int main()
{

    return 0;
}