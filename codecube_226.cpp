#include <bits/stdc++.h>
using namespace std;
vector<int> com , G , pos;
int c_id;
void bfs(int u){
	queue <int> Q;
	Q.push(u);
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		int v = G[u];
		if(com[v] == 0){
			com[v] = c_id;
			pos[v]=pos[u] + 1;
			Q.push(v);
		}
	}
}
int main(){
	int N , Q;
	int s,e,a,b;
	scanf("%d %d",&N ,&Q);
	com.assign(N + 1,0);
	G.assign(N + 1,0);
	pos.assign(N + 1,0);
	for(int i=1;i<=N;++i) scanf("%d",&G[i]);
	for(int i=1;i<=N;++i){
		if(com[i] == 0){
			++c_id;
			com[i] = c_id;
			pos[i] = 1;
			bfs(i);
		}
	}
	//for(int i=1;i<=N;++i) cout << pos[i] << " ";
	//printf("SURVIVE\n");
	//printf("DEAD\n");
	while(Q--){
		scanf("%d %d %d %d",&s ,&e,&a,&b);
		if(com[e] == com[s]){
			if(com[a] != com[e] or com[b] != com[e]){
				printf("DEAD\n");
				continue;
			}else if(com[a] == com[b] and com[e] == com[b]){
				int i , j;
				if(pos[G[a]] <= pos[b]){
					i = pos[G[a]];j = pos[b];
				}else{
					i = pos[G[b]];j = pos[a];
				}
				int consider = (int)(i <= pos[e] and pos[e] <= j) + (int)(i <= pos[s] and pos[s] <= j);
				if(consider % 2 == 0){
					printf("DEAD\n");
					continue;
				}
			}
		}else if(((com[a]==com[e] and com[b]==com[s]) or (com[a]==com[s] and com[b]==com[e]))){
			printf("DEAD\n");
			continue;
		}
		printf("SURVIVE\n");
	}
	
}
