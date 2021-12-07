import java.util.Scanner;

class codecube_192{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = input.nextInt();
        int k = input.nextInt();
        int ans=-2000000000;
        int[][] DP;int[] a,b;
        a=new int[n+1];
        b=new int[m+1];
        for(int i=1;i<=n;++i){
            a[i]=input.nextInt();
        }
        for(int j=1;j<=m;++j){
            b[j]=input.nextInt();
        }
        DP = new int[n+1][2];
        for(int j=0;j<=m;++j){
            int mn=2000000000;
            for(int i=0;i<=n;++i){
                DP[i][j%2]=2000000000;
                if(i==0){
                    DP[0][j%2]=j;
                }else if(j==0){
                    DP[i][0]=1;
                }else{
                    if(a[i]==b[j]){
                        DP[i][j%2]=DP[i-1][(j-1)%2];
                        if(DP[i][j%2]<mn){
                            mn=DP[i][j%2];
                        }
                    }else{
                        if(DP[i][j%2]>1+DP[i][(j-1)%2]){
                            DP[i][j%2]=1+DP[i][(j-1)%2];
                        }
                        if(DP[i][j%2]>1+DP[i-1][(j-1)%2]){
                            DP[i][j%2]=1+DP[i-1][(j-1)%2];
                        }
                        if(DP[i][j%2]>1+mn){
                            DP[i][j%2]=1+mn;
                        }
                    }
                }
                if(DP[i][j%2]<=k){
                    if(j>ans){
                        ans=j;
                    }
                }
            }
        }
    System.out.println(ans);
    }
}