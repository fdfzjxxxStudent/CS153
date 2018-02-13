#include<bits/stdc++.h>
#define N 105
using namespace std;
struct guide{double s,t;};
bool cmp(const guide& a,const guide& b){
	return a.s<b.s||a.s==b.s&&a.t<b.t;
}
guide d[N];
int main(){
	int W,n,i,j,cnt=0,S=0,T,x,r;
	double tmp;
	cin>>n>>T>>W;
	W/=2;
	for(i=j=0;i<n;i++) {
		cin>>x>>r;
		if(r<W/2) continue;
		d[j].s=x-sqrt(r*r-W*W/4);
		d[j++].t=x+sqrt(r*r-W*W/4);
	}
	n=j;
	sort(d,d+n,cmp);
	for(i=0;i<n&&S<T;i++){
		for(j=i;j<n&&d[j].s<=S;j++)
			if(d[j].t>d[i].t) i=j;
		if(d[i].s>S) break;
		S=d[i].t; cnt++; 
	}
	if(S<T) cout<<-1<<endl;
	else cout<<cnt<<endl;	
	return 0;
}
