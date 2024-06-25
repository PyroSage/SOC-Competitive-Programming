#include <bits/stdc++.h>
using namespace std;
string s;

int get_cost(int l, int r, char c)
{
    int cnt = 0;
    for (int i = l; i < r+1; i++)
    {
        if (s[i] != c) cnt++;     
    }
    return cnt;
}

int get_min(int l, int r, char c)
{
    if(l == r)
    {
        if (s[l] == c) return 0;
        else return 1;
    }
    int m = (l + r) >> 1;
    return min(get_cost(l, m, c) + get_min(m+1, r, c+1), get_cost(m+1, r, c)+get_min(l, m, c+1));
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n >> s;
        cout << get_min(0, n-1, 'a') << endl;
    }
    return 0;
}