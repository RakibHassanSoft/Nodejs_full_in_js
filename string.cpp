


//----------------------------------12-------------------------


//----------------------------------11-------------------------
// #include <stdio.h>
// #include <string.h>

// int sumDigitsInString(char str[]) {
//     int sum = 0;
//     int i = 0;

//     // Traverse the string
//     while (str[i] != '\0') {
//         // Check if the character is a digit
//         if (str[i] >= '0' && str[i] <= '9') {
//             sum += str[i] - '0';  // Convert the character to its integer value and add to sum
//         }
//         i++;
//     }

//     return sum;
// }

// int main() {
//     char str[1000];

//     printf("Enter a string: ");
//     fgets(str, sizeof(str), stdin);



//     int sum = sumDigitsInString(str);

//     printf("Sum of digits: %d\n", sum);

//     return 0;
// }


//----------------------------------10-------------------------
// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// int isPalindrome(char str[]) {
//     int start = 0;
//     int end = strlen(str) - 1;

//     while (start < end) {
//         // Skip non-alphabetic characters by checking if the character is a letter
//         if ((str[start] < 'A' || (str[start] > 'Z' && str[start] < 'a') || str[start] > 'z')) {
//             start++;
//         } else if ((str[end] < 'A' || (str[end] > 'Z' && str[end] < 'a') || str[end] > 'z')) {
//             end--;
//         } else {
//             // Compare characters (case insensitive)
//             if (tolower(str[start]) != tolower(str[end])) {
//                 return 0; // Not a palindrome
//             }
//             start++;
//             end--;
//         }
//     }
//     return 1; // It's a palindrome
// }

// int main() {
//     char str[1000];

//     printf("Enter a string: ");
//     fgets(str, sizeof(str), stdin);


//     if (isPalindrome(str)) {
//         printf("yes\n");
//     } else {
//         printf("no\n");
//     }

//     return 0;
// }


//----------------------------------9-------------------------
// #include <stdio.h>
// #include <ctype.h> // For tolower() function

// int countOccurrences(char str[], char ch) {
//     int count = 0;
//     int i = 0;
    
//     // Convert input character to lowercase for case-insensitive comparison
//     ch = tolower(ch);

//     while (str[i] != '\0') {
//         // Compare each character in the string with the input character (case-insensitive)
//         if (tolower(str[i]) == ch) {
//             count++;
//         }
//         i++;
//     }

//     return count;
// }

// int main() {
//     char str[1000], ch;

//     printf("Enter a string: ");
//     fgets(str, sizeof(str), stdin);

//     printf("Enter a character to count: ");
//     scanf("%c", &ch);

//     int occurrences = countOccurrences(str, ch);

//     printf("Occurrences of '%c': %d\n", ch, occurrences);

//     return 0;
// }


//----------------------------------7-------------------------
// #include <stdio.h>

// void toggleCase(char str[]) {
//     int i = 0;

//     while (str[i] != '\0') {
//         // Toggle the case of the character
//         if (str[i] >= 'a' && str[i] <= 'z') {
//             str[i] = str[i] - 'a' + 'A';  // Convert to uppercase
//         } else if (str[i] >= 'A' && str[i] <= 'Z') {
//             str[i] = str[i] - 'A' + 'a';  // Convert to lowercase
//         }
//         i++;
//     }
// }

// int main() {
//     char str[1000];

//     printf("Enter a string: ");
//     fgets(str, sizeof(str), stdin);

//     toggleCase(str);

//     printf("Toggled case string: \"%s\"\n", str);

//     return 0;
// }


//----------------------------------6-------------------------
// #include <stdio.h>

// void toUpperCase(char str[]) {
//     int i = 0;

//     while (str[i] != '\0') {
//         // Check if character is lowercase and convert to uppercase
//         if (str[i] >= 'a' && str[i] <= 'z') {
//             str[i] = str[i] - 'a' + 'A';
//         }
//         i++;
//     }
// }

// int main() {
//     char str[1000];

//     printf("Enter a string: ");
//     fgets(str, sizeof(str), stdin);

   
//     toUpperCase(str);

//     printf("Uppercase string: \"%s\"\n", str);

//     return 0;
// }

//----------------------------------5-------------------------
// #include <stdio.h>

// void reverseString(char str[]) {
//     int start = 0, end = 0;

//     // Find the length of the string
//     while (str[end] != '\0') {
//         end++;
//     }
//     end--; // Move to last character (ignore null terminator)

//     // Swap characters from start to end
//     while (start < end) {
//         char temp = str[start];
//         str[start] = str[end];
//         str[end] = temp;

//         start++;
//         end--;
//     }
// }

// int main() {
//     char str[1000];

//     printf("Enter a string: ");
//     fgets(str, sizeof(str), stdin);

//     reverseString(str);

//     printf("Reversed string: \"%s\"\n", str);

//     return 0;
// }

//----------------------------------4-------------------------
// #include <stdio.h>

// int countWords(char str[]) {
//     int count = 0, i = 0;
//     int inWord = 0;

//     while (str[i] != '\0') {
//         if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t') {
//             if (inWord == 0) {
//                 count++;      // Starting a new word
//                 inWord = 1;
//             }
//         } else {
//             inWord = 0;       // Outside of word
//         }
//         i++;
//     }

//     return count;
// }

// int main() {
//     char str[1000];

//     printf("Enter a string: ");
//     fgets(str, sizeof(str), stdin);

//     // Remove newline if present
//     for (int i = 0; str[i] != '\0'; i++) {
//         if (str[i] == '\n') str[i] = '\0';
//     }

//     int wordCount = countWords(str);
//     printf("%d\n", wordCount);

//     return 0;
// }


//----------------------------------3-------------------------

// #include <stdio.h>

// int countVowels(char str[]) {
//     int count = 0;
//     int i = 0;

//     while (str[i] != '\0') {
//         char ch = str[i];

//         // Check for vowels (both lowercase and uppercase)
//         if (ch == 'a' || ch == 'e' || ch == 'i' ||
//             ch == 'o' || ch == 'u' ||
//             ch == 'A' || ch == 'E' || ch == 'I' ||
//             ch == 'O' || ch == 'U') {
//             count++;
//         }

//         i++;
//     }

//     return count;
// }

// int main() {
//     char str[1000];

//     printf("Enter a string: ");
//     fgets(str, sizeof(str), stdin);

//     int vowels = countVowels(str);
//     printf("%d\n", vowels);

//     return 0;
// }

//----------------------------------2-------------------------

// #include <stdio.h>

// int main() {
//     char str1[100], str2[100], result[200];
//     int i = 0, j = 0;

//     printf("Enter first string: ");
//     gets(str1); // allows spaces (use fgets in safer code)

//     printf("Enter second string: ");
//     gets(str2);

//     // Copy str1 to result
//     while (str1[i] != '\0') {
//         result[i] = str1[i];
//         i++;
//     }

//     // Append str2 to result
//     while (str2[j] != '\0') {
//         result[i] = str2[j];
//         i++;
//         j++;
//     }

//     result[i] = '\0'; // End the string

//     printf("Concatenated string: %s\n", result);

//     return 0;
// }

//----------------------------------1-------------------------

// #include <stdio.h>

// int findLength(char str[]) {
//     int length = 0;
//     while (str[length] != '\0') {
//         length++;
//     }
//     return length;
// }

// int main() {
//     char input[1000];

//     printf("Enter a string: ");
//     fgets(input, sizeof(input), stdin); 

//     int length = findLength(input);
//     printf("%d\n", length-1);

//     return 0;
// }
