'''
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
'''
#Leetcode sollution
class Solution(object):
    def twoSum(self, nums, target):
        c = []
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                k = nums[i]+nums[j]
                if k== target:
                    c.append(i)
                    c.append(j)
                    break
        return c
