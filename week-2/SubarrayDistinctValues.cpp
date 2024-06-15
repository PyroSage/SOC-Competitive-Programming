#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll count(vector<ll>& a, ll n, ll k) {
    int l = 0, r = 0;
    ll ans = 0ll;
    ll distinct = 0ll;
    map<ll, ll> frequency;
    while (r < n)
    {
        if (frequency.find(a[r]) == frequency.end() || frequency[a[r]] == 0)
        {
            distinct++;
        }
        frequency[a[r]]++;
        while (distinct > k)
        {
            frequency[a[l]]--;
            if (frequency[a[l]] == 0)
            {
                distinct--;
            }
            l++;
        }
        ans += r - l + 1;
        r++;
    }
    return ans;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << count(a, n, k) << endl;
    return 0;
}