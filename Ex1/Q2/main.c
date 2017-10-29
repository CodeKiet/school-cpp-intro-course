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
