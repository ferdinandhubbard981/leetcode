#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int previousNum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (previousNum = nums[i]) nums.erase(nums.begin() + --i);
            previousNum = nums[i];
        }
        return nums.size();
    }
};


int main() {
    Solution s;
    vector<int> input = {1, 2, 2, 3};
    int output = s.removeDuplicates(input);
}class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int previousNum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (previousNum = nums[i]) nums.erase(nums.begin()+i-1);
        }
        return nums.size();
    }
};
