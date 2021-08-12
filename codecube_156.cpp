#include <bits/stdc++.h>
using namespace std;

int main(){
	string t = "codecube";
	string s;
	cin >> s;
	int i = 0;int j = 0;
	int ans = 0;
	while(i < s.size()){
		if(s[i] == t[j]){
			++i;
		}else{
			++ans;
		}
		++j;
		if(j == 8 && i < s.size()) j = 0;
	}
	while(j < 8){
		++j;++ans;
	}
	cout << ans;
}
