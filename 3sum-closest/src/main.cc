// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closestSum = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        uint32_t n = nums.size();
        for (uint32_t i = 0; i < n-2; i++) {
            uint32_t left = i+1, right = n-1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(sum - target) < abs(closestSum-target)) closestSum = sum;
                if (sum < target) left++;
                else right--;
            }
        }
        return closestSum;
    }
};

int main() {
    Solution s;
    vector<int> input = {-1,2,1,-4};
    int target = 1;
    int output = s.threeSumClosest(input, target);
    cout << "output: " << output << endl;
}