#include<iostream>
#include<string>
#define S 200
using namespace std;
string s1,s2;
int x[S],y[S];
void converts(int z[S],string str){
	for(int i=0;i<str.size();i++) z[i]=str[str.size()-i-1]-'0';
	for(int i=str.size();i<=S;i++) z[i]=0;
}
void add(int *a,int *b,int len=S){
	for(int i=0;i<len;i++){
		if((a[i]+=b[i])>=10){//��λ 
			a[i+1]++; 
			a[i]-=10;
		}
	}
}
void print(int *z){
	int i;
	for(i=S-1;i>0;i--) if(z[i]>0) break;
	for(;i>=0;i--) cout<<z[i];
	cout<<endl;
}
int main(){
	cin>>s1>>s2;
	converts(x,s1);
	converts(y,s2);
	add(x,y);
	print(x);
	return 0;
}
