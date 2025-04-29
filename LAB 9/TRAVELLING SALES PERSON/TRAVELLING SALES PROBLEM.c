#include <stdio.h>
#include <math.h>

int n;
int dist[10][10];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int travelingSalesman(int path[], int visited[], int currentCity, int visitedCount, int totalDistance) {
    if (visitedCount == n) {
        return totalDistance + dist[currentCity][0];
    }

    int minDistance = 9999999;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            minDistance = min(minDistance, travelingSalesman(path, visited, i, visitedCount + 1, totalDistance + dist[currentCity][i]));
            visited[i] = 0;
        }
    }
    return minDistance;
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    int visited[10] = {0};
    visited[0] = 1;

    int result = travelingSalesman(NULL, visited, 0, 1, 0);
    printf("Minimum travel distance: %d\n", result);

    return 0;
}
