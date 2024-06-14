#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solver(vector<ll>& arr, ll n, ll x)
{
    // building a 2D vector storing the value and the index of the element
    vector<vector<ll>> vec(n, vector<ll>(2));
    ll first, second, third, fourth;
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        vec[i][0] = arr[i];
        vec[i][1] = i + 1;
    }
    // sorting the vector in ascending order
    sort(vec.begin(), vec.end());

    for(first = 0; first < n - 3; first++)
    {
        for(second = first + 1; second < n - 2; second++)
        {
            third = second + 1;
            fourth = n - 1;
            while(third < fourth)
            {
                sum = vec[first][0] + vec[second][0] + vec[third][0] + vec[fourth][0];

                if(sum == x)
                {
                    cout << vec[first][1] << " " << vec[second][1] << " " << vec[third][1] << " " << vec[fourth][1] << endl;
                    return;
                }
                else if (sum < x)
                {
                    third++;
                }
                else if (sum > x)
                {
                    fourth--;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return;
}

int main()
{
    ll n, x;
    cin >> n >> x;
    if(n < 4)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    solver(arr, n, x);
    return 0;
}
