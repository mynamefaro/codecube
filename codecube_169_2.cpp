#include<bits/stdc++.h>
using namespace std;
using lli=long long;
int P=1e9+7;
int fac[100002];
int main(){
	for(int i=2;i<=100000;++i){
		for(int j=i;j<=100000;j+=i){
			++fac[j];
		}
	}
	int n,m;
	scanf("%d%d",&n,&m);
	int ans=0;int a=0;
	int N[n],M[m];
	for(int i=0;i<n;++i){
		scanf("%d",&N[i]);
		N[i]=fac[N[i]];
	}
	for(int i=0;i<m;++i){
		scanf("%d",&M[i]);
		M[i]=fac[M[i]];
	}
	for(int i=0;i<n;++i){
		if(a==m) break;
		if(M[a]==N[i]){
			++a;
			ans=max(ans,a);
		}else{
			a=0;
			if(i>=n-m) break;
		}
	}
	printf("%d",ans);
}

