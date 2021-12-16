#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool contains(vector<int> triplets, int num) {
        for (int i = 0; i < triplets.size(); i++) {
            if (num == triplets[i]) return true;
        }
        return false;
    }

    bool isDuplicate(vector<vector<int>> triplets, vector<int> nums, int i, int j, int k) {
        //some element in triplets contains nums[i] nums[j] and nums[k]
        for (int l = 0; l < triplets.size(); l++) {
            if (contains(triplets[l], nums[i]) && contains(triplets[l], nums[j]) && contains(triplets[l], nums[k])) return true;
        }
        return false;
    }

    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void bubbleSortDesc(vector<int>& nums) {
        for (int i = 0; i < nums.size()-1; i++) {
            for (int j = 0; j < nums.size() - i - 1; j++) {
                if (nums[j] < nums[j+1])
                swap(nums, j, j+1);
            }
        }
    }


    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        if (nums.size() < 3) return output;
        bubbleSortDesc(nums);
        int i = 0, j = 1, k = nums.size()-1;
        while (k-i >= 2) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0 && !isDuplicate(output, nums, i, j, k)) output.push_back({nums[i], nums[j], nums[k]});
            if (sum >= 0) {
                if (k-j == 1) {
                    i++;
                    j = i+1;
                }
                else j++;
            }
            else {
                k--;
                j = i+1;
            }
        }
        return output;
    }
};

int main() {
    Solution instance;
    vector<int> input = {0, 0, 0};
    vector<vector<int>> triplets = instance.threeSum(input);
    cout << endl;
}

