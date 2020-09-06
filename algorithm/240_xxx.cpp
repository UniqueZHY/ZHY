/*************************************************************************
	> File Name: 240_xxx.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月11日 星期三 18时16分08秒
 ************************************************************************/
/*
X n == 1
-
X X
 X   n == 2
X X
-
X X   X X
 X     X
X X   X X
   X X      n == 3
    X
   X X
X X   X X
 X     X
X X   X X
-
X X   X X         X X   X X
 X     X           X     X
X X   X X         X X   X X
   X X               X X
    X                 X
   X X               X X
X X   X X         X X   X X
 X     X           X     X
X X   X X         X X   X X
         X X   X X
          X     X
         X X   X X
            X X
             X                n == 4
            X X
         X X   X X
          X     X
         X X   X X
X X   X X         X X   X X
 X     X           X     X
X X   X X         X X   X X
   X X               X X
    X                 X
   X X               X X
X X   X X         X X   X X
 X     X           X     X
X X   X X         X X   X X
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
char ans[2200][2200];//答案数组
int num[10] = {0, 1, 3, 9, 27, 81, 243, 729};//1到7的边长
//将n的图形在左上左下右上右下中间这五个方向上用n - 1的图形弄出来
void func(int x, int y, int n) {
    if (n == 1) {
        ans[x][y] = 'X';
        return ;
    }
    func(x, y, n - 1);//左上
    func(x, y + num[n] / 3 * 2, n - 1);//左下
    func(x + num[n] / 3 * 2, y, n - 1);//右上
    func(x + num[n] / 3 * 2, y + num[n] / 3 * 2, n - 1);//右下
    func(x + num[n] / 3, y + num[n] / 3, n - 1);//中间
}

int main() {
    func(1, 1, 7);
    int n;
    while (cin >> n) {
        if (n == -1) {
            break;
        }
        for (int i = 1; i <= num[n]; i++) {
            for (int j = 1; j <= num[n]; j++) {
                if (ans[i][j] == 'X') cout << 'X';
                else cout << ' ';
            }
            cout << endl;
        }
        cout << '-' << endl;
    }
    return 0;
}
