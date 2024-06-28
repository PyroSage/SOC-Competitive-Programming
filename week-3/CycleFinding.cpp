#include <bits/stdc++.h>
#define ll long long int
#define INF 1000000000000000
#define pb push_back

using namespace std;

vector<pair<ll, ll> > graph[2501];

ll dist[2501];
ll par[2501];
ll cnt[2501];

ll n, m, u, v, w, q;
bool in_queue[2501];
bool visited[2501];
ll x;
bool spfa(ll start)
{
    dist[start] = 0;
    par[start] = -1;

    queue<ll> q;

    q.push(start);
    in_queue[start] = true;

    while (!q.empty()) {
        ll ele = q.front();
        visited[ele] = true;
        in_queue[ele] = false;
        q.pop();
        for (auto child : graph[ele]) {
            if (dist[child.first]
                > dist[ele] + child.second) {
                cnt[child.first]++;
                if (cnt[child.first] > n) {
                    x = child.first;
                    par[child.first] = ele;
                    return false;
                }
                dist[child.first]
                    = dist[ele] + child.second;
                if (!in_queue[child.first]) {
                    q.push(child.first);
                    in_queue[child.first] = true;
                }
                par[child.first] = ele;
            }
        }
    }
    return true;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        dist[i] = INF;
    vector<vector<ll> > edges;
    for (ll i = 0; i < m; i++) {
        cin >> u >> v >> w;
        edges.pb({ u, v, w });
    }
    for (ll i = 0; i < m; i++) {
        graph[edges[i][0]].push_back(
            { edges[i][1], edges[i][2] });
    }
    for (ll i = 1; i <= n; i++) {
        if (!spfa(i)) {
            cout << "YES" << endl;
            ll ele = x;
            stack<ll> st;
            bool is_stack[2501] = {};
            while (!is_stack[ele]) {
                is_stack[ele] = true;
                st.push(ele);
                ele = par[ele];
            }
            cout << ele << " ";
            while (st.top() != ele) {
                cout << st.top() << " ";
                st.pop();
            }
            cout << ele << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}