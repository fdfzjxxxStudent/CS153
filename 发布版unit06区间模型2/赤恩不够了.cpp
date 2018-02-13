#include<iostream>
#include<algorithm>
#define N 1005
using namespace std;
struct ke{int s,t;};
bool cmp(const ke& a,const ke& b){
	return a.s<b.s||a.s==b.s&&a.t<b.t;
}
ke d[N];
int main(){
	int n,a,p,i,j,x[N],cnt=0;
	cin>>n>>a>>p;	
	for(i=0;i<n;i++){
		int sh,sm,th,tm,num;
		char c;
		cin>>sh>>c>>sm>>c>>th>>c>>tm>>c>>num;
		if(num<10) continue;
		d[i].s=sh*100+sm;
		tm+10<60?d[i].t=th*100+tm+10:d[i].t=th*100+tm+50;
	}
	sort(d,d+n,cmp);
	for(i=0;i<n;i++){
		for(j=0;j<cnt;j++)
			if(d[i].s>x[j]) break;
		if(j<cnt) x[j]=d[i].t;
		else x[cnt++]=d[i].t;
	}
	cout<<cnt<<" "<<a-cnt*p<<endl;	
	if(a-cnt*p<=0) cout<<"fdfzjxxx needs "<<(0-(a-cnt*p))/p+1<<" chien to help him"<<endl;
	if(a-cnt*p>=888) cout<<"fdfzjxxx is very rich!"<<endl; 
	return 0;
}
