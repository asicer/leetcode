#!/usr/local/bin/python3

class Solution:
    def isValid(self, s: str) -> bool:
        l = []
        for i in range(len(s)):
            if s[i] is '(' or s[i] is '{' or s[i] is '[':
                l.append(s[i])
            else:
                if len(l) is 0:
                    return False
                elif s[i] is ')':
                    if l.pop() is not '(':
                        return False
                elif s[i] is ']':
                    if l.pop() is not '[':
                        return False
                elif s[i] is '}':
                    if l.pop() is not '{':
                        return False
        return len(l) == 0

s = Solution()
print(s.isValid(""))
print(s.isValid("{"))
print(s.isValid("{[]}"))
