/**
 * Student Name: Eitan Sternlicht
 * ID:
 * Exercise: 1
 * Question: 3
 * Program Overview:
 *      Program reads list of integers from user until reaches -1
 *      After each number it checks whether the number is the same as the
 *      average of all the previous numbers, if so, it prints it with it's
 *      current place in the list.
 *      At the end, the program prints how many of these "special numbers"
 *      were printed in total.
 */
#include <stdio.h>


int main() {
    int numOfSpecials = 0; // how many special numbers were found counter (will be printed in the end
    int totalCounter = 0; // sum total of all input numbers gotten from user
    double avg = -1; // current average of previous elements
    int num;

    scanf("%d", &num);

    for (int i = 1;num != -1; i++) {
        if (avg == num) {
            printf("\n%d place: %d\n", num, i);
            numOfSpecials++;
        }
        totalCounter += num; // add num to new total
        avg = totalCounter / i; // create new average
        scanf("%d", &num);
    }

    printf("\nNumber of special numbers: %d", numOfSpecials);
    return 0;
}