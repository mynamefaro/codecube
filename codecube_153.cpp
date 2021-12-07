#include<bits/stdc++.h>
using namespace std;

using tll = tuple<int,int,int,int,int,int>;
using tl=tuple<int,int,int,int>;
const int A = (1<<7);

int di[5] = {-1,0,1,0,0};
int dj[5] = {0,-1,0,1,0};

int dis[202][202][7][A];
bool visited[202][202][7][A]; //INIT NODE (row , column , time , bitmask (choosen))

int newt(int t){
	if(t+1>6) return 1;
	return t+1;
}

int main()
{
    
    int arr[202][202], G[202][202]; //board , reward (by order ex 3,5 is 1st) it has 7 rewards
    char c;

    //input
    int N,M;
    int sr,sc; //start r and start c
    int reward_id=0;
    int ans=-1;
    
    queue<tll> PQ;
    
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            cin >> c;
            if(c=='#'){
                arr[i][j]=-1;
            }else if(c=='S'){
                arr[i][j]=8;
                PQ.emplace(0 ,i,j,1,0,0);
    			visited[i][j][1][0];
            }else if(c=='G'){
                arr[i][j]=7;
                G[i][j]= (reward_id);
                ++reward_id;
            }else if(c=='.'){
                arr[i][j]=8;
            }else{
                arr[i][j]=c-'0';
            }
            //printf("%d ",arr[i][j]);
        }
        //printf("\n");
    }
    //DJK
    
    
    while(!PQ.empty()){
    	int d=get<0>(PQ.front());
        int r=get<1>(PQ.front());
        int c=get<2>(PQ.front());
        int t=get<3>(PQ.front());
        int b=get<4>(PQ.front()); //b is bit
        int cnt=get<5>(PQ.front()); //REWARD COUNT
        PQ.pop();

  
            for(int j=0;j<5;++j){
            	int bb=b;
            	int ccnt=cnt; //NEW REWARD COUNT
                int rr=r+di[j]; //NEW R
                int cc=c+dj[j]; //NEW C
                if(rr<=0 or rr>N or cc<=0 or cc>M or arr[rr][cc]==-1) continue;
				
                //CHECK CONDITION
            
                if((arr[rr][cc] > 6 or (arr[rr][cc] == newt(t) and arr[rr][cc] <= 6) or arr[rr][cc] <= cnt) and !visited[rr][cc][newt(t)][bb]){
                	if(arr[rr][cc]==7)
            		{
                		int id = G[rr][cc]; //REWARD ID
            			bb = (b|(1<<id)); //UPDATE NEW BIT (IF IT HAS A NEW REWARD
            			if(!(b & (1<<id))){ //IF THIS ID IS A NEW REWARD
            				++ccnt;
            			}
            			if(ccnt==7){ //IF IT HAS 7 REWARDS
							printf("%d",d+1);
							return 0;
        				}
					}
                    PQ.emplace(d+1 , rr , cc , newt(t) , bb , ccnt);
                    visited[rr][cc][newt(t)][bb]=true;
                }
            }
        
        
    }
	
    printf("%d",ans);
    return 0;
}
