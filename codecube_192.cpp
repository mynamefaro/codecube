#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int a[n+1],b[m+1];
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int j=1;j<=m;++j) scanf("%d",&b[j]);
	int ans=-2e9;
	int dp[n+1][2];
	for(int j=0;j<=m;++j){
		int mn=2e9;
		for(int i=0;i<=n;++i){
			dp[i][(j+0)%2]=2e9;
			if(i==0){
				dp[0][j%2]=j;
			}else if(j==0){
				dp[i][0]=1;
			}else{
				if(a[i]==b[j]){
					dp[i][(j-0)%2]=dp[i-1][(j-1)%2];
					mn=min(mn,dp[i][(j-0)%2]);
				}else{
					dp[i][(j-0)%2]=1+min({dp[i][(j-1)%2] ,dp[i-1][(j-1)%2] ,mn});
				}
			}
			if(dp[i][j%2]<=k) ans=max(ans,j);
		}
	}
	printf("%d",ans);
}
