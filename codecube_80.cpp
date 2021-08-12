#include <bits/stdc++.h>
using namespace std;

string s;

int find_k(int N){
	if(s.size() % N != 0) return 0;
	for(int i = N;i < s.size();++i){
		if(s[i % N] != s[i]) return 0;
	}
	return s.size() / N;
}

int main(){
	int K = 0;
	for(int t = 1;t <= 5;++t){
		K = 0;
		cin >> s;
		for(int l = 0;l <= s.size()/2 ;++l){
			for(int i = 0;i <= l;++i){
				if(l + 1 + i >= s.size()) break;
				if(s[i] != s[l + 1 + i]) break;
				if(i == l){
					int N = l + 1;
					K = find_k(N);
				}
			}
			if(K > 0) break;
		}
		if(K == 0) K = 1;
		set <int> fac;
		fac.insert(1);fac.insert(K);
		for(int i = 2;i <= K / 2;++i){
			if(K % i == 0){
				fac.insert(i);
				fac.insert(K / i);
			}
		}
		printf("%d\n",fac.size());
	}
}
