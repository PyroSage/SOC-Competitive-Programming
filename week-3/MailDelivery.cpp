#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 100005;
vii adj[MAXN];
int vis[200005];

void solve() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }
    
    for (int i = 1; i <= n; ++i) {
        if (adj[i].size() % 2 != 0) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    
    stack<int> st;
    st.push(1);
    vi path;
    
    while (!st.empty()) {
        int v = st.top();
        bool found = false;
        
        while (!adj[v].empty()) {
            pii edge = adj[v].back();
            adj[v].pop_back();
            int u = edge.first;
            int idx = edge.second;
            if (!vis[idx]) {
                st.push(u);
                vis[idx] = 1;
                found = true;
                break;
            }
        }
        
        if (!found) {
            path.pb(v);
            st.pop();
        }
    }
    
    if (path.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    
    for (int node : path) {
        cout << node << " ";
    }
    cout << "\n";
}

signed main() {
    IOS;
    solve();
    return 0;
}
