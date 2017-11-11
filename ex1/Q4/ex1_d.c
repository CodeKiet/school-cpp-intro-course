/**
 * Student Name: Eitan Sternlicht
 * ID:
 * Exercise: 1
 * Question: 4
 * Program Overview:
 *  This program generates 10 random numbers and prints their
 *  palindromes based on this spec:
 *      1. If the number is a palindrome already: prints it
 *      2. Reverses the number and attaches the reversed number to the end (Thus creating a palindrome)
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define RANDOM_NUMBERS_TO_GENERATE 10

int digits(int);


int main() {
    srand((unsigned int)time(NULL)); // create a random seed based on current time

    for (int i = 0; i < RANDOM_NUMBERS_TO_GENERATE; ++i) {
        int randomNum = rand(); // generate pseudorandom number
        printf("\noriginal number: %d", randomNum);

        int len = digits(randomNum); // len = amount of digits in the number
        char randomNumStr[len + 1]; // create char array of the same size digits as number (+1 for null terminator character)

        randomNumStr[len] = '\0'; // add null terminator at the end of string

        // loop to convert every digit into it's character version and insert into char array
        for (int j = len - 1; j >=0; --j, randomNum /= 10) {
            randomNumStr[j] = (char) ((randomNum % 10) + '0');
        }


        char randomNumStrReversed[len + 1]; // char array to hold reversed number

        randomNumStrReversed[len] = '\0'; // add null terminator at the end of reversed string

        // loop to reverse previous char array
        for (int k = 0; k < len; ++k) {
            randomNumStrReversed[k] = randomNumStr[len - k - 1];
        }


        if (strcmp(randomNumStrReversed, randomNumStr) == 0) {
            // if number == reversedNumber then it's a palindrome
            printf("\nalready a palindrome: %s", randomNumStr);
        } else {
            // not a palindrome
            printf("\nreversed number: %s", randomNumStrReversed);
            // print concatenated number + reversed number to create a palindrome like spec requires
            printf("\npalindrome created: %s%s", randomNumStr, randomNumStrReversed);
        }
    }
    return 0;
}

/**
 * returns amount of digits of any positive integer (e.g. digits(16) == 2)
 * @param x integer to count digits of
 * @return digits in x
 */
int digits(int x) {
    if (x <= 9)
        return 1;
    return 1 + digits(x / 10);
}