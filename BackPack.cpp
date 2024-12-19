#include<iostream>
using namespace std;

struct prop{
    int W;
    int C;
}O[31];

int main(){
    int M, N;
    cin>>M>>N;
    int dp[201][31];
    for(int i=0; i<201;i++){
        for(int j=0;j<31;j++){
            dp[i][j]=0;
        }
    }
    for(int i=1; i<=N; i++) cin>>O[i].W>>O[i].C;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            dp[j][i] = dp[j][i-1];
            if(j >= O[i].W){
                dp[j][i] = max(O[i].C + dp[j-O[i].W][i-1], dp[j][i-1]);
            }
        }
    }
    cout<<dp[M][N];

}