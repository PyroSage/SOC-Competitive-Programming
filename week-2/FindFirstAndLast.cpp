#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int binary(vector<int>& arr, int n, int target) {
        int low = 0, high = n - 1;
        int result;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                result = mid;
                return result;
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int ans = binary(nums, nums.size(), target);
        result = {ans, ans};
        if (ans == -1) {
            return result;
        }
        while(result[0]-1 >= 0 and nums[result[0]-1] == target){
            result[0]--;
        }
        while(result[1]+1 < nums.size() and nums[result[1]+1] == target){
            result[1]++;
        }
        return result;  
    }
};