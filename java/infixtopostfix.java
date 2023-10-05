package com.company.Stacks;

public class InfixToPostfix {

    public static int precedence(String op){
        if (op == null){
            return -1;
        }
        if (op.equals("*") || op.equals("/")) {
            return 2;
        }
        if (op.equals("+") || op.equals("-")) {
            return 1;
        }
        return -1;
    }

    public static StringBuilder infixToPostfix(String inf, CharStack st){
        StringBuilder post = new StringBuilder();
        int i = 0;
        while (i < inf.length()) {
            if (inf.charAt(i) == '*' || inf.charAt(i) == '/' || inf.charAt(i) == '+' || inf.charAt(i) == '-'){
                if (precedence(inf.substring(i, i + 1)) > precedence(st.stackTop())) {
                    st.push(inf.substring(i, i + 1));
                    i++;
                }
                else{
                    post.append(st.pop());
                }
            }
            else {
                post.append(inf.charAt(i));
                i++;
            }
        }
        while (!st.isEmpty()){
            post.append(st.pop());
        }
        return post;
    }

    public static void main(String[] args) {
        CharStack s = new CharStack(10);
        System.out.println(infixToPostfix("x-y/z-k*d", s));
    }
}