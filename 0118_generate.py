#!/usr/local/bin/python3

from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        result= []
        for i in range(numRows):
            temp = []
            for j in range(i+1):
                if j==0 or j==i:
                    s = 1
                else:
                    s = result[i-1][j-1] + result[i-1][j]
                temp.append(s);
            result.append(temp)
        return result

s = Solution()
ls = s.generate(10)
for l in ls:
    print(l)
