#include <bits/stdc++.h>
using namespace std;

int main(){
	int K;
	string S;
	cin >> K;
	cin >> S;
	if(K == 1){
		cout << S;
		return 0;
	}
	queue <int> H[K + 1];
	vector <int> c_list;
	vector <int> c_cnt (K + 1 , 0);
	int c = 1;
	int y_d = 1;
	int x_cnt = 1;
	for(int i = 0;i < S.size();++i){
		c_list.push_back(c);
		++c_cnt[c];
		if((c == K || c == 1) && i > 0){
			if(x_cnt == K){
				x_cnt = 1;
				y_d *= -1;
				c += y_d;
			}else{
				++x_cnt;
			}
		}else{
			c += y_d;
		}
	}
	c = K;
	for(int i = 0;i < S.size();++i){
		if(c_cnt[c] == 0) --c;
		H[c].push(i);
		--c_cnt[c];
	}
	for(auto x:c_list){
		printf("%c",S[H[x].front()]);
		H[x].pop();
	}
}
