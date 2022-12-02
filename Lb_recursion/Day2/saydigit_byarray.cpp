#include <bits/stdc++.h>
using namespace std;

void sayDigits(int n, string str[])
{
   //base case
   if(n==0)
   return;

   int rem = n%10;
   n=n/10;

   //recursive Call
   sayDigits(n,str);
   cout << str[rem] << " ";

}

int main()
{
    int n;
    cin >> n;
    string str[10] = {"zero", "one", "two", "three",
                             "four", "five", "six",
                             "seven", "eight", "nine"};

    sayDigits(n, str);

    return 0;
}