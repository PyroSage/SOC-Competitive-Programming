#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    int k;
    cin >> k;
    cin >> s;
    int n = s.length();
    ll count = 0ll;
    int sum = 0;
    map<int, long long> m;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            sum++;
        }
        if (sum == k) {
            count++;
        }
        count += m[sum - k];
        m[sum]++;
    }
    cout << count << endl;
    return 0;
}