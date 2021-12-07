#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using pii=pair<int,int>;

int main(){
	int Q;
	scanf("%d",&Q);
	while(Q--){
		int N,H;
		scanf("%d%d",&N,&H);
		pii s[N];
		int l=0,r=-2e9;
		for(int i=0;i<N;++i){
			scanf("%d%d",&s[i].first,&s[i].second);
			r=max(r,s[i].second);
		}
		sort(s,s+N);
		int ans=2e9;
		while(l<=r){
			int K=(l+r)/2;
			deque <pii> mx,mn;
			bool result=false;
			for(int i=0;i<N;++i){
				while(!mx.empty() and mx.back().Y<s[i].Y){
					mx.pop_back();
				}
				while(!mn.empty() and mn.back().Y>s[i].Y){
					mn.pop_back();
				}
				mx.push_back(s[i]);
				mn.push_back(s[i]);
				while(!mx.empty() and s[i].X-mx.front().X>K){
					mx.pop_front();
				}
				while(!mn.empty() and s[i].X-mn.front().X>K){
					mn.pop_front();
				}
				if(mx.empty() or mn.empty()) continue;
				if(abs(mx.front().Y-mn.front().Y)>=H){
					result=true;
					break;
				} 
			}
			if(result){
				ans=min(ans,K);
				r=K-1;
			}else{
				l=K+1;
			}
		}
		if(ans==2e9){
			printf("-1\n");
		}else{
			printf("%d\n",ans);
		}
	}
}
