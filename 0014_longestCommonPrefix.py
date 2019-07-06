#!/usr/local/bin/python3

from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) < 1:
            return ""

        result = strs[0]

        for s in strs[1:]:
            r = min(len(s), len(result))
            result = result[:r]
            for i in range(r):
                if s[i] != result[i]:
                    result = result[:i]
                    break

        return result


s = Solution()

l = [""]
print(s.longestCommonPrefix(l))
l = ["a"]
print(s.longestCommonPrefix(l))
l = ["aa","a"]
print(s.longestCommonPrefix(l))
l = ["flower","flow","flight"]
print(s.longestCommonPrefix(l))
