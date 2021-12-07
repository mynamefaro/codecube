#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int g[n+1],b[n+1];
    for(int i=1;i<=n;++i){
        scanf("%d%d",&g[i],&b[i]);
    }
    for(int i=1;i<=n;++i){
    	if(!b[i]) continue;
    	for(int j=max(1,i-k);j<=min(n,i+k);++j){
    		if(b[i]>g[j]){
    			b[i]-=g[j];
    			g[j]=0;
			}else{
				g[j]-=b[i];
				b[i]=0;
				break;
			}
		}
		if(b[i]>0){
			printf("NO");
			return 0;
		}
	}
	for(int i=1;i<=n;++i){
    	if(!g[i]) continue;
    	for(int j=max(1,i-k);j<=min(n,i+k);++j){
    		if(g[i]>b[j]){
    			g[i]-=b[j];
    			b[j]=0;
			}else{
				b[j]-=g[i];
				g[i]=0;
				break;
			}
		}
		if(g[i]>0){
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}
