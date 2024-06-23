#include <bits/stdc++.h>
using namespace std;

void update(vector<int> ls, map<int, int> &arr, int level)
{
    if (ls.size() == 0)
    {
        return;
    }
    int max = *max_element(ls.begin(), ls.end());
    arr[max] = level;
    int max_index = distance(ls.begin(), find(ls.begin(), ls.end(), max));
    update(vector<int>(ls.begin(), ls.begin() + max_index), arr, level + 1);
    update(vector<int>(ls.begin() + max_index + 1, ls.end()), arr, level + 1);
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ls;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            ls.push_back(temp);
        }
        map<int, int> arr;
        update(ls, arr, 0);
        for (int i = 0; i < n; i++)
        {
            cout << arr[ls[i]] << " ";
        }
        cout << endl;
    }
    return 0;
}