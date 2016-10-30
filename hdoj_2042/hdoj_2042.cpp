//
// Created by Harlan1994 on 2016/10/30.
//

#include <stdio.h>

int main() {
    int n, a;
    int f[1001] = {0, 4};
    scanf("%d", &n);
    for (int i = 2; i < 1000; i++) {
        f[i] = (f[i - 1] - 1) * 2;
    }
    while (n--) {
        scanf("%d", &a);
        printf("%d\n", f[a]);
    }
    return 0;
}