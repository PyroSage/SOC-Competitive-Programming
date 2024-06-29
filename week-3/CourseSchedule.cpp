#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define vi vector<int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 100005;
vi adj[MAXN];
bool vis[MAXN];
vi order;
int state[MAXN];

void dfs(int node) {
    vis[node] = true;
    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) dfs(neighbor);
    }
    order.pb(node);
}

bool hasCycle(int node) {
    state[node] = 1;
    for (int neighbor : adj[node]) {
        if (state[neighbor] == 0) {
            if (hasCycle(neighbor)) return true;
        } else if (state[neighbor] == 1) {
            return true;
        }
    }
    state[node] = 2;
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    for (int i = 1; i <= n; ++i) {
        if (!state[i] && hasCycle(i)) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) dfs(i);
    }
    reverse(order.begin(), order.end());
    for (int node : order) {
        cout << node << " ";
    }
    cout << "\n";
}

signed main() {
    IOS;
    solve();
    return 0;
}
