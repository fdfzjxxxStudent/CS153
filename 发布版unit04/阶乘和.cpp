#include<iostream>
#include<string>
#define SIZE 5000
using namespace std;
void converts(int *a,string s){
	int i,len=s.size();
	for(i=0;i<len;i++) a[i]=s[len-i-1]-'0';
	for(;i<SIZE;i++) a[i]=0;
}
void add(int *a,int *b,int len=SIZE){//a+=b
	//��λ���
	for(int i=0;i<len;i++)
		if((a[i]+=b[i])>=10){//��λ 
			a[i+1]++; 
			a[i]-=10;
		}
}
//�߾���*int, �൱��a*=b, Ҫ��b>0 
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
int s[SIZE],tmp[SIZE],m;
int main() {
	converts(s,"0");
	converts(tmp,"1");
	cin>>m; 
	for(int i=1;i<=m;i++){
		mul(tmp,i);
		add(s,tmp);
	}
	print(s);
	return 0;
}

