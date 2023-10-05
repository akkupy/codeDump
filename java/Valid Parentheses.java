class Solution {
    public boolean isValid(String s) {
        
        ArrayDeque<Character> dq = new ArrayDeque<Character>(s.length());
        
        boolean valid = false;
        
        int i;
        for(i=0;i<s.length();i++){
            char c = s.charAt(i);

            if(c=='(' || c=='{' || c=='['){
                dq.add(c);
            }
            
            if(dq.isEmpty()){
                return true;
            }
            
            if(c=='}' && dq.getLast() != '{'){
                return false;
            }
            else{
                dq.removeLast();
            }
            
             if(c==')' && dq.getLast() != '('){
                return false;
            }
            else{
                dq.removeLast();
            }
            
             if(c==']' && dq.getLast() != '['){
                return false;
            }
            else{
                dq.removeLast();
            }
            
        }
        
        
        
        return (true);
    }
}