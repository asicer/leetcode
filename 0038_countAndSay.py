#!/usr/local/bin/python3

# from typing import List

class Solution:
    def countAndSay(self, n: int) -> str:
        result = "1"
        for i in range(1,n):
            value = result[0]
            count = 1
            tempS = ""
            if len(result) is 1:
                result = tempS + str(count) + value
                continue
            for j in range(1, len(result)):
                if result[j] is value:
                    count = count + 1
                else:
                    tempS = tempS + str(count) + value
                    value = result[j]
                    count = 1
            tempS = tempS + str(count) + value
            result = tempS
        return result

s = Solution()
print("Result is: "+s.countAndSay(5))
