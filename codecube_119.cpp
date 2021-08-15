#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int arr[n][m],DP[n][m];
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int j=0;j<m;++j) DP[0][j]=arr[0][j];
    int ans=-2e9;
    for(int i=1;i<n;++i){
        deque <int> dq;
        for(int j=0;j<=k;++j){
            while(!dq.empty() and DP[i-1][j]>DP[i-1][dq.back()]){
                dq.pop_back();
            }
            dq.push_back(j);
        }
        for(int j=0;j<m;++j){
            while(!dq.empty() and dq.front()<j-k){
                dq.pop_front();
            }
            DP[i][j]=arr[i][j]+DP[i-1][dq.front()];
            //printf("%d %d : %d\n",i,j,DP[i][j]);
            ans=max(ans,DP[i][j]);
            if(j+k+1>=m) continue;
            while(!dq.empty() and DP[i-1][j+k+1]>DP[i-1][dq.back()]){
                dq.pop_back();
            }
            dq.push_back(j+k+1);
        }
    }
    printf("%d",ans);
}