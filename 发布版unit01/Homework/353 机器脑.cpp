#include<iostream>
#include<string>
#define SIZE 200
using namespace std;
//高精度赋值 a=b; 
void copy(int *a, int *b) {
	for(int i=0;i<SIZE;i++)a[i]=b[i];
}
void converts(int *a,string s){
	int i,len=s.size();
	for(i=0;i<len;i++) a[i]=s[len-i-1]-'0';
	for(;i<SIZE;i++) a[i]=0;
}
void add(int *a,int *b,int len=SIZE){//a+=b
	//逐位相加
	for(int i=0;i<len;i++)
		if((a[i]+=b[i])>=10){//进位 
			a[i+1]++; 
			a[i]-=10;
		}
}
void print(int *a){
	int i;
	for(i=SIZE-1;i>0;i--) if(a[i]>0) break;
	for(;i>=0;i--) cout<<a[i]; cout<<endl;
}
int x[SIZE],y[SIZE],n;
int main() {
	cin>>n;
	n--;
	converts(x,"1");
	converts(y,"1");
		for(int i=1;i<=n/2;i++){
			add(x,y);
			add(y,x);
		}
	if(n%2==1){
		add(x,y);
		print(x);
	}
	else print(y);
	return 0;
}

