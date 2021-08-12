#include<bits/stdc++.h>
using namespace std;
long long int qs[602];
long long int table[602][602];
bool visited[602][602];
long long int query(int a,int b){
    return qs[b]-qs[a-1];
}
long long int solve(int i,int j){
    if(i>=j) return 0;
    if(!visited[i][j]){
        visited[i][j]=true;
        for(int k=j;k>i;--k){
            long long int qa=query(i,k-1);
            long long int qb=query(k,j);
            table[i][j]=max(table[i][j] ,2*min(qa,qb) + max(qa,qb) + solve(i,k-1)+solve(k,j));
        }
    }
    return table[i][j];
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%lld",&qs[i]);
        qs[i]+=qs[i-1];
    }
    printf("%lld",solve(1,n));
}