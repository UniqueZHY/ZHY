/*************************************************************************
	> File Name: ep11.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月19日 星期四 20时01分22秒
 ************************************************************************/

#include<stdio.h>
#define max_n 20
int arr[max_n + 5][max_n + 5];
int dir[4][2] = {
    {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}
};

int cacl(int x, int y) {
    int ans = 0;
    for (int k = 0; k < 4; k++) {
        int p = 1;
        for (int step = 0; step < 4; step++) {
            int dx = x + dir[k][0] * step;
            int dy = y + dir[k][1] * step;
            if(dx < 0 || dx > max_n) break;
            if(dy < 0 || dy > max_n) break;
            p *= arr[dx][dy];
        }
        if (p > ans) ans = p;
    }
    return ans;
}

int main() {
    int ans = 0;
    for (int i = 0; i < max_n; i++){
        for(int j = 0; j < max_n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < max_n; i++) {
        for (int j = 0; j < max_n; j ++) {
            int p = cacl(i, j);
            if(p > ans) ans = p;
        }
    }
    printf("%d\n", ans);
    return 0;
}




/*#include<stdio.h>
#define max_n 20

int grid[max_n + 5][max_n + 5];
int dir[4][2] = {
    {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}
};

int calc(int x, int y) {
    int ans = 0;
    for (int k = 0; k < 4; k++) {
        int p = 1; 
        for (int step = 0; step < 4; step++) {
            int dx = x + dir[k][0] * step;//代表X的偏移量
            //本身的值加上移动的步数在乘以x和y的偏移量
            int dy = y + dir[k][1] * step;//代表Y的偏移量
            if (dx < 0 || dx >= max_n) break;
            if (dy < 0 || dy >= max_n) break;
            p *= grid[dx][dy];
        }
        if (p > ans) ans = p;
    }
    return ans;
}
int main() {
    for (int i = 0; i < max_n; i++) {
        for (int j = 0; j < max_n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    int ans = 0;
    for(int i = 0; i < max_n; i++) {
        for(int j = 0; j < max_n; j++) {
            int p = calc(i, j);
            if (p > ans) ans = p;
        }
    }
    printf("%d\n", ans);
    return 0;
}*/
