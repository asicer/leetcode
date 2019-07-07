#!/usr/local/bin/python3

# from typing import List

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        i = len(a)-1
        j = len(b)-1

        carry = 0
        result = ""

        while i>=0 or j>=0 or carry==1:
            va = a[i] == '1' if i >= 0 else 0
            vb = b[j] == '1' if j >= 0 else 0
            temp = va + vb + carry
            value = temp%2
            carry = int(temp/2)
            result = str(int(value)) + result
            i = i-1
            j = j-1

        return result

s = Solution()
print(s.addBinary("11", ""))
print(s.addBinary("11", "1"))
print(s.addBinary("1010", "1011"))
