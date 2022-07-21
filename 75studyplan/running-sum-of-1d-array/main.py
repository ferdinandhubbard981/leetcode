from typing import List
class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        for i in range(len(nums))[1:]:
            nums[i] += nums[i-1]
        return nums

def main():
    instance = Solution()
    inputArr = [1, 2, 3, 4, 5]
    print(instance.runningSum(inputArr))
    
if __name__ == "__main__":
    main()