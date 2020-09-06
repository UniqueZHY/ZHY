/*************************************************************************
	> File Name: T1114.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年09月11日 星期三 20时08分25秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 80
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char s[N + 1],t[N + 1];
int main() {
	int i,j,lens,lent;
	gets(s);
	gets(t);
	lens = strlen(s);
	lent = strlen(t);
	for(i = 0; i < lens; i++)
		s[i] = tolower(s[i]);
	for(j = 0; j < lens; j++)
		t[j] = tolower(t[j]);
	if(lens > lent) 
	{
		for(i = 0; i < lens;) {
			if(t[i] == s[i]){
				i++;	}
			else if(t[i] < s[i]) {
				printf(">");
				break;
			} else if(t[i] > s[i]) {
				printf("<");
				break;
			}
		}
		if(i == lens)
			printf("=\n");
 
	}
     else
	{
		for(i = 0; i < lent;) {
			if(s[i] == t[i])
				i++;
			else if(s[i] > t[i]) {
				printf(">");
				break;
			} else if(s[i] < t[i]) {
				printf("<");
				break;
			}
		}
		if(i == lent)
			printf("=\n");
 
	}
	return 0;
}