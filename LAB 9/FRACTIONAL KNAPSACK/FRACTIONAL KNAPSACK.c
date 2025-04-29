#include <stdio.h>

int n = 5;
int weight[10] = {10, 15, 10, 12, 8};
int value[10]  = {3, 3, 2, 5, 1};
int W = 10;

int main() {
    int cur_w = W;
    float tot_v = 0.0;
    int used[10] = {0};
    int i, maxi;

    while (cur_w > 0) {
        maxi = -1;


        for (i = 0; i < n; ++i) {
            if (!used[i]) {
                if (maxi == -1 || (float)value[i]/weight[i] > (float)value[maxi]/weight[maxi]) {
                    maxi = i;
                }
            }
        }

        used[maxi] = 1;

        if (weight[maxi] <= cur_w) {

            cur_w -= weight[maxi];
            tot_v += value[maxi];
            printf("Added object %d (%d value, %d weight) completely. Remaining capacity: %d\n",
                   maxi + 1, value[maxi], weight[maxi], cur_w);
        } else {
            float fraction = (float)cur_w / weight[maxi];
            tot_v += value[maxi] * fraction;
            printf("Added %.2f%% of object %d (%d value, %d weight).\n",
                   fraction * 100, maxi + 1, value[maxi], weight[maxi]);
            cur_w = 0;
        }
    }

    printf("Total value in knapsack: %.2f\n", tot_v);
    return 0;
}
