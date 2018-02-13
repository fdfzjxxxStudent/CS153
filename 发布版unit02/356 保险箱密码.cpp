#include <iostream>
#include <string>
#define SIZE 1000
using namespace std;
void converts(int *a,string s){
	int i,len=s.size();
	for(i=0;i<len;i++) a[i]=s[len-i-1]-'0';
	for(;i<SIZE;i++) a[i]=0;
}
void add(int *a,int *b,int len=SIZE){//a+=b
	for(int i=0;i<len;i++)
		if((a[i]+=b[i])>=10){//½øÎ» 
			a[i+1]++; 
			a[i]-=10;
		}
}
void multiply(int *c,int *a,int *b) {
	converts(c,"0");
	for(int i=0;i<SIZE;i++) 
		for(int j=0; j<b[i]; j++)
			add(c+i, a, SIZE-i);
} 
void print(int *a){
	int i;
	for(i=SIZE-1;i>0;i--) if(a[i]>0) break;
	for(;i>=0;i--) cout<<a[i]; cout<<endl;
}
int x[SIZE],y[SIZE],z[SIZE];
unsigned long long a=0,b=0,i,len;
string s1,s2;
int main(){
	cin>>s1>>s2;
	converts(x,s1);
	converts(y,s2);
	multiply(z,x,y);
	for(len=SIZE-1;len>0;len--) if(z[len]>0) break;
	for(i=0;i<SIZE-len+1;i++)
		i%2==1?a+=z[i]:b+=z[i];
	if(i%2==1) cout<<b<<a<<endl;
	else cout<<a<<b<<endl;
	return 0;
}
