#include<iostream>
#include<algorithm>
#define N 105
using namespace std;
struct food{int s,t;};
bool cmp(const food& a,const food& b){
	return a.t<b.t||a.t==b.t&&a.s<b.s;
}
food d[N];
int n,i,x,ans;
int main(){
	cin>>n;	
	for(i=0;i<n;i++) cin>>d[i].s;
	for(i=0;i<n;i++) cin>>d[i].t;
	sort(d,d+n,cmp);
	x=-1; ans=0;
	for(i=0;i<n;i++)
		if(d[i].s>=x) {
			ans++;
			x=d[i].t;
		}
	cout<<ans<<endl;	
	return 0;
}
