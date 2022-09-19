class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(nums)):
            for j in range(i,len(nums)-1):
                if (nums[i]+nums[j+1]==target):
                    return i,j+1
        return None
