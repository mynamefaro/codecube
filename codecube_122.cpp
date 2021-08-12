#include<bits/stdc++.h>
using namespace std;
bool visited[502][502][2][2][2];
int di[] = {-1,0,1,0};
int dj[] = {0,1,0,-1};
int main(){
	int N,M;
	int sr,sc,er,ec;
	string s;
	scanf("%d%d",&N,&M);
	int arr[N][M];
	for(int r=0;r<N;++r){
		cin >> s;
		for(int c=0;c<M;++c){
			char ch=s[c];
			if(ch=='S'){
				sr=r;
				sc=c;
				arr[r][c]=0;
			}else if(ch=='E'){
				er=r;
				ec=c;
				arr[r][c]=0;
			}else if(ch=='#'){
				arr[r][c]=9;
			}else if(ch=='J'){
				arr[r][c]=1;
			}else if(ch=='B'){
				arr[r][c]=2;
			}else if(ch=='P'){
				arr[r][c]=3;
			}else if(ch=='j'){
				arr[r][c]=-1;
			}else if(ch=='b'){
				arr[r][c]=-2;
			}else if(ch=='p'){
				arr[r][c]=-3;
			}else if(ch=='.'){
				arr[r][c]=0;
			}
		}
	}
	
	queue<tuple<int,int,int,int,int,int>> Q;
	Q.emplace(sr,sc,0,0,0,0);
	int ans=-1;
	while(!Q.empty()){
		int r=get<0>(Q.front());
		int c=get<1>(Q.front());
		int j=get<2>(Q.front());
		int b=get<3>(Q.front());
		int p=get<4>(Q.front());
		int dis=get<5>(Q.front());Q.pop();
		//cout << r << " " << c << " " << j << " " << b << " " << p << " " << dis << endl;
		if(r==er and c==ec){
			ans=dis;
			break;
		}
		for(int i=0;i<4;++i){
			int rr=r+di[i];
			int cc=c+dj[i];
			if(rr<0 or rr>=N or cc<0 or cc>=M) continue;
			if(arr[rr][cc]<5){
				if(arr[rr][cc]==0){
					if(visited[rr][cc][j][b][p]) continue;
					visited[rr][cc][j][b][p]=true;
					Q.emplace(rr,cc,j,b,p,dis+1);
				}else if(arr[rr][cc]==1 and j==1){
					if(visited[rr][cc][j][b][p]) continue;
					visited[rr][cc][j][b][p]=true;
					Q.emplace(rr,cc,j,b,p,dis+1);
				}else if(arr[rr][cc]==2 and b==1){
					if(visited[rr][cc][j][b][p]) continue;
					visited[rr][cc][j][b][p]=true;
					Q.emplace(rr,cc,j,b,p,dis+1);
				}else if(arr[rr][cc]==3 and p==1){
					if(visited[rr][cc][j][b][p]) continue;
					visited[rr][cc][j][b][p]=true;
					Q.emplace(rr,cc,j,b,p,dis+1);
				}else if(arr[rr][cc]==-1){
					if(visited[rr][cc][1][b][p]) continue;
					visited[rr][cc][1][b][p]=true;
					Q.emplace(rr,cc,1,b,p,dis+1);
				}else if(arr[rr][cc]==-2){
					if(visited[rr][cc][j][1][p]) continue;
					visited[rr][cc][j][1][p]=true;
					Q.emplace(rr,cc,j,1,p,dis+1);
				}else if(arr[rr][cc]==-3){
					if(visited[rr][cc][j][b][1]) continue;
					visited[rr][cc][j][b][1]=true;
					Q.emplace(rr,cc,j,b,1,dis+1);
				}
			}
		}
	}
	cout<<ans;
}
