#include <iostream>
using namespace std;
int minimumMoves(string s, string t)
{

    int n = s.length();
    int m = t.length();

    int i = n - 1;
    int j = m - 1;

    int k = 0;
    int l = 0;

    int suf = 0;

    if (s[k] == t[l])
    {
        while (i < n && j < m)
        {

            if (s[k] == t[l])
            {

                suf++;

                k++;
                l++;
            }
            else
            {

                break;
            }
        }
    }
    else
    {
        while (i >= 0 && j >= 0)
        {

            if (s[i] == t[j])
            {

                suf++;

                i--;
                j--;
            }
            else
            {

                break;
            }
        }
    }

    return n + m - 2 * suf;
}

int main()
{
    string s = "letscode";
    string t = "code";

    cout << minimumMoves(s, t) << endl;

    return 0;
}