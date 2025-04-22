#include <stdio.h>

#define MAX 20

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int knapsack(int n, int weight[], int profit[], int capacity) {
    int i, w;
    int K[MAX][MAX];


    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            } else if (weight[i] <= w) {
                K[i][w] = max(profit[i] + K[i-1][w - weight[i]], K[i-1][w]);
            } else {
                K[i][w] = K[i-1][w];
            }
        }
    }


    printf("\nDP Table:\n");
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            printf("%4d", K[i][w]);
        }
        printf("\n");
    }

    return K[n][capacity];
}

int main() {
    int n, i, capacity;
    int weight[MAX], profit[MAX];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of items:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
    }

    printf("Enter the profits of items:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &profit[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    int maxProfit = knapsack(n, weight, profit, capacity);
    printf("\nMaximum profit that can be obtained: %d\n", maxProfit);

    return 0;
}
