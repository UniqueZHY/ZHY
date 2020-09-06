/*************************************************************************
	> File Name: jsk_矩阵螺旋输出.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月28日 星期五 13时43分15秒
 ************************************************************************/

#include <stdio.h>
int cnt = 0, n, m;//m行n列矩阵

void out() {
    cnt++;
    if (cnt == n * m) printf("\n");
    else printf(" ");
    return ;
}

int main() {
    int matrix[100][100];
    int x[4] = {0, 1, 0, -1}, y[4] = {1, 0, -1, 0};
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m ; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int dir, l, i, j;
    dir = l = i = j = 0;
    while (cnt < n * m) {
        printf("%d", matrix[i][j]);
        if (x[dir] != 0) {//上下
            if (i + x[dir] >= m - l || i + x[dir] <= l) {
                dir++;
            }
            if (dir == 4) {
                dir = 0;
                l++;
            }
        } else {
            if (j + y[dir] >= n - l || j + y[dir] < l) {
                dir++;
            }
        }
        i += x[dir];
        j += y[dir];
        out();
    }
    return 0;
}
