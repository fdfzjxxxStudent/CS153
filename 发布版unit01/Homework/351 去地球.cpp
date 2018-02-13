#include <iostream>
#include <string>
#define SIZE 101
using namespace std;
int x[SIZE],y[SIZE],z[SIZE],i,j;
string s1,s2,s3;
void converts(int *a,string s){
	int i,len=s.size();
	for(i=0;i<len;i++) a[i]=s[len-i-1]-'0';
	for(;i<SIZE;i++) a[i]=0;
}
void print(int *a){
	int i;
	for(i=SIZE-1;i>0;i--) if(a[i]>0) break;
	for(;i>=0;i--) cout<<a[i]; cout<<endl;
}
bool m(int *a,int *b,int len=SIZE){
	int i;
	for(i=len-1;i>=0&&a[i]==b[i];i--);
	return i<0 || a[i]<b[i];
}
int main(){
	cin>>s1>>s2>>s3;
	converts(x,s1);
	converts(y,s2);
	converts(z,s3);
	if(!m(x,y)){
		if(!m(x,z)) print(x);
		else print(z);
	}
	else{
		if(!m(y,z)) print(y);
		else print(z);
	}
	return 0;
}


