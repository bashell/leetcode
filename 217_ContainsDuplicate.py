class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        self.numsSet = set(nums)
        if len(nums) == len(self.numsSet):    ## ����set������Ԫ��Ψһ�Խ���ȥ��
            return False
        return True