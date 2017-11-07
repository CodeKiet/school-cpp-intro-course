/**
 * Student Name: Eitan Sternlicht
 * ID:
 * Exercise: 1
 * Question: 2
 * Program Overview:
 *      Program takes sets of 2 integers at a time until reaches the set 0 0.
 *      After each set the program will print how many digits of the first integer
 *      were present in the second (we are assuming all digits are 10 digits or less)
 */

#include <stdio.h>

int pairCount(int, int);
int digitInNum(int, int);



int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    while(a != 0 || b != 0) {
        printf(" %d\n", pairCount(a, b));
        scanf("%d %d", &a, &b);
    }
    return 0;
}

/**
 * assuming pair is not (0, 0)
 * @param a
 * @param b
 * @return count of how many digits of a are in b
 */
int pairCount(int a, int b) {
    if (a == 0)
        return 0;
    return digitInNum(a % 10, b) + pairCount(a / 10, b);
}

/**
 * checks if digit is in number
 * @param digit
 * @param num
 * @return 1 if digit is in num, 0 if not
 */
int digitInNum(int digit, int num) {
    if (num == 0)
        return 0;
    if (digit == num % 10)
        return 1;
    return digitInNum(digit, num / 10);
}
