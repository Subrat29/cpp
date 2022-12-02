#include <bits/stdc++.h>
using namespace std;

void sayDigits(int n, vector <string> digits)
{
   //base case
   if(n==0)
   return;

   int rem = n%10;
   n=n/10;

   //recursive Call
   sayDigits(n, digits);
   cout << digits[rem] << " ";

}

int main()
{
    int n;
    cin >> n;
    vector <string> digits = {"zero", "one", "two", "three",
                             "four", "five", "six",
                             "seven", "eight", "nine"};
    sayDigits(n, digits);

    return 0;
}