/*************************************************************************
	> File Name: 151_双手石头剪刀布.cpp
	> Author: zhanghongyan 
	> Mail: 
	> Created Time: 2019年11月08日 星期五 17时11分43秒
 ************************************************************************/
/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath> 
using namespace std;
int main()  {
  char a1 , a2 , b1 , b2;//a1小明左手 ， a2小明右手，b1李华左手 ，b2 李华右手
  cin >>a1 >>a2 >> b1 >> b2;
  if(a1 == 'Y' && b1 == 'H' || a1 == 'H' && b1 == 'O' ||a1 == 'O' && b1 == 'Y') {
    if((a2 == 'Y' && b2 == 'H' || a2 == 'H' && b2 =='O' ||a2 =='O' && b2 == 'Y') || a2 == b2 ){
      cout <<"MING";
    }
    if(a1 == 'Y' && b2 =='O' || a1 =='O' && b2 == 'H' ||a2 == 'H' && b2 == 'Y') {
      if(a2 =='Y' && b2 =='H' || a2 == 'O' && b2 == 'Y' || a2 == 'H' && b2 =='O') {
        cout <<"MING";
      }else if(a2 == b2) {
        cout<<"LIHUA";
      }
    }
  }
  if(a1 == b1) {
    if(a2 == 'Y' && b2 == 'H' || a2 == 'H' && b2 == 'O' || a2 == 'O' && b2 =='Y') {
      cout<<"MING";
    }else if(a2 == b2){
      cout<<"TIE";
    }else {
      cout<<"LIHUA";
    }
  }
  if(a1 == 'Y' && b1 =='O' ||a1 =='O' && b1 == 'H' || a1 =='H' && b1 == 'Y') {
    if((a2 == b1) || (a2 == 'Y' && b1 == 'O' || a2 =='O' && b1 == 'H' ||a2 =='H' && b1 == 'Y')) {
        cout<<"LIHUA";
    }
    if(a2 =='Y' && b1 == 'H' ||a2 == 'H' && b2 == 'O' ||a2 == 'O' && b2 =='Y') {
      if(a2 =='Y' && b2 =='O' || a2 == 'H' && b2 == 'Y'||a2 =='O'&& b2 ==  'H' ) {
        cout<<"LIHUA";
      }
      else {
        cout<<"MING";
      }
    }
  }
  return 0;
}*/
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int judg(int a, int b) {
  if (a == 'O' && b == 'Y') {
    return 1;
  }
  else if (a == 'Y' && b == 'O') {
    return -1;
  }
  else if (a == 'Y' && b == 'H') {
    return 1;
  }
  else if (a == 'H' && b == 'Y') {
    return -1;
  }
  else if (a == 'H' && b == 'O') {
    return 1;
  }
  else if (a == 'O' && b == 'H') {
    return -1;
  }
  else {
    return 0;
  }
}
int main() {
  char a, b, c, d;
  cin >> a >> b >> c >> d;
  if (judg(a, c) > 0) {
    if (judg(a, d) >= 0) {
      cout << "MING" << endl;
    }
    else {
      if (judg(b, d) == 1) {
        cout << "MING" << endl;
      }
      else {
        cout << "LIHUA" << endl;
      }
    }
  }
  else if (!judg(a, c)){
    if (judg(b, d) == 1) {
      cout << "MING" << endl;
    }
    else if (judg(b, d) == 0) {
      cout << "TIE" << endl;
    }
    else {
      cout << "LIHUA" << endl;
    }
  }
  else {
    if (judg(b, c) <= 0) {
      cout << "LIHUA" << endl;
    }
    else {
      if (judg(b, d) >= 0) {
        cout << "MING" << endl;
      }
      else {
        cout << "LIHUA" << endl;
      }
    }
  }
  return 0;
}
