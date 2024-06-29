#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define vi vector<int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 100005;
vi adj[MAXN];
int vis[MAXN];
vi cyc;

bool dfs(int node) {
    vis[node] = 1;
    for (int neighbor : adj[node]) {
        cyc.pb(neighbor);
        if (vis[neighbor] == 0) {
            if (dfs(neighbor)) return true;
        } else if (vis[neighbor] == 1) {
            return true;
        }
        cyc.pop_back();
    }
    vis[node] = 2;
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            cyc.pb(i);
            if (dfs(i)) {
                vi ans = {*cyc.rbegin()};
                for (auto it = cyc.rbegin() + 1; it != cyc.rend(); ++it) {
                    ans.pb(*it);
                    if (*it == *cyc.rbegin()) break;
                }
                reverse(ans.begin(), ans.end());
                cout << ans.size() << '\n';
                for (int x : ans) cout << x << " ";
                return;
            }
            cyc.pop_back();
        }
    }

    cout << "IMPOSSIBLE\n";
}

signed main() {
    IOS;
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
