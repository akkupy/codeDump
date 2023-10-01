class main {
    public String reverseWords(String s) {
        String[] words = s.split(" ");
        StringBuilder reversed = new StringBuilder();
        for (String word : words) {
            StringBuilder reversedWord = new StringBuilder(word);
            reversedWord.reverse();
            reversed.append(reversedWord).append(" ");
        }
        return reversed.toString().trim();
    }
    public static void main(String[] args) {
        main solution = new main();
    
        String s1 = "Let's take LeetCode contest";
        String result1 = solution.reverseWords(s1);
        System.out.println(result1); 
    
        String s2 = "God Ding";
        String result2 = solution.reverseWords(s2);
        System.out.println(result2); 
    }
}