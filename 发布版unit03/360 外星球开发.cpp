#include<iostream>
#include<string>
#define SIZE 1200
using namespace std;
void converts(int *a,string s){
	int i,len=s.size();
	for(i=0;i<len;i++) a[i]=s[len-i-1]-'0';
	for(;i<SIZE;i++) a[i]=0;
}
//�߾��ȸ��� a=b; 
void copy(int *a, int *b) {
	for(int i=0;i<SIZE;i++)a[i]=b[i];
}
//�ж�a<=b 
bool le(int *a, int *b, int len=SIZE) {
	int i;
	for(i=len-1; i>=0&&a[i]==b[i]; i--);
	return i<0 || a[i]<b[i];
}
//�߾���-�߾��ȣ��൱��a-=b��ע��ȷ��a>=b 
void sub(int *a, int *b, int len=SIZE) {
	for(int i=0;i<len;i++) 
		if((a[i]-=b[i])<0){//��λ  
			a[i+1]--;
			a[i]+=10;
		}
} 
//�߾���/��%�߾��ȣ�q=a/b, r=a%b��Ҫ��b>0 
void div(int *q,int *r,int *a,int *b){
	converts(q,"0");	//��ʼ���� 
	copy(r,a);			//��ʼ������
	int j;
	for(j=SIZE-1; b[j]==0; j--) ; //��b��߷���λ��j 
	for(int i=SIZE-1-j; i>=0; i--) 
		for( ;le(b,r+i,SIZE-i); q[i]++)   
			sub(r+i,b,SIZE-i);
} 
void print(int *a){
	int i;
	for(i=SIZE-1;i>0;i--) if(a[i]>0) break;
	for(;i>=0;i--) cout<<a[i]; cout<<endl;
}
int x[SIZE],y[SIZE],s[SIZE],t[SIZE],tmp[SIZE];
int main() {
	string s1,s2;
	cin>>s1>>s2;
	converts(x,s1);
	converts(y,s2);
	converts(tmp,"0"); 
	if(!le(x,y)){
		copy(tmp,y);
		copy(y,x);
		copy(x,tmp);
	}
	converts(tmp,"0"); 
	while(1){
		div(s,t,y,x);
		copy(y,t);
		if(le(t,tmp)) break;
		div(s,y,x,t);
		copy(x,t);
		if(le(t,tmp)) break;
	}	
	print(x);
	return 0;
}
//�����Լ����շת����� 
