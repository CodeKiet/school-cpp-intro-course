#include <stdio.h>



int main() {
    const int len = 20;
    int ns[len];
    int upLinesCount = 0;
    int downLinesCount = 0;
    int goingUp;

    for (int j = 0; j < len; ++j) {
        scanf("%d", &ns[j]);
    }

    printf("%d", ns[0]);

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

    if (ns[len - 2] < ns[len - 1])
        upLinesCount++;
    else
        downLinesCount++;


    printf("\nsummary:\n");
    printf("=======\n");
    printf("There are %d ascending lines.\n", upLinesCount);
    printf("There are %d descending lines.\n", downLinesCount);
    return 0;
}
