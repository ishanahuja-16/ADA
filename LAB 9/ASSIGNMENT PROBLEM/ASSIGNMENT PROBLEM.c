#include <stdio.h>
#include <stdlib.h>

int cost[3][3], n;

int calculateCost(int perm[]) {
    int totalCost = 0;
    for (int i = 0; i < n; i++) {
        totalCost += cost[i][perm[i]];
    }
    return totalCost;
}

void generatePermutations(int perm[], int l, int r, int *minCost) {
    if (l == r) {
        int currentCost = calculateCost(perm);
        if (currentCost < *minCost) {
            *minCost = currentCost;
        }
    } else {
        for (int i = l; i <= r; i++) {
            int temp = perm[l];
            perm[l] = perm[i];
            perm[i] = temp;

            generatePermutations(perm, l + 1, r, minCost);

            temp = perm[l];
            perm[l] = perm[i];
            perm[i] = temp;
        }
    }
}

int main() {
    printf("Enter the number of workers/jobs: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    int perm[n];
    for (int i = 0; i < n; i++) {
        perm[i] = i;
    }

    int minCost = 9999999;
    generatePermutations(perm, 0, n - 1, &minCost);

    printf("Minimum cost for assignment: %d\n", minCost);
    return 0;
}
