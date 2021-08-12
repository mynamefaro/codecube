#include<bits/stdc++.h>
using namespace std;
int table1[1000002];
int p1[1000002];
int c1[11],c2[11];
int arr[11];
int main(){
	int k,p,m;
	scanf("%d%d%d",&p,&m,&k);
	for(int i=1;i<=k;++i) scanf("%d",&arr[i]);
	for(int i=1;i<=m;++i){
		table1[i]=2e9;
		p1[i]=i;
		for(int j=1;j<=k;++j){
			if(i>=arr[j]){
				if(table1[i-arr[j]]<table1[i]){
					table1[i]=table1[i-arr[j]];
					p1[i]=i-arr[j];
				}
			}
		}
		++table1[i];
	}
	int pp1,pp2,sum_coin=2e9;
	for(int i=p;i<=m;++i){
		if(table1[i]+table1[i-p]<sum_coin){
			sum_coin=table1[i]+table1[i-p];
			pp1=i;
			pp2=i-p;
		}
	}
	printf("%d %d\n",table1[pp1],table1[pp2]);
	int pp=pp1;
	while(pp!=p1[pp]){
		for(int i=1;i<=k;++i){
			if(arr[i]==pp-p1[pp]){
				++c1[i];
				pp=p1[pp];
				break;
			}
		}
	}
	for(int i=1;i<=k;++i) printf("%d ",c1[i]);
	printf("\n");
	pp=pp2;
	//cout << pp << endl;
	while(pp!=p1[pp]){
		for(int i=1;i<=k;++i){
			if(arr[i]==pp-p1[pp]){
				++c2[i];
				pp=p1[pp];
				break;
			}
		}
	}
	for(int i=1;i<=k;++i) printf("%d ",c2[i]);
}
