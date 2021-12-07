#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int main(){
    char c[]={'c','o','d','e','c','u','b','e','\0'};
    char s[100002];
    scanf("%s",s);
    int m=strlen(s);
    pii DP[9][m+1];
    DP[1][0]=make_pair(-1e9,1e9);
    for(int j=1;j<=m;++j){
    	if(s[j-1]==c[0]){
    		DP[1][j]=make_pair(j,j);
		}else{
			DP[1][j]=DP[1][j-1];
		}
	}
	pii ans;
	int ansl=2e9+12;
	for(int i=2;i<=8;++i){
		DP[i][0]=make_pair(-1e9,1e9);
		for(int j=1;j<=m;++j){
			DP[i][j]=DP[i][j-1];
			if(c[i-1]==s[j-1]){
				//if(j-DP[i-1][j-1].first <= DP[i][j].second-DP[i][j].first){
					DP[i][j]=make_pair(DP[i-1][j-1].first,j);
				//}
			}
			if(i<8) continue;
			if(DP[i][j].second-DP[i][j].first<ansl){
				ansl=DP[i][j].second-DP[i][j].first;
				ans=DP[i][j];
			}else if(DP[i][j].second-DP[i][j].first==ansl){
				if(ans.first>DP[i][j].first){
					ans=DP[i][j];
				}
			}
		}
	}
	/*for(int i=1;i<=8;++i){
		for(int j=1;j<=m;++j) printf("(%d %d)",DP[i][j].first,DP[i][j].second);
		printf("\n");
	}*/
	if(ans.first==-1e9 or ans.second==1e9){
		printf("-1");
		return 0;
	}
	printf("%d %d",ans.first,ans.second);
}
