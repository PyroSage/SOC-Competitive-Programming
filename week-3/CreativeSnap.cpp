#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define out1d(arr,size) {for(int i=0;i<size;i++) cout<<arr[i]<<" ";}
#define in2d(arr,row,col) for(int i=0;i<row;i++) for(int j=0;j<col;j++) cin>>arr[i][j];
#define out2d(arr,row,col) {for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cout<<arr[i][j]<<" ";cout<<endl;}}

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ll N = 1e5 + 7;

ll n, k, A, B;
vector<ll> pos;

ll fun(ll l,ll r)
{
	
	if(l>r)
		return 0;

	vector<ll>:: iterator lower,upper;
	lower=lower_bound(pos.begin(), pos.end(),l);
	upper=upper_bound(pos.begin(),pos.end(),r);

	if(lower==upper)
		return A;

	ll length=upper-lower;
	ll mx=B*length*(r-l+1);

	if(l==r)
		return mx;

	ll mid=(l+r)/2;
	mx=min(mx,fun(l,mid)+fun(mid+1,r));
	return mx;


}

void solve()
{
    cin >> n >> k >> A >> B;
    ll x;
    for(ll i = 0; i < k; i += 1)
    {
        cin >> x;
        pos.pb(x);
    }

    sort(pos.begin(),pos.end());
    ll ans=fun(1,pow(2,n));
    cout<<ans;
}

int main()
{
    sync;
    int testCases = 1;
    while (testCases--)
    {
        solve();
        cout << '\n';
    }
    return 0;
}