#include<bits/stdc++.h>
using namespace std;

const int CON = 2005;
vector<int> g[CON];
int ans[CON];
int root[CON];

void bfs(int v)
{
    queue<pair<int, int> > q;
    q.push(make_pair(v, 1));
    int vis[CON]={0};
    vis[v]=1;
    root[v]=-1;
    pair<int, int> temp;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        for(int i=0;i<g[temp.first].size();i++)
        {
            if(g[temp.first][i]==v)
            {
                while(v!=-1)
                {
                    ans[v]=min(ans[v], temp.second);
                    v=root[v];
                }
                return;
            }
            if(vis[g[temp.first][i]]==0)
            {
                vis[g[temp.first][i]]=1;
                root[g[temp.first][i]]=temp.first;
                q.push(make_pair(g[temp.first][i], temp.second+1));
            }
        }
    }
    ans[v]=-1;
    return;
}

int main()
{
    
    for(int i=0;i<CON;i++)
    {
        ans[i]=200005;
    }
    
    int n, temp;
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d", &temp);
            if(temp==1)
            {
                g[i].push_back(j);
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        if(ans[i]==200005)
        {
            bfs(i);
            if(ans[i]==-1)
            {
                cout << "NO WAY" << endl;
            }
            else
            {
                cout << ans[i] << endl;
            }
        }
        else
        {
            cout << ans[i] << endl;
        }
    }
    
    return 0;
} 