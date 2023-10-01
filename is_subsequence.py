class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
   
        #x=set(s)
        #y=set(t)
        #return x.issubset(y)
        #for i in range(len(s)):
            #for j in range(len(t)):
        i, j = 0, 0
        while i < len(s) and j < len(t):
            if s[i]==t[j]:
                i+=1
            j+=1
        return i==len(s)
                
