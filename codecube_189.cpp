#include <bits/stdc++.h>
using namespace std;
using pii = pair<int , int>;
int N;
void dijkstra(int s, vector <vector <pii>> &G , vector <int> &dis){
	priority_queue <pii , vector <pii> , greater<pii>> PQ;
	vector <bool> visited (N + 1,false);
	dis[s] = 0;
	PQ.push({dis[s] , s});
	while(!PQ.empty()){
		int u = PQ.top().second;PQ.pop();
		if(visited[u]) continue;
		visited[u] = true;
		for(auto vw:G[u]){
			int v = vw.first;
			int w = vw.second;
			if(!visited[v] && dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				PQ.push({dis[v] , v});
			}
		}
	}
}

int main(){
	int M;
	scanf("%d %d",&N ,&M);
	int s , t;
	scanf("%d %d",&s ,&t);
	vector <vector <pii>> G (N + 1,vector <pii>());
	vector <pii> E;
	int u , v , w;
	int sum_w = 0;
	int ans = 0;
	for(int i = 1;i <= M;++i){
		scanf("%d %d %d",&u ,&v,&w);
		G[u].push_back({v , w});
		G[v].push_back({u , w});
		E.push_back({u , v});
		sum_w += w;
	}
	vector <int> dis_s (N + 1,2e9) , dis_t (N + 1,2e9);
	dijkstra(s , G , dis_s);
	dijkstra(t , G , dis_t);
	int minlost = 2e9;
	for(auto uv : E){
		u = uv.first;v = uv.second;
		minlost = min(minlost , dis_s[u] + dis_t[v]);
		minlost = min(minlost , dis_s[v] + dis_t[u]);
	}
	ans = sum_w - minlost;
	printf("%d",ans);
}
