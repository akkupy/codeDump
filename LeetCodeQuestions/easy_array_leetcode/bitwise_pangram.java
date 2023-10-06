public class bitwise_pangram {
    public static void main(String[] args) {
        String sentence="thequickbrownfoxjumppsoverthelazydog";
        int res=0;
        for (int i = 0; i < sentence.length(); i++) {
            res |=(1<<(sentence.charAt(i)-1));
        }
        if(res==((1<<26)-1)){
            System.out.println(true);
        }else
        System.out.println(false);
    }
}
