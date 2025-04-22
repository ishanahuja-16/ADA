#include <stdio.h>
#include <stdbool.h>

#define LEFT -1
#define RIGHT 1

int getMobile(int a[], int dir[], int n) {
    int mobile = 0, mobileIndex = -1;
    for (int i = 0; i < n; i++) {
        if (dir[i] == LEFT && i > 0 && a[i] > a[i - 1] && a[i] > mobile) {
            mobile = a[i];
            mobileIndex = i;
        }
        if (dir[i] == RIGHT && i < n - 1 && a[i] > a[i + 1] && a[i] > mobile) {
            mobile = a[i];
            mobileIndex = i;
        }
    }
    return mobileIndex;
}

void printPermutation(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void johnsonTrotter(int n) {
    int a[n], dir[n];

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(a, n);

    for (int count = 1; count < 1 << n; count++) {
        int mobileIndex = getMobile(a, dir, n);
        if (mobileIndex == -1)
            break;

        int swapIndex = mobileIndex + dir[mobileIndex];
        int temp = a[mobileIndex];
        a[mobileIndex] = a[swapIndex];
        a[swapIndex] = temp;

        temp = dir[mobileIndex];
        dir[mobileIndex] = dir[swapIndex];
        dir[swapIndex] = temp;

        for (int i = 0; i < n; i++)
            if (a[i] > a[swapIndex])
                dir[i] = -dir[i];

        printPermutation(a, n);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    johnsonTrotter(n);
    return 0;
}
