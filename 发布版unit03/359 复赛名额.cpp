#include <iostream>
#include <string>
#define SIZE 50000
using namespace std;
void converts(int *a,string s){
	int i,len=s.size();
	for(i=0;i<len;i++) a[i]=s[len-i-1]-'0';
	for(;i<SIZE;i++) a[i]=0;
}
//高精度/int, 相当于a/=n，要求n>0 
void div(int *a, int n) { 
	//c代表每一位的被除数 	
	for(int i=SIZE-1,c=0; i>=0; i--) {//逐位相除 
		c = c%n*10 + a[i];  //高位的余数留给低位 
		a[i] = c/n;  //商 
	}
}
void add(int *a,int *b,int len=SIZE){//a+=b
	for(int i=0;i<len;i++)
		if((a[i]+=b[i])>=10){//进位 
			a[i+1]++; 
			a[i]-=10;
		}
}
void mul(int *a, int b) {
	for(int i=0,c=0; i<SIZE; i++){ 
		c = c/10 + a[i]*b;
		a[i] = c%10;
	}
} 
void print(int *a){
	int i;
	for(i=SIZE-1;i>0;i--) if(a[i]>0) break;
	for(;i>=0;i--) cout<<a[i]; cout<<endl;
}
int x,y,ans[SIZE];
int main(){
	cin>>x>>y;
	converts(ans,"1");
	for(int i=1,j=x;i<=y;i++,j--)
		mul(ans,j);
	for(int j=y;j>=1;j--)
		div(ans,j);
	print(ans);
	return 0;
}
