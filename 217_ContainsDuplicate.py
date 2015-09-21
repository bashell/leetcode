class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        self.numsSet = set(nums)
        if len(nums) == len(self.numsSet):    ## 利用set容器的元素唯一性进行去重
            return False
        return True