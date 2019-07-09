#!/usr/local/bin/python3

from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic = {}
        for i in range(len(nums)):
            if target-nums[i] in dic:
                return [i, dic[target-nums[i]]]
            dic[nums[i]] = i

s = Solution()
nums = [2, 7, 11, 15]
target = 9
print(s.twoSum(nums, target))
