/**
 * Student Name: Eitan Sternlicht
 * ID:
 * Exercise: 1
 * Question: 1
 * Program Overview:
 *      Get 20 numbers from user and output lines split
 *      by ascending and descending lines on each new line.
 *      prints a summary at the end that summarizes how many lines of each there were.
 */

#include <stdio.h>
#include <stdbool.h>
#define LEN 20


int main() {
    int ns[LEN];
    int upLinesCount = 0;
    int downLinesCount = 0;
    bool goingUp;

    for (int j = 0; j < LEN; ++j) {
        scanf("%d", &ns[j]);
    }

    printf("%d", ns[0]);
    // check starting direction of first 2 elements
    if (ns[0] < ns[1])
        goingUp = true;
    else
        goingUp = false;


    for (int i = 1; i < LEN - 1; ++i) {
        if (goingUp == 1) {
            if (ns[i] > ns[i + 1]) {
                goingUp = false;
                upLinesCount++;
                printf(" %d\n%d", ns[i], ns[i]);
            } else {
                printf(" %d", ns[i]);
            }
        } else {
            if (ns[i] < ns[i + 1]) {
                goingUp = true;
                downLinesCount++;
                printf(" %d\n%d", ns[i], ns[i]);
            } else {
                printf(" %d", ns[i]);
            }
        }
    }

    printf(" %d", ns[LEN - 1]);

    // check last two elements which aren't checked in loop
    if (ns[LEN - 2] < ns[LEN - 1])
        upLinesCount++;
    else
        downLinesCount++;


    printf("\nsummary:\n");
    printf("=======\n");
    printf("There are %d ascending lines.\n", upLinesCount);
    printf("There are %d descending lines.\n", downLinesCount);
    return 0;
}
