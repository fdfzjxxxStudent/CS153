#include<stdio.h> 
#include<iostream>
#include<algorithm>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<windows.h>
#define N 1005
#define MAX 1000
using namespace std;
struct lesson{int s,t;double p;};
bool cmp(const lesson& a,const lesson& b){
	return a.t<b.t||a.t==b.t&&a.s<b.s;
}
lesson d[N];
ofstream fout;
int n,i,x,ans,a,b;
int main(){
	fout.open("½²¿Î.txt");
	for(int k=1;k<21;k++){
		srand(time(0)*time(0));
		n=rand()%MAX;
		fout<<n<<endl;
		for(i=0;i<n;i++){
			ra:
			a=rand()%1000; b=a+rand()%1000;
			if(a%100>=60||b%100>=60) goto ra;
			d[i].s=a + rand() % (b-a+1);
			rb:
			a=d[i].s+rand()%1000; b=a+rand()%1000;
			if(a%100>=60||b%100>=60) goto rb;
			d[i].t=a + rand() % (b-a+1);
			if(d[i].t<=d[i].s) goto ra; 
			d[i].t%100+10<60?d[i].t+=10:d[i].t+=50;
			fout<<d[i].s<<" "<<d[i].t<<endl;
		}
		fout<<"====="<<endl;
		sort(d,d+n,cmp);
		x=-1; ans=0;
		for(i=0;i<n;i++)
			if(d[i].s>=x) {
				ans++;
				x=d[i].t;
			}
		fout<<ans<<" "<<ans*80<<endl;	
		if(n%2==0&&n/ans>n/2) fout<<"I am so sad!"<<endl;
		if(n%2==1&&n/ans>n/2) fout<<"I am so sad!"<<endl;
		fout<<"====="<<endl;
		cout<<"Answer for question "<<k<<":"<<endl;
		cout<<"(n="<<n<<")"<<endl;
		cout<<ans<<" "<<ans*80<<endl;
		if(n%2==0&&n/ans>n/2) fout<<"I am so sad!"<<endl;
		if(n%2==1&&n/ans>n/2) fout<<"I am so sad!"<<endl;
		Sleep(k*1000%100);
	}
	return 0;
}
