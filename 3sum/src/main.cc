// problem:
// find all triplets that are different and sum to 0, no duplicates.
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // sort the input vector in non-decreasing order
        u_int32_t n = nums.size();
        for (u_int32_t left = 0; left < n - 2; left++) {
            if (left > 0 && nums[left] == nums[left-1]) continue; // skip duplicates
            u_int32_t mid = left + 1;
            u_int32_t right = n - 1;
            while (mid < right) {
                int sum = nums[left] + nums[mid] + nums[right];
                if (sum == 0) {
                    result.push_back({nums[left], nums[mid], nums[right]});
                    mid++;
                    right--;
                    while (mid < right && nums[mid] == nums[mid-1]) mid++; // skip duplicates
                    while (mid < right && nums[right] == nums[right+1]) right--; // skip duplicates
                } else if (sum < 0) {
                    mid++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }

};

int main() {
    vector<int> input = {-1,0,1,2,-1,-4};
    Solution s;
    vector<vector<int>> output = s.threeSum(input);
    return 0;
}