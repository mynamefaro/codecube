#include<bits/stdc++.h>
using namespace std;
using lli=long long;
char s[2010],t[2010];
lli mod[200];
int n,m;//slen,tlen
bool check(int l){
	//frequency
	unordered_map<lli,int> f;
	//string s
	lli hash=0;
	for(int i=0;i<l;++i){
		hash+=mod[s[i]];
	}
	for(int i=l-1;i<n;++i){
		if(i>l-1){
			hash-=mod[s[i-l]];
			hash+=mod[s[i]];
		}
		++f[hash];
	}
	//string t;
	hash=0;
	for(int i=0;i<l;++i){
		hash+=mod[t[i]];
	}
	for(int i=l-1;i<m;++i){
		if(i>l-1){
			hash-=mod[t[i-l]];
			hash+=mod[t[i]];
		}
		if(f.count(hash)>0) return true;
	}
	return false;
}
int main(){
	scanf("%s",s);
	scanf("%s",t);
	mod['A']=1;
	for(int i='B';i<='Z';++i){
		mod[i]=1e9+7;
		mod[i]*=mod[i-1];
	}
	int ans=0;
	n=strlen(s);
	m=strlen(t);
	for(int l=min(n,m);l>=1;--l){
		if(check(l)){
			printf("%d",l);
			return 0;
		}
	}
	printf("0");
}
