#!/usr/local/bin/python3

# from typing import List

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        res = -1
        needleSize = len(needle)
        haystackSize = len(haystack)

        if needleSize is 0 and haystackSize is 0:
            return 0

        # for i in range(haystackSize):
        for i in range(haystackSize-needleSize+1):
            if (haystack[i:i+needleSize] == needle):
                res = i
                break

        return res

s = Solution()

haystack, needle = "", ""
print(s.strStr(haystack, needle))
haystack, needle = "hello", "ll"
print(s.strStr(haystack, needle))
