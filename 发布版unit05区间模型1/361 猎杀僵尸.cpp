#include<iostream>
#include<algorithm>
#define N 1005
using namespace std;
struct zombie{int s,t;};
bool cmp(const zombie& a,const zombie& b){
	return a.t<b.t||a.t==b.t&&a.s<b.s;
}
zombie d[N];
int n,i,j,x,ans;
int main(){
	cin>>n;	
	for(i=0;i<n;i++)
		cin>>d[i].s>>d[i].t;
	sort(d,d+n,cmp);
	x=-1; ans=0;
	for(i=0;i<n;i++)
		if(d[i].s>=x) {
			ans++;
			x=d[i].t;
		}
	cout<<n-ans<<endl;	
	return 0;
}
