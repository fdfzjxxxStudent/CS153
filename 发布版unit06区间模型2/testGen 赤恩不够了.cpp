#include<stdio.h> 
#include<iostream>
#include<algorithm>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<windows.h>
#define N 1005
using namespace std;
struct ke{int s,t;};
bool cmp(const ke& a,const ke& b){
	return a.s<b.s||a.s==b.s&&a.t<b.t;
}
ke d[N];
ofstream fout;
int main(){
	fout.open("³à¶÷²»¹»ÁË.txt"); 
	for(int k=1;k<=20;k++){
		srand(time(0));
		fout<<"====="<<endl;
		printf("#");
		int n,a,p,tmp,i,j,x[N],cnt=0;
		n=1+rand()%1000;
		Sleep(10);
		a=0+rand()%1000000000000;
		Sleep(10);
		p=0+rand()%1000000000000;
		Sleep(10);
		if(a<p){
			tmp=a;
			a=p*n*100;
			p=tmp;
		}
		cout<<n<<" "<<a<<" "<<p<<endl;
		fout<<n<<" "<<a<<" "<<p<<endl;
		for(i=0;i<n;i++){
			int sh,sm,th,tm,tmph,tmpm,num;
			char c;
			sh=0+rand()%23;
			Sleep(10);
			sm=0+rand()%59;
			Sleep(10);
			t:
			th=0+rand()%23;
			tm=0+rand()%59;
			Sleep(10);
			if(th<sh||th==sh&&th<=sm){
				tmph=th;tmpm=tm;
				th=sh;tm=sm;
				sh=tmph;sm=tmpm;
			}
			num=0+rand()%50;
			fout<<sh<<":"<<sm<<"-"<<th<<":"<<tm<<"|"<<num<<endl;
			//cout<<sh<<":"<<sm<<"-"<<th<<":"<<tm<<"|"<<num<<endl;
			if(num<10) continue;
			d[i].s=sh*100+sm;
			tm+10<60?d[i].t=th*100+tm+10:d[i].t=th*100+tm+50;
		}
		fout<<"====="<<endl;
		sort(d,d+n,cmp);
		for(i=0;i<n;i++){
			for(j=0;j<cnt;j++)
				if(d[i].s>x[j]) break;
			if(j<cnt) x[j]=d[i].t;
			else x[cnt++]=d[i].t;
		}
		//cout<<cnt<<" "<<a-cnt*p<<endl;
		fout<<cnt<<" "<<a-cnt*p<<endl;	
		if(a-cnt*p<=0){
			fout<<"fdfzjxxx needs "<<(0-(a-cnt*p))/p+1<<" chien to help him"<<endl;
			//cout<<"fdfzjxxx needs "<<(0-(a-cnt*p))/p+1<<" chien to help him"<<endl;
		}
		if(a-cnt*p>=888){
			fout<<"fdfzjxxx is very rich!"<<endl; 
			//cout<<"fdfzjxxx is very rich!"<<endl; 
		}
	}
	fout.close();
	return 0;
}
