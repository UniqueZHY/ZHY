/*************************************************************************
	> File Name: erfen.c
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月01日 星期五 10时51分51秒
 ************************************************************************/

#include<stdio.h>
int main()
{
 int b[]={1,2,3,4,5,6,7,8,9,10};
 int left=0,right=9,a,key,i;
 printf("请输入要寻找元素");
 scanf("%d",&key);
 while(left<right)
 {
  	a=(left+right)/2;
  	if(b[a]==key)
     {
      printf("所在位置为:%d\n",a);
      break;
     }
    else if(key>b[a])
      left=a+1;
    else
      right=a-1;
 }
 if(key>10||key<1)
 printf("没找到该元素\n"); 
}

