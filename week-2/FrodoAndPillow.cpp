#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void find_max_value(ll n, ll m, ll k)
{
    m -= n;
    ll l = 0, r = m;

    while (l < r)
    {
        ll mid = (l + r + 1) / 2;
        ll left_pos = min(k - 1, mid - 1);
        ll right_pos = min(n - k, mid - 1);
        ll needed = mid + (ll)((left_pos*mid) - (ll)(left_pos*(left_pos + 1)) / 2) + (ll)((right_pos*mid) - (ll)(right_pos*(right_pos + 1)) / 2);
        if (needed <= m)
            l = mid;
        else
            r = mid - 1;
    }
    cout << l+1 << endl;
}

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    find_max_value(n, m, k);
    return 0;
}