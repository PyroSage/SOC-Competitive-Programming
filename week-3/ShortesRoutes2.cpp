#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
ll ninf=-1e18;
ll inf=1e18;

int main()
{
	ll n,m,q;
	cin>>n>>m>>q;

    vector<vector<ll>> dis(n+1,vector<ll> (n+1,inf));

    for(int i=1;i<=n;i++)
    {
        dis[i][i]=0;
    }
    
    for(int i=0;i<m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        dis[u][v]=min({dis[u][v],w,dis[v][u]});
        dis[v][u]=min({dis[u][v],w,dis[v][u]});
    }

    for(int via=1;via<=n;via++)
    {

        for(int u=1;u<=n;u++){

            for(int v=1;v<=n;v++){

                dis[u][v]=min(dis[u][v],dis[u][via]+dis[via][v]);
            }
        }
    }

    while(q--)
    {
        ll u,v;
        cin>>u>>v;
        if(dis[u][v]==inf)cout<<-1<<endl;
        else cout<<dis[u][v]<<endl;
    }

}