#include <iostream>
#include <vector>
using namespace std;

int binary(vector<int>& arr, int low, int high, int target) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        if (nums[0] <= nums[nums.size() - 1]) {
            return binary(nums, 0, nums.size() - 1, target);
        }
        
        int pivot = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                pivot = i;
                break;
            }
        }
        
        if (target >= nums[0] && target <= nums[pivot]) {
            return binary(nums, 0, pivot, target);
        } else if (target >= nums[pivot + 1] && target <= nums[nums.size() - 1]) {
            return binary(nums, pivot + 1, nums.size() - 1, target);
        }
        
        return -1;
    }
};