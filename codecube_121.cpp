#include<bits/stdc++.h>
using namespace std;
using lli=long long;
using tll=tuple<int,int,int>;
int sett[100010],rankk[100010];
int find(int u){
	if(sett[u]==-1) return u;
	return sett[u]=find(sett[u]);
}
void unionn(int u,int v){
	u=find(u);
	v=find(v);
	if(rankk[u]>rankk[v]) swap(u,v);
	sett[u]=v;
	rankk[v]+=rankk[u];
}
int main(){
	int n;
	lli ans=0;
	scanf("%d",&n);
	int p[n+1];
	for(int i=1;i<=n;++i){
		scanf("%d",&p[i]);
		sett[i]=-1;
		rankk[i]=1;
	} 
	priority_queue<tll,vector<tll>,greater<tll>> PQ;
	int m;
	scanf("%d",&m);
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		PQ.emplace(p[u]+p[v],u,v);
	}
	while(!PQ.empty()){
		int w=get<0>(PQ.top());
		int u=get<1>(PQ.top());
		int v=get<2>(PQ.top());PQ.pop();
		if(find(u)!=find(v)){
			unionn(u,v);
			ans+=w;
		}
	}
	printf("%lld",ans);
}
