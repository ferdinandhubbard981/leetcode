    #include <bits/stdc++.h>

    using namespace std;

    class Solution {
    public:
        int maxArea(vector<int>& height) {
            int maxArea = 0;
            int i = 0, j = height.size() - 1;
            while (i != j) {
                //find smallest height index between i and j
                int smallestHeightIndex = (height[i] < height[j]) ? i : j;
                //check if area is greater than maximum
                int currentArea = (j-i) * height[smallestHeightIndex];
                maxArea = (currentArea > maxArea) ? currentArea : maxArea;
                //increment or decrement i or j depending on smallest height
                if (smallestHeightIndex == i) i++;
                else j--;
                
            }
            return maxArea;
        }
    };


int main()  {

}