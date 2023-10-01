//link- https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<>();
        if(digits.length() == 0){
            return res;
        }
        allCombi("", digits, res);
        return res;
    }

    public void allCombi(String p, String up,List<String> res ){
        if(up.length() == 0){
            res.add(p);
            return;
        }
        int btn = up.charAt(0) - '0';
        int i=(btn-2)*3;
        if(btn>7) i++;
        int len =i+3;
        if(btn==7 || btn == 9){
            len ++;
        }
        for(int j=i; j<len; j++){
            char ch = (char)('a'+j);
            allCombi(p+ch, up.substring(1), res);
        }
    }
}
