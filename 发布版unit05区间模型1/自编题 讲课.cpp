//ÕýÈ·´ð°¸ 
#include<iostream>
#include<algorithm>
#define N 1005
using namespace std;
struct lesson{int s,t;double p;};
bool cmp(const lesson& a,const lesson& b){
	return a.t<b.t||a.t==b.t&&a.s<b.s;
}
lesson d[N];
int n,i,x,ans,allp=0;
int main(){
	cin>>n;	
	for(i=0;i<n;i++){
		cin>>d[i].s>>d[i].t;
		d[i].t%100+10<60?d[i].t+=10:d[i].t+=50;
	}
	sort(d,d+n,cmp);
	x=-1; ans=0;
	for(i=0;i<n;i++)
		if(d[i].s>=x) {
			ans++;
			allp+=80;
			x=d[i].t;
		}
	cout<<ans<<" "<<allp<<endl;	
	if(n%2==0&&n/ans>n/2) cout<<"I am so sad!"<<endl;
	if(n%2==1&&n/ans>n/2) cout<<"I am so sad!"<<endl;
	return 0;
}
