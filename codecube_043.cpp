#include<bits/stdc++.h>
using namespace std;
using lli=long long;
using pii=pair<int,int>;
lli table[302][2002];
bool visited[302][2002];
using tll=tuple<int,int,int>;
vector <tll> G[302];
int S,T;
lli solve(int u,int dis){
	if(u==S and dis==0) return 0;
	if(!visited[u][dis]){
		visited[u][dis]=true;
		table[u][dis]=-2e18;
		for(auto vwc:G[u]){
			int v=get<0>(vwc);
			int w=get<1>(vwc);
			int c=get<2>(vwc);
			if(dis < w) continue;
			table[u][dis] = max(table[u][dis] , solve(v,dis-w) + c);
		}
	}
	return table[u][dis];
}
int main(){
    int N,M,K;
    scanf("%d%d%d",&N,&M,&K);
    scanf("%d%d",&S,&T);
    while(M--){
    	int u,v,w,c;
    	scanf("%d%d%d%d",&u,&v,&c,&w);
    	G[u].emplace_back(v,w,c);
    	G[v].emplace_back(u,w,c);
	}
	lli ans=0;
	for(int dis=K;dis>=0;--dis) ans=max(ans,solve(T,dis));
	if(ans==0){
		printf("Impossible");
		return 0;
	}
	printf("%lld",ans);
}
