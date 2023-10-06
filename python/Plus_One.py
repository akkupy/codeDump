link : https://leetcode.com/problems/plus-one/

solution :

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        result = int(''.join(map(str,digits)))+1
        result = [int(x) for x in str(result)] 
        return result
