import heapq

class Solution:
    def minimumCostSimpler(self, nums: list[int]) -> int:
        mins = heapq.nsmallest(2, nums[1:])
        return nums[0] + sum(mins)
    
    def minimumCost(self, nums: list[int]) -> int:
        min1 = 100
        min2 = 100
        for i in range(1, len(nums)):
            if(nums[i] < min1):
                min2 = min1
                min1 = nums[i]
            elif(nums[i] < min2):
                min2 = nums[i]
        return nums[0] + min1 + min2