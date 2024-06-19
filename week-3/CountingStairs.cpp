#include <bits/stdc++.h>
using namespace std;

class Solution {
    int x, y;
public:
    int count(int n, map<int, int> & m){
        if (n <= m.size()){
            return m[n];
        }
        x = count(n-1, m);
        y = count(n-2, m);
        m[n] = x + y;
        return m[n];
    }
    int climbStairs(int n) {
        map<int, int> m = {{1, 1}, {2, 2}, {3, 3}};
        return count(n, m);
    }
};

int main(){
    Solution s;
    cout << s.climbStairs(10) << endl;
    return 0;
}