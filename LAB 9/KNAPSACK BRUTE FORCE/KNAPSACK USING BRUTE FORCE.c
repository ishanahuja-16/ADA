#include <stdio.h>
#include <math.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int weights[], int values[], int n, int W) {
    int maxValue = 0;
    int totalCombinations = pow(2, n);

    for (int i = 0; i < totalCombinations; i++) {
        int currentWeight = 0, currentValue = 0;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                currentWeight += weights[j];
                currentValue += values[j];
            }
        }

        if (currentWeight <= W) {
            maxValue = max(maxValue, currentValue);
        }
    }

    return maxValue;
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];

    printf("Enter the weight of the items: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter the values of the items: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    printf("Maximum value in knapsack = %d\n", knapsack(weights, values, n, W));
    return 0;
}
