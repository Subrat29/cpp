#include <bits/stdc++.h> //stl
using namespace std;

int main()
{
    cout << "Max heap" << endl;
    priority_queue<int> pq; // max heap
    pq.push(2);
    pq.push(4);
    pq.push(1);
    pq.push(6);

    cout << "Top element: " << pq.top() << endl;
    pq.pop();

    cout << "Top element: " << pq.top() << endl;

    if (pq.empty())
        cout << "pq is empty" << endl;
    else
        cout << "pq is not empty" << endl;

    cout << endl
         << "Min Heap" << endl;
    priority_queue<int, vector<int>, greater<int>> minHeap; // min heap

    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(8);
    minHeap.push(4);

    cout << "Top element: " << minHeap.top() << endl;
    minHeap.pop();

    cout << "Top element: " << minHeap.top() << endl;

    if (minHeap.empty())
        cout << "pq is empty" << endl;
    else
        cout << "pq is not empty" << endl;

    return 0;
}