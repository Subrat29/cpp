#include <iostream>
#include <math.h>
using namespace std;

void Fun(int n)
{
    if (n <= 1)
        return;
    // for (int i = 1; i < (n ^ 2); i++)
    // {
    //     cout << i << ": C - language\n";
    // }

    for (int i = 1; i < pow(n, 2); i++)
    {
        cout << i << ": C - language\n";
    }
}

int main()
{
    int n = 5;
    Fun(n);

    cout << pow(n, 2);

    return 0;
}

// Here, (n ^ 2) is a bitwise XOR operation. The binary representation of 5 is 101,
//  and the binary representation of 2 is 010. When you perform a bitwise XOR between
//  these two binary numbers, you get 111, which is 7 in decimal notation.

//  Use this: pow(n, 2);