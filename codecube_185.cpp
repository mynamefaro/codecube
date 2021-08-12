#include<bits/stdc++.h>
using namespace std;
using lli=long long;
using pii=pair<lli,lli>;
int main(){
	int N,M,T;
	scanf("%d%d%d",&N,&M,&T);
	int X,Y;
	scanf("%d%d",&X,&Y);
	vector <pii> G[N+1];
	lli dis[N+1][T+1];
	bool visited[N+1][T+1];
	for(int i=0;i<=N;++i){
		for(int j=0;j<=T;++j){
			visited[i][j]=false;
			dis[i][j]=20000000000000;
		}
	}
	int u,v,w,c;
	while(M--){
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back({v,w});
	}
	priority_queue<pair<lli,pii>,vector<pair<lli,pii>>,greater<pair<lli,pii>>>PQ;
	dis[X][1]=0;
	PQ.push({dis[X][1],{X,1}});
	while(!PQ.empty()){
		u=PQ.top().second.first;
		c=PQ.top().second.second;PQ.pop();
		if(visited[u][c])continue;
		visited[u][c]=true;
		if(u==Y and c==0) break;
		int newc=(c+1)%T;
		//cout << newc << endl;
		for(auto vw:G[u]){
			v=vw.first;
			w=vw.second;
			//cout << v << " ";
			if(!visited[v][newc] and dis[v][newc]>dis[u][c]+w){
				dis[v][newc]=dis[u][c]+w;
				PQ.push({dis[v][newc],{v,newc}});
			}
		}
	}
	if(dis[Y][0]>=20000000000000) dis[Y][0]=-1;
	printf("%lld",dis[Y][0]);
}
