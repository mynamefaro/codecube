#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using tll=tuple<long long,int,int>;
using lli=long long;
int main(){
	int n,m,k,t;
	scanf("%d%d%d%d",&n,&m,&k,&t);
	vector<pii> G[n+1];
	lli dis[n+1][2];
	bool visited[n+1][2];
	for(int i=1;i<=n;++i){
		dis[i][0]=dis[i][1]=2e18;
		visited[i][0]=visited[i][1]=false;
	}
	while(m--){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		G[u].emplace_back(v,w);
		G[v].emplace_back(u,w);
	}
	priority_queue <tll,vector<tll>,greater<tll>>PQ;
	dis[1][1]=0;
	PQ.emplace(dis[1][1],1,1);
	while(!PQ.empty()){
		int u=get<1>(PQ.top());
		int c=get<2>(PQ.top());PQ.pop();
		if(visited[u][c]) continue;
		visited[u][c]=true;
		for(auto vw:G[u]){
			int v=vw.first;
			int w=vw.second;
			if(!visited[v][c] and dis[v][c]>dis[u][c]+w){
				dis[v][c]=dis[u][c]+w;
				PQ.emplace(dis[v][c],v,c);
			}
			if(c==1 and !visited[v][0] and dis[v][0]>dis[u][c]+k){
				dis[v][0]=dis[u][c]+k;
				PQ.emplace(dis[v][0],v,0);
			}
		}
	}
	if(min(dis[n][0],dis[n][1])>t){
		printf("No Honey TT\n");
	}else{
		printf("Happy Winnie the Pooh :3\n%d",min(dis[n][0],dis[n][1]));
	}
}
