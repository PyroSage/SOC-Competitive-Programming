#include <bits/stdc++.h>
using namespace std;

const int N = 300300;
int n, m;
int a[N];

int solve(int l, int r)
{
    if (r - l == 1)
    {
        return 0;
    }
    int mid = (l + r) >> 1;
    int mal = *max_element(a + l,a + mid);
    int mar = *max_element(a + mid, a + r);
    int ans = 0;
    if (mal > mar)
    {
        ans++;
        for (int i = 0; i < mid - l; i++)
        {
            swap(a[l + i], a[mid + i]);
        }
    }
    return solve(l, mid) + solve(mid, r) + ans;
}

int solved()
{
    int ans = solve(0, n);
    if (is_sorted(a, a + n))
    {
        return ans;
    }
    return -1;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << solved() << endl;
        
    }
    return 0;
}