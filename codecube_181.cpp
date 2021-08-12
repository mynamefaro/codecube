#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int N,M,P;
vector <pii> G[40010];
int a[50010],b[50010];
bool bfs(int A,int B,int block){
	vector <bool> visited(N+1,false);
	queue <int> Q;
	visited[A]=true;
	Q.push(A);
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		if(u==B) break;
		for(auto vw:G[u]){
			int v=vw.first;
			int w=vw.second;
			if(w>=block) continue;
			if(!visited[v]){
				visited[v]=true;
				Q.push(v);
			}
		}
	}
	return visited[B];
}
bool check(int block){
	bool ans=false;
	for(int i=1;i<=P;++i){
		ans=ans or bfs(a[i],b[i],block);
		if(ans) break;
	}
	return ans;
}
int main(){
	scanf("%d%d%d",&N,&M,&P);
	int u,v,w;
	int max_w=0;
	while(M--){
		scanf("%d%d%d",&u,&v,&w);
		max_w=max(max_w,w);
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i=1;i<=P;++i){
		scanf("%d%d",&a[i],&b[i]);
	}
	if(!check(2e9)){
		printf("-1");
		return 0;
	}
	int ans=0;
	int l=0,r=max_w;
	while(l<=r){
		int mid=(l+r)/2;
		if(!check(mid)){
			ans=max(ans,mid);
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%d",ans);
}
