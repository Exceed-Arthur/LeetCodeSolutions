# Given a string s, find the length of the longest substring without repeating characters.
class Solution:
    def __init__(self):
        self.modified = False    
    def recursiveCharRepeatFinder(self, s:str, start:int, end:int):
        self.modified=False
        for i in range(start, end-1):
            if s[i] == s[i+1]:
                self.modified = True
                return self.recursiveCharRepeatFinder(s[start:i], start, i)
        if not self.modified:
            self.modified = False
            for i in range(3, len(s)):
                if s[0:i] in s[i:len(s)]:
                    self.modified = True
                    return len(s[0:i])            
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxSize = self.recursiveCharRepeatFinder(s, 0, len(s))
        return maxSize
      
