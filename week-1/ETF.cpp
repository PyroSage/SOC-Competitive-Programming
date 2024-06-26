#include <bits/stdc++.h>
using namespace std;

int phi(int n)
{
    int result = n;
    for (int i = 2; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result *= (1.0 - (1.0 / (float)i));
        }
    }
    if (n > 1)
    {
        result -= result / n;
    }
    return (int)result;
}

int main()
{
    int n, t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << phi(n) << endl;
    }
    return 0;
}