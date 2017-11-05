#include <stdio.h>


int main() {
    int numOfSpecials = 0;
    int totalCounter = 0;
    int numOfNumbers = 0;
    double avg = 0;
    int n;
    scanf("%d", &n);
    while (n != -1) {
        if (avg == n) {
            printf("\n%d place: %d\n", n, numOfNumbers + 1);
            numOfSpecials++;
        }
        totalCounter += n;
        numOfNumbers++;
        avg = totalCounter / numOfNumbers;
        scanf("%d", &n);
    }

    printf("\nNumber of special numbers: %d", numOfSpecials);
    return 0;
}