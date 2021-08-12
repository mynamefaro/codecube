#include<bits/stdc++.h>
using namespace std;
using lli=long long;
using tll=tuple<int,int,int,int>;
int p[100002];
int find(int u){
	if(p[u]==0) return u;
	return p[u]=find(p[u]);
}

bool unionn(int u,int v){
	u=find(u);
	v=find(v);
	//cout << "DONE";
	if(u==v) return false;
	p[u]=v;
	return true;
	
	
}
int main(){
	lli ans=0;
	int n,m;
	scanf("%d%d",&n,&m);
	priority_queue<tll> PQ,special_edge;
	priority_queue<int,vector<int>,greater<int>> edge;
	for(int i=1;i<=m;++i){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		PQ.emplace(w,u,v,i);
	}
	int T;
	scanf("%d",&T);
	while(!PQ.empty()){
		int w=get<0>(PQ.top());
		int u=get<1>(PQ.top());
		int v=get<2>(PQ.top());
		int i=get<3>(PQ.top());PQ.pop();
		if(unionn(u,v)){
			edge.push(i);
			ans+=w;
		}else{
			special_edge.emplace(w,u,v,i);
		} 
	}
	if(!special_edge.empty()){
		int w=get<0>(special_edge.top());
		int u=get<1>(special_edge.top());
		int v=get<2>(special_edge.top());
		int i=get<3>(special_edge.top());PQ.pop();
		edge.push(i);
		ans+=w;
	}
	if(edge.size()<n){
		printf("-1");
		return 0;
	}
	printf("%lld\n",ans);
	if(T==2){
		while(!edge.empty()){
			printf("%d ",edge.top());
			edge.pop();
		}
	}
	
}
