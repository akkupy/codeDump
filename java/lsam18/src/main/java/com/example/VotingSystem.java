package lsam18.src.main.java.com.example;

import java.util.Scanner;

public class VotingSystem {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Initialize candidate and vote count
        String candidateName = "John Doe";
        int voteCount = 0;
        
        System.out.println("Welcome to the Voting System");
        System.out.println("Candidate: " + candidateName);
        
        while (true) {
            System.out.println("\nOptions:");
            System.out.println("1. Vote for " + candidateName);
            System.out.println("2. View Results");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            
            int choice = scanner.nextInt();
            
            switch (choice) {
                case 1:
                    voteCount++;
                    System.out.println("You've voted for " + candidateName);
                    break;
                case 2:
                    System.out.println("Candidate: " + candidateName);
                    System.out.println("Vote Count: " + voteCount);
                    break;
                case 3:
                    System.out.println("Exiting the Voting System");
                    scanner.close();
                    System.exit(0);
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}
