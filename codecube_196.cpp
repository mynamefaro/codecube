#include<bits/stdc++.h>
using namespace std;
using lli=long long;
using pii=pair<long long,int>;
vector<pair<int,int>> G[100002];
int n,m;
void djt(int s,vector<lli> &dis){
	vector<bool> visited(n+1,false);
	priority_queue<pii,vector<pii>,greater<pii>> PQ;
	dis[s]=0;
	PQ.push({dis[s],s});
	while(!PQ.empty()){
		int u=(int) PQ.top().second;PQ.pop();
		if(visited[u]) continue;
		visited[u]=true;
		for(auto vw:G[u]){
			int v=(int) vw.first;
			int w=vw.second;
			if(!visited[v] and dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				PQ.push({dis[v],v});
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	vector <lli> disa(n+1,2e16) ,disb(n+1,2e16);
	int a,b;
	scanf("%d%d",&a,&b);
	djt(a,disa);
	djt(b,disb);

	vector <bool> visited(n+1,false);//VISITED FOR C to D
	for(int u=1;u<=n;++u){
		if(disa[u]+disb[u]==disa[b]) visited[u]=true;
	}
	int c,d;
	scanf("%d%d",&c,&d);
	vector <lli> dis(n+1,2e16); //FOR C TO D
	priority_queue<pii,vector<pii>,greater<pii>> PQ;
	dis[c]=0;
	PQ.push({dis[c],c});
	while(!PQ.empty()){
		int u=(int) PQ.top().second;PQ.pop();
		if(visited[u]) continue;
		visited[u]=true;
		for(auto vw:G[u]){
			int v=(int) vw.first;
			int w=vw.second;
			if(!visited[v] and dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				PQ.push({dis[v],v});
			}
		}
	}
	if(dis[d]==2e16){
		printf("-1");
	}else{
		printf("%lld",dis[d]);
	}
}
