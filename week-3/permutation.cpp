#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int k, vector<int>& nums, vector<int>& current, vector<vector<int>>& permutations, vector<bool>& used){
        if(current.size() == k){
            permutations.push_back(current);
            return;
        }
        for(int i = 0; i < k; i++){
            if(!used[i]){
                current.push_back(nums[i]);
                used[i] = true;
                dfs(k, nums, current, permutations, used);
                used[i] = false;
                current.pop_back();
            }
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        int k = nums.size();
        dfs(k, nums, current, permutations, used);
        return permutations;
    }
};

int main(){
    vector<int> nums = {1, 2, 3}; // Example values
    Solution s;
    vector<vector<int>> result = s.permute(nums);
    for(auto v : result){
        for(auto i : v){
            cout << i << " ";
        }
        cout << endl;
    }
}