#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int find(vector<int>& nums, int val) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) return i;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        if (copy.size() < 2) return output;
        int low = 0, high = copy.size()-1;
        while (low != high) {
            int sum = copy[low] + copy[high];
            if (sum == target) {
                int trueLowIndex = find(nums, copy[low]);
                int trueHighIndex = find(nums, copy[high]);
                output.push_back(trueLowIndex);
                output.push_back(trueHighIndex);
                low++;
            }
            else if (sum < target) {
                low++;
            }
            else high--;
        }
        return output;
    }
};

int main() {
    vector<int> input = {3, 2, 4};
    int target = 6;
    Solution instance;
    vector<int> output = instance.twoSum(input, target);
    return 0;
}