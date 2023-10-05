class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        x=set()
        for i in nums:
            if i in x:
                return True
            else:
                x.add(i)
        return False
