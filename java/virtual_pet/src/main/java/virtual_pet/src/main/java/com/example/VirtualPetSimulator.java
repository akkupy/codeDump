package virtual_pet.src.main.java.com.example;

import java.util.Random;
import java.util.Scanner;

class VirtualPet {
    private String name;
    private int hunger;
    private int happiness;

    public VirtualPet(String name) {
        this.name = name;
        this.hunger = 50; // Initialize hunger to a moderate level
        this.happiness = 50; // Initialize happiness to a moderate level
    }

    public void feed() {
        hunger -= 10;
        if (hunger < 0) {
            hunger = 0;
        }
        System.out.println(name + " has been fed. Hunger level: " + hunger);
    }

    public void play() {
        happiness += 10;
        if (happiness > 100) {
            happiness = 100;
        }
        System.out.println(name + " is happy! Happiness level: " + happiness);
    }

    public void checkStatus() {
        System.out.println("Name: " + name);
        System.out.println("Hunger level: " + hunger);
        System.out.println("Happiness level: " + happiness);
    }

    public void update() {
        // Simulate the passage of time, affecting hunger and happiness
        hunger += 5;
        happiness -= 5;

        if (hunger > 100) {
            hunger = 100;
        }

        if (happiness < 0) {
            happiness = 0;
        }
    }
}

public class VirtualPetSimulator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Welcome to the Virtual Pet Simulator!");
        System.out.print("Enter a name for your pet: ");
        String petName = scanner.nextLine();

        VirtualPet pet = new VirtualPet(petName);

        while (true) {
            System.out.println("\nOptions:");
            System.out.println("1. Feed " + petName);
            System.out.println("2. Play with " + petName);
            System.out.println("3. Check " + petName + "'s status");
            System.out.println("4. Quit");

            int choice = scanner.nextInt();

            if (choice == 1) {
                pet.feed();
            } else if (choice == 2) {
                pet.play();
            } else if (choice == 3) {
                pet.checkStatus();
            } else if (choice == 4) {
                System.out.println("Goodbye!");
                scanner.close();
                System.exit(0);
            }

            // Simulate the passage of time and update pet's status
            pet.update();
        }
    }
}
