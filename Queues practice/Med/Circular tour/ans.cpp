#include <bits/stdc++.h>                              //app1: by 2 loops,  app2: by front & rear,  app3: by start & kami
using namespace std;

class petrolPump                           
{
    public:
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n)
{
    int kami = 0 ;         //dont forget to initialize
    int balance = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        balance += p[i].petrol - p[i].distance;

        if (balance < 0)
        {
            kami += balance;
            start = i + 1;
            balance = 0;
        }
    }

    if (kami + balance >= 0)
    {
        return start;
    }

    return -1;
}

int main()
{
    petrolPump p[] = { {4,6}, {6,5}, {7,3}, {4,5} };

    // p[] = {{6,4},{6,4},{6,4},{6,4}};          why not initialize like that after declaration??

    cout << "size of p: " << sizeof(p) << endl;
    cout << "size of p[0]: " << sizeof(p[0]) << endl;

    int n = sizeof(p)/sizeof(p[0]);
    cout << "n : " << n << endl;

    cout << tour(p, n);
    return 0;
}