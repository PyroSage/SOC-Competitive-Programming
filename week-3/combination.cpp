#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int n, int k, int start, vector<int>& current, vector<vector<int>>& combinations){
        if(current.size() == k){
            combinations.push_back(current);
            return;
        }
        for(int i = start; i <= n; i++){
            current.push_back(i);
            dfs(n, k, i+1, current, combinations);
            current.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> current;
        dfs(n, k, 1, current, combinations);
        return combinations;
    }
};

int main(){
    int n = 4; // Example values
    int k = 2;
    Solution s;
    vector<vector<int>> result = s.combine(n, k);
    for(auto v : result){
        for(auto i : v){
            cout << i << " ";
        }
        cout << endl;
    }
}