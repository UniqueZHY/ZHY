/*************************************************************************
	> File Name: string.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月11日 星期六 16时27分25秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
    char str[1000];
    scanf("%[^\n]", str);
    int len = strlen(str);
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') str[i] = '\n';
    }
    printf("%s\n", str);
    return 0;
}


/*int main() {
    char str[1000];
    scanf("%[^\n]s", str);
    int len = strlen(str);
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') str[i] = '\0';
    }
    int pos = 0;
    while (pos < len) {
        pos += printf("%s", str + pos);
        pos += 1;
        printf("\n");
    }
    return 0;
}*/
