#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pii = pair<int,int>;
lli N;
int cycle_head = 0;
vector <vector <int>> G;
vector <lli> table; //ans = table[u] * (N - table[u]); // if u v is not in cycle ring
vector <bool> cycle_ring , cycle_ring_visited;
lli find_table(int p , int u){
	if(u == cycle_head && p != -1) return 0;
	if(table[u] == 0){
		for(auto v:G[u]){
			if(v == p) continue;
			table[u] += find_table(u , v);
		}
		++table[u];
	}
	return table[u];
}
bool find_cycle_ring(int p , int u){
	if(u == cycle_head && p != -1) return true;
	if(cycle_ring_visited[u] == false){
		cycle_ring_visited[u] = true;
		for(auto v:G[u]){
			if(v == p) continue;
			cycle_ring[u] = find_cycle_ring(u , v) or cycle_ring[u];
		}
	}
	return cycle_ring[u];
}
int main(){
	int M;
	scanf("%lld %d",&N ,&M);
	int u ,v , p;//P parent
	G.assign(N + 1,vector <int>());
	vector <pii> E;
	while(M--){
		scanf("%d %d",&u ,&v);
		G[u].push_back(v);
		G[v].push_back(u);
		E.push_back({u , v});
	}
	//FIND CYCLE HEAD
	vector <bool> visited(N + 1,false);
	stack <pii> s;
	visited[1] = true;s.push({-1 , 1});
	while(!s.empty() && cycle_head == 0){
		p = s.top().first;
		u = s.top().second;
		s.pop();
		for(auto vw:G[u]){
			v = vw;
			if(!visited[v]){
				visited[v] = true;
				s.push({u , v});
			}else if(visited[v] && v != p){
				cycle_head = v;
			}
		}
	}
	table.assign(N + 1,0);
	cycle_ring.assign(N + 1,false);
	cycle_ring_visited.assign(N + 1,false);
	find_table(-1 , cycle_head);
	find_cycle_ring(-1 , cycle_head);
	
	for(auto uv : E){
		u = uv.first;v = uv.second;
		if(cycle_ring[u] && cycle_ring[v]){
			printf("0 ");
		}else if(cycle_ring[u]){
			printf("%lld ",table[v] * (N - table[v]));
		}else if(cycle_ring[v]){
			printf("%lld ",table[u] * (N - table[u]));
		}else{
			lli l = min(table[u] , table[v]);
			printf("%lld ",l * (N - l));
		}
	}
}
/*15 15 39 15 28 0 0 0 0 0 0 0 0 28 15 15*/

