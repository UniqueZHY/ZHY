/*************************************************************************
	> File Name: ep31.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月22日 星期日 14时45分51秒
 ************************************************************************/

/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 8
#define M 200

int f[N + 5][M + 5];
int w[N + 5] = {1, 2, 5, 10, 20, 50, 100, 200};

int main() {
    for(int i = 0; i < N;i++) {
        f[i][0] = 1;
        for(int j = 1; j <= M; j++) {
            f[i][j] = 0;
            if(i >= 1) f[i][j] += f[i - 1][j];
            if(j >= w[i]) f[i][j] += f[i][j - w[i]];
            //拼凑第I中硬币J元钱W『I』是第I元钱的面值
        }
    }
    printf("%d\n", f[N - 1][M]);
    return 0;
}


*/
/*#include<stdio.h>
#define max_n 8
#define max_m 200

int w[max_n + 5] = {
    1, 2, 5, 10, 20, 50, 100, 200
};
int f[2][max_m + 5];


int main() {
    for (int k = 0; k < max_n; k++) {
        int i = k % 2;
        f[i][0] = 1;//用前i种硬币拼凑0元钱
        //f[i][i] = f[i - 1][i] + f
        for (int j = 1; j <= max_m; j++) {
            f[i][j] = 0;
            f[i][j] += f[i ^ 1][j];//需要0 0^1 = 1
            if (j >= w[k]) f[i][j] += f[i][j - w[k]];
        }
    }
    printf("%d\n", f[(max_n - 1) % 2][max_m]);
    return 0;
}*/

#include<stdio.h>
#define max_n 8
#define max_m 200

int w[max_n + 5] = {
    1, 2, 5, 10, 20, 50, 100, 200
};
int f[max_m + 5];


int main() {
    f[0] = 1;
    for (int i = 0; i < max_n; i++) {
        for (int j = 1; j <= max_m; j++) {
            if (j >= w[i]) f[j] += f[j - w[i]];
        }
    }
    printf("%d\n", f[max_m]);
    return 0;
}
