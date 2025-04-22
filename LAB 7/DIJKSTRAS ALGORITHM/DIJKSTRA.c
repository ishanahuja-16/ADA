#include <stdio.h>

#define INF 999
#define MAX 20

void dijkstra(int c[MAX][MAX], int n, int v, int d[MAX]) {
    int s[MAX] = {0};
    int i, j, u, min;

    for (i = 1; i <= n; i++) {
        d[i] = c[v][i];
        s[i] = 0;
    }

    d[v] = 0;
    s[v] = 1;

    for (int k = 2; k <= n; k++) {
        min = INF;
        for (i = 1; i <= n; i++) {
            if (!s[i] && d[i] < min) {
                min = d[i];
                u = i;
            }
        }
        s[u] = 1;

        for (i = 1; i <= n; i++) {
            if (!s[i] && d[i] > d[u] + c[u][i]) {
                d[i] = d[u] + c[u][i];
            }
        }
    }
}

int main() {
    int c[MAX][MAX], d[MAX];
    int n, i, j, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix (999 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    printf("\nEnter the source vertex: ");
    scanf("%d", &v);

    dijkstra(c, n, v, d);

    printf("\nShortest distances from source vertex %d:\n", v);
    for (i = 1; i <= n; i++) {
        if (d[i] == INF)
            printf("Vertex %d is unreachable\n", i);
        else
            printf("To vertex %d = %d\n", i, d[i]);
    }

    return 0;
}
