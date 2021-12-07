#include<bits/stdc++.h>
using namespace std;

const int NN=3e5+5;
const int mod=1e9+7;

int p[NN*2];
int ans[NN];

int find(int u)
{
    if(p[u]==-1) return u;
    return p[u] = find(p[u]);
}

bool unionn(int u,int v)
{
    u=find(u);
    v=find(v);
    if(u == v) return false;
    p[u]=v;
    return true;
}

int main()
{
    int N,M;
    int t,u,v;
    int a;
    scanf("%d%d",&N,&M);
    a=N;
    ans[0]=1;
    bool check=true;
    for(int i=1;i<=N;++i)
    {
        ans[i] = ans[i-1]*2;
        ans[i] = ans[i] % mod;
    }
    for(int i=1;i<=2*N;++i)
    {
        p[i]=-1;
    }
    for(int m=1;m<=M;++m)
    {
        scanf("%d%d%d",&t,&u,&v);
        if(!check)
        {
            printf("0\n");
            continue;
        }
        if(t)
        {
            bool c=unionn(u , v);
            bool d=unionn(u + N,v + N);
            if(c and d)
            {
                --a;
            }
        }
        else 
        {
            bool c=unionn(u , v + N);
            bool d=unionn(u + N , v);
            if(c and d)
            {
                --a;
            }
        }
        if(find(u) == find(u + N) or find(v) == find(v + N))
        {
            printf("%d\n",0);
            check = false;
            continue;
        }
        printf("%d\n",ans[a]);
    }
}

//Credit duplicate from YEZAELP