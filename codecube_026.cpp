#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int main(){
	priority_queue <pii,vector<pii>,greater<pii>>PQ;
	int n,a,b,ans=0;
	int cnt=0;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&a,&b);
		PQ.push({a,1});
		PQ.push({b,0});
	}
	while(!PQ.empty()){
		pii p=PQ.top();PQ.pop();
		if(p.second==1){
			++cnt;
			ans=max(cnt,ans);
		}else{
			--cnt;
		}
	}
	printf("%d\n",ans);
}
