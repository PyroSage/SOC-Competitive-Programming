#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll N = 2e5 + 7;

#define pb push_back
#define endl "\n"
#define f first
#define s second
#define pi 2 * acos(0.0)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

string normalize(string s) {
    if (s.size() & 1) return s;
    string a = normalize(s.substr(0, s.size() / 2));
    string b = normalize(s.substr(s.size() / 2));
    return (a > b) ? (b + a) : (a + b);
}

void solve() {
    string a, b;
    cin >> a >> b;
    if (normalize(a) == normalize(b))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    FAST
    solve();
    return 0;
}
