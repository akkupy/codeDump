package com.ayush;

import java.util.Scanner;

public class SwapNumbers {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter Two Numbers: ");
        int a = in.nextInt();
        int b = in.nextInt();

        //Swap Numbers code
        int temp = a;
        a = b;
        b = temp;
        System.out.println("Swap: " + a + " " + b);
    }
}
