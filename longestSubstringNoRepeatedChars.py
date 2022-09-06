class Solution:

    def lengthOfLongestSubstring(self, s: str, largest=0) -> int:
        largest = largest
        print(f"Length Of String We Are Analyzing {s}: {len(s)}")
        if len(s) == 0:
            return 0
        if len(set(s)) == 1:
            return 1
        if len(s) == len(set(s)):
            return len(s)
        for index in range(len(s)):
            if len(s) - index > largest:
                usedLetters = []
                index1 = 0
                while index1 <= len(s) - index:
                    let = s[index1]
                    if let in usedLetters:
                        if not largest > index1:
                            largest = index1
                            print(f"changed largest to {index1}")
                        if largest >= len(s[index1:len(s)]):
                            return largest
                        return Solution.lengthOfLongestSubstring(self, s[index1:len(s)], largest)
                    usedLetters.append(let)
                    index1+=1
                print(remainingChars, "remaining chars", s[index:len(s)])
