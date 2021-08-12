#include <bits/stdc++.h>
using namespace std;

int main(){
	int ans = 2e9;
	string s;
	cin >> s;
	vector <int> cnt_f;
	for(int i = 1;i < s.size();++i){
		if(s.size() % i > 0) continue;
		int cnt = 0;
		//cout << "HEY HEY";
		for(int j = 0;j < i;++j){
			int f = 0;
			cnt_f.assign(28 , 0);
			for(int k = j;k < s.size();k += i){
				++cnt_f[s[k] - 'a'];
				f = max(f , cnt_f[s[k] - 'a']);
				//cout << f << endl;
			}
			cnt += ((s.size() / i) - f);
			cnt_f.clear();
		}
		ans = min(ans , cnt);
	}
	cout << ans;
}
