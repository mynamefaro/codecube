#include <bits/stdc++.h>
using namespace std;

int N;
string s;
vector <int> arr , play_space;

int put(int i){
	if(i == N) return 0;
	if(arr[i] > 0) return 0;
	put(i + 1);
	for(int r = 1;r <= 2;++r){
		if(r != arr[i + 1] && (i == 0 || r != arr[i - 1])){
			arr[i] = r;
			return 0;
		}
	}
}

int main(){
	cin >> N;arr.assign(N + 1,0);
	cin >> s;
	int space = 0;
	for(int i = 0;i < s.size();++i){
		if(s[i] == 'W'){
			arr[i] = 1;
			space = 0;
		}else if(s[i] == 'B'){
			arr[i] = 2;
			space = 0;
		}else{
			++space;
			if(space == 1) play_space.push_back(i);
		}
	}
	for(auto i:play_space) put(i);
	for(int i = 0;i < N;++i){
		if(arr[i] == 0) printf("G");
		if(arr[i] == 1) printf("W");
		if(arr[i] == 2) printf("B");
	}
}
