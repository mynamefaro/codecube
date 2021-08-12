#include<bits/stdc++.h>
using namespace std;
int table[1002][3002];
int main(){
    int n;
    scanf("%d",&n);
    int arr[n+1];
    for(int i=1;i<=n;++i) scanf("%d",&arr[i]);
    for(int i=1;i<=n;++i){
        table[i][0]=2e9;
        for(int j=1;j<=3000;++j){
            table[i][j]=2e9;
            if(arr[i]<=j) table[i][j]=min(table[i][j] , table[i-1][arr[i]-1]);
            table[i][j]=min(table[i][j] , 1 + table[i-1][j-1]);
        }
    }
    printf("%d",table[n][3000]);
}