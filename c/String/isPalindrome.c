//  if a given string is palindrome or not
#include <stdio.h>
#include <string.h>

int main()
{
	char str[20];
    gets(str); // input the string

	// Start from first and
	// last character of str
	int left = 0;
	int right = strlen(str) - 1;

	// Keep comparing characters
	// while they are same
	while (right > left) {
		if (str[left++] != str[right--]) {
			printf("%s is not a palindrome\n", str);
			return 0;
			// will return from here
		}
	}

	printf("%s is a palindrome\n", str);

	return 0;
}
