public class multiArrayList {
    class Solution {
        public static void main(String[] args) {
           ArrayList<ArrayList<String>> items=new ArrayList<>();
           items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]]; 
           String ruleKey = "color";
           String ruleValue = "silver";
           int c=countMatches(items,ruleKey,ruleValue);
           System.out.println(c);
        }
        public int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
               int count = 0;
            for(int i=0; i<items.size(); i++) {
                if(ruleKey.equals("type")) {
                    if(ruleValue.equals(items.get(i).get(0))) {
                        count++;
                    }
                }
                else if(ruleKey.equals("color")) {
                    if(ruleValue.equals(items.get(i).get(1))) {
                        count++;
                    }
                }
                else {
                    if(ruleValue.equals(items.get(i).get(2))) {
                        count++;
                    }
                }
            }   
            return count;
        }
    } 
}
