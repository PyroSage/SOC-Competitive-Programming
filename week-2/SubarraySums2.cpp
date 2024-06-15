#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll count(vector<ll>& a, ll k) {
    ll count = 0ll;
    ll sum = 0ll;
    map<ll, ll> sumcount;
    sumcount[0] = 1;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i];
        count += sumcount[sum - k];
        sumcount[sum]++;
    }
    return count;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << count(a, k) << endl;
    return 0;
}