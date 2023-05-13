#include <iostream>
using namespace std;

int minimumDays(int S, int N, int M)
{
    int sunday = S / 7;

    // sunday ko shop off rhti h
    int buyingDay = S - sunday;
    int totalFood = S * M;
    int ans = 0;

    if ((totalFood) % N == 0)
    {
        ans = totalFood / N;
    }
    else
    {
        ans = totalFood + 1;
    }

    if (ans <= buyingDay)
        return ans;
    else
        return -1;
}

int main()
{

    return 0;
}