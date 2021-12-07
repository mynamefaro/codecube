#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

const int S = 200005; //MAX_SIZE

int arr[S],cnt[S],ml[S];
int cnt_over_0;

int main(){
	int N, K, Q;
	scanf("%d%d%d",&N,&K,&Q);
	
	for(int i=1;i<=N;++i)
	{
		scanf("%d",&arr[i]);
	}
	int I=1,J=1,preI=0;
	while(I<=N){
		while(arr[I]>K){
			++I;
		}
		
		J=max(J,I);
		while(!(cnt_over_0==K)){
			if(J>N){
				J=2e9;
				break;
			}
			while(arr[J]>K and J<=N){
				++J;
			}
			if(cnt[arr[J]]==0)
			{
				cnt_over_0++;
			}
			++cnt[arr[J]];
			++J;
		}
		for(int i=preI+1;i<=I;++i){
			ml[i]=J-1;
		}
		preI=I;
		--cnt[arr[I]];
		if(cnt[arr[I]]==0)
		{
			cnt_over_0--;
		}
		++I;
	}
	for(int i=preI+1;i<=N;++i){
		ml[i]=J-1;
	}
	//QUESTION
	while(Q--){
		int l,r;
		scanf("%d%d",&l,&r);
		if(ml[l]<=r){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
}
