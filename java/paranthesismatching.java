package com.company.Stacks;

import java.util.Scanner;

public class ParenthesisMatching {

    public static boolean parenthesisMatch(String exp, CharStack st){
        for (int i = 0; i < exp.length(); i++) {
            if (exp.charAt(i) == '('){
                st.push("(");
            }
            else if (exp.charAt(i) == ')'){
                if (st.isEmpty()){
                    return false;
                }
                st.pop();
            }
        }
        return st.isEmpty();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String exp = sc.nextLine();
        CharStack st = new CharStack(exp.length());
        if (parenthesisMatch(exp, st)){
            System.out.println("Parenthesis Match");
        }
        else{
            System.out.println("Parenthesis Missing");
        }
    }
}