#include<iostream>
#include<string>
#define SIZE 200
using namespace std;
void converts(int *a,string s){
	int i,len=s.size();
	for(i=0;i<len;i++) a[i]=s[len-i-1]-'0';
	for(;i<SIZE;i++) a[i]=0;
}
//判断a<=b 
bool le(int *a, int *b, int len=SIZE) {
	int i;
	for(i=len-1; i>=0&&a[i]==b[i]; i--) ;
	return i<0 || a[i]<b[i];
}
//高精度-高精度，相当于a-=b，注意确保a>=b 
void sub(int *a, int *b, int len=SIZE) {
	for(int i=0;i<len;i++) 
		if((a[i]-=b[i])<0){//借位  
			a[i+1]--;
			a[i]+=10;
		}
} 
void print(int *a){
	int i;
	for(i=SIZE-1;i>0;i--) if(a[i]>0) break;
	for(;i>=0;i--) cout<<a[i]; cout<<endl;
}
int x[SIZE],y[SIZE];
int main() {
	string s1,s2;
	cin>>s1>>s2;
	converts(x,s1);
	converts(y,s2);
	if(le(y,x)) {
		sub(x,y);
		print(x);
	}
	else {
		sub(y,x);
		cout<<"-"; print(y);
	}
	return 0;
}

