#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void generatePassword(char *password, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+[]{}|;:,.<>?";
    int charset_size = sizeof(charset) - 1;
    
    srand((unsigned int)time(NULL));

    for (int i = 0; i < length; i++) {
        int index = rand() % charset_size;
        password[i] = charset[index];
    }
    
    password[length] = '\0';
}

int main() {
    int length;
    printf("Enter the desired password length: ");
    scanf("%d", &length);

    if (length <= 0) {
        printf("Password length should be greater than 0.\n");
        return 1;
    }

    char password[length + 1];
    generatePassword(password, length);

    printf("Generated Password: %s\n", password);

    return 0;
}
