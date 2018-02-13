#include <iostream>  
#include <algorithm>  
using namespace std;  
//ifstream cin("hanoi.in",ios :: in);  
//ofstream cout("hanoi.out",ios :: out);  
int main() {  
  ios :: sync_with_stdio(false); //流的加速  
  int n,len = 1,num[101];  
  fill(num+1,num+100+1,0);  
  num[1] = 1;  
  len = 2;  
  cin >> n;  
  n++;  
  while (n--) {  //*2操作  
    for (int i = 1;i <= len;i++) num[i] *= 2;  
    for (int i = 1;i <= len;i++)  
      if (num[i] >= 10) {  //进位  
        num[i+1] += num[i]/10;  
        num[i] %= 10;  
      }  
    if(num[len] != 0) len++;  
  }  
  num[1] -= 2;  //-2操作  
  for (int i = 1;i < len;i++) {  
    if (num[i] < 0) {  //退位  
      num[i+1] -= 10;  
      num[i] += 10;  
    }  
  }  
  if (num[len] < 0) len--;  
  for (int i = len-1;i >= 1;i--) cout << num[i];  //输出  
  return 0;  
}  
/*
严格推导：
f[n+1]-f[n]=2*f[n]+2-2*f[n-1]-2=2*(f[n]-f[n-1])
d[n]≡f[n]-f[n-1]是等比数列（数列d成为数列f的差分）
d[n]=2n
f[n]=d[1]+d[2]+d[3]+…+d[n]=2+22+23+24+…+2n

