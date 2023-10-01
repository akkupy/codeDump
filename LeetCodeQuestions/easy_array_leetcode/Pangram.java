public class Pangram {
    public static void main(String[] args) {
        boolean[] arr=new boolean[26];
        String sentence="thequickbrownfoxjumppsoverthelazydog";
        for(int i=0;i<sentence.length();i++){
                arr[sentence.charAt(i)-'a']=true;
        }
        for(int i=0;i<26;i++){
            if(arr[i]==false){
                System.out.println(false);
            }
        }
        System.out.println(true);
    }
}
