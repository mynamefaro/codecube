#include<bits/stdc++.h>
using namespace std;
int table[100002][10],query[100002][10];
pair<int,int> ptable[100002][10],pquery[100002][10];
int main(){
    string s,t="codecube";
    cin >> s;
    int n=s.size();
    int m=t.size();
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            query[i][j]=2e9;
        }
    }
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            ptable[i][j]=make_pair(i,j);
            pquery[i][j]=make_pair(i,j);
            if(i==0 and j==0){
                query[i][j]=0;
                continue;
            }else if(j==0){
                query[i][j]=table[i][j]=1;
            }else if(i<j){
                query[i][j]=table[i][j]=2e9;
            }else{
                if(s[i-1]==t[j-1]){
                    query[i][j]=table[i][j]=table[i-1][j-1];
                }else{
                    query[i][j]=table[i][j]=1+query[i-1][j];
                }
            }
            if(i>0) query[i][j]=min(query[i][j],query[i-1][j]);
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }
    printf("%d",table[n][m]);
    printf(" %d",ptable[n][m].first);
}