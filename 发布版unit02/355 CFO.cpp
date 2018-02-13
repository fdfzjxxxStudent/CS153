#include <iostream>
#include <string>
#define SIZE 1000000 
using namespace std;
void converts(int *a,string s){
	int i,len=s.size();
	for(i=0;i<len;i++) a[i]=s[len-i-1]-'0';
	for(;i<SIZE;i++) a[i]=0;
}
void add(int *a,int *b,int len=SIZE){//a+=b
	for(int i=0;i<len;i++)
		if((a[i]+=b[i])>=10){//进位 
			a[i+1]++; 
			a[i]-=10;
		}
}
//高精度*int, 相当于a*=b, 要求b>0 
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
int p[SIZE],ans[SIZE],n,q;
string name,pstr; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>name>>q>>pstr;
		converts(p,pstr);
		mul(p,q);
		add(ans,p);
	}
	print(ans);
	return 0;
} 
