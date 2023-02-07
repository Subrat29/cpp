#include <bits/stdc++.h>
using namespace std;

class List
{
public:
    int data;
    List *next;
};

int kthMoney(List *head, int k)
{
    List *temp = head;
    int cnt = 0;

    while (temp)
    {
        cnt++;
        temp = temp->next;
    }

    temp = head;
    int dest = cnt - k + 1;
    cnt = 1;

    while (cnt != dest)
    {
        cnt++;
        temp = temp->next;
    }

    return temp->data;
}

int main()
{

    return 0;
}