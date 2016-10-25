//
// Created by Harlan1994 on 2016/10/25.
//

#include<stdio.h>
#include<string.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, v, i, j;
        int val[1005], cost[1005], f[1005];
        memset(val, 0, sizeof(val));
        memset(cost, 0, sizeof(cost));
        memset(f, 0, sizeof(f));
        scanf("%d%d", &n, &v);
        for (i = 1; i <= n; i++)
            scanf("%d", &val[i]);
        for (i = 1; i <= n; i++)
            scanf("%d", &cost[i]);
        for (i = 1; i <= n; i++)
            for (j = v; j >= cost[i]; j--) {
                f[j] = f[j] > (f[j - cost[i]] + val[i]) ? f[j] : (f[j - cost[i]] + val[i]);
            }
        printf("%d\n", f[v]);
    }
    return 0;
}