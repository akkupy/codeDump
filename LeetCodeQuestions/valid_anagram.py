class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        x=''.join(sorted(s))
        y=''.join(sorted(t))
        return x==y
