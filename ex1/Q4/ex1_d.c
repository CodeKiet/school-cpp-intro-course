#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int digits(int);


int main() {
    srand((unsigned int)time(NULL));

    for (int i = 0; i < 10; ++i) {
        int randomNum = rand();
        printf("\noriginal number: %d", randomNum);

        const int len = digits(randomNum);
        char randomNumStr[len + 1];

        for (int j = len - 1; j >=0; --j, randomNum /= 10) {
            randomNumStr[j] = (char) ((randomNum % 10) + '0');
        }
        randomNumStr[len] = '\0';

        char randomNumStrReversed[len + 1];

        for (int k = 0; k < len; ++k) {
            randomNumStrReversed[k] = randomNumStr[len - k - 1];
        }

        randomNumStrReversed[len] = '\0';

        if (strcmp(randomNumStrReversed, randomNumStr) == 0) {
            printf("\nalready a palindrome: %s", randomNumStr);
        } else {
            printf("\nreversed number: %s", randomNumStrReversed);
            printf("\npalindrome created: %s%s", randomNumStr, randomNumStrReversed);
        }
    }
    return 0;
}

int digits(int x) {
    return (int)log10(x) + 1;
}