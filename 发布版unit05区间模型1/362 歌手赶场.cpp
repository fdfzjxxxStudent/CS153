#include<iostream>
#include<algorithm>
#include<string>
#define N 105
using namespace std;
struct concert{int s,t;};
bool cmp(const concert& a,const concert& b){
	return a.t<b.t||a.t==b.t&&a.s<b.s;
}
concert d[N];
int n,i,x,ans,sm,ss,tm,ts;
char c;
int main(){
	cin>>n;	
	for(i=0;i<n;i++){
		cin>>sm>>c>>ss>>c>>tm>>c>>ts;
		d[i].s=sm*100+ss;
		if(ts+45<=60) d[i].t=tm*100+ts+45;
		if(ts+45>60) d[i].t=tm*100+100+ts-15;
	}
	sort(d,d+n,cmp);
	x=-1; ans=0;
	for(i=0;i<n;i++){
		if(d[i].s>=x) {
			ans++;
			x=d[i].t;
		}
		//cout<<d[i].s<<"|"<<d[i].t<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
