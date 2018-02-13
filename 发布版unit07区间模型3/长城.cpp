#include<iostream>
#include<algorithm>
#define N 10005
using namespace std;
struct guide{double s,t;};
bool cmp(const guide& a,const guide& b){
	return a.s<b.s||a.s==b.s&&a.t<b.t;
}
guide d[N];
int main(){
	int n,i,j,cnt=0;
	int S=0,T;
	cin>>T>>n;	
	for(i=0;i<n;i++){
		cin>>d[i].s>>d[i].t;
		d[i].s=d[i].s-d[i].t;
		d[i].t=d[i].s+d[i].t+d[i].t;
		//cout<<d[i].s<<"|"<<d[i].t<<endl;
	}
	sort(d,d+n,cmp);
	for(i=0;i<n&&S<T;i++){
		for(j=i;j<n&&d[j].s<=S;j++)
			if(d[j].t>d[i].t) i=j;
		if(d[i].s>S) break;
		S=d[i].t; cnt++; 
	}
	if(S<T) cout<<"Impossible"<<endl;
	else cout<<cnt<<endl;	
	return 0;
}
