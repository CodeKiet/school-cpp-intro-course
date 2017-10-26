#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

void q1();
void q2();
void q3();
void q4();
int digits(int);
int pairCount(int, int);
int digitInNum(int, int);


int main() {
//    q1();
//    q2();
//    q3();
//    q4();
    return 0;
}

void q1() {
    const int len = 20;
    int ns[len];

    for (int j = 0; j < len; ++j) {
        scanf("%d", &ns[j]);
    }
    int upLinesCount = 0;
    int downLinesCount = 0;

    printf("%d", ns[0]);

    int goingUp;
    if (ns[0] < ns[1])
        goingUp = 1;
    else
        goingUp = 0;


    for (int i = 1; i < len - 1; ++i) {
        if (goingUp == 1) {
            if (ns[i] > ns[i + 1]) {
                goingUp = 0;
                upLinesCount++;
                printf(" %d\n%d", ns[i], ns[i]);
            } else {
                printf(" %d", ns[i]);
            }
        } else {
            if (ns[i] < ns[i + 1]) {
                goingUp = 1;
                downLinesCount++;
                printf(" %d\n%d", ns[i], ns[i]);
            } else {
                printf(" %d", ns[i]);
            }
        }
    }

    printf(" %d", ns[len - 1]);
    if (ns[len - 2] < ns[len - 1]) {
        upLinesCount++;
    }
    else {
        downLinesCount++;
    }


    printf("\nsummary:\n");
    printf("=======\n");
    printf("There are %d ascending lines.\n", upLinesCount);
    printf("There are %d descending lines.\n", downLinesCount);
}

void q2() {
    int a, b;
    scanf("%d %d", &a, &b);
    while(a != 0 || b != 0) {
        printf(" %d\n", pairCount(a, b));
        scanf("%d %d", &a, &b);
    }
}

void q3() {
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
}

void q4() {
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
}

int digits(int x) {
    return (int)log10(x) + 1;
}

int pairCount(int a, int b) {
    if (a == 0) {
        if (digitInNum(0, b))
            return 1;
        else
            return 0;
    }

    int count = 0;

    while(a != 0) {
        if (digitInNum(a % 10, b))
            count++;

        a = a / 10;
    }
    return count;
}

int digitInNum(int digit, int num) {
    if (digit == 0 && num == 0)
        return 1;

    int currentDigit;

    while (num != 0) {
        currentDigit = num % 10;
        if (currentDigit == digit)
            return 1;
        num = num / 10;
    }
    return 0;
}
