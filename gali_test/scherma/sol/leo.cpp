// @check-accepted: esempi NE_10 L_equal N_small NE_1000 full
#include <iostream>
using namespace std;

int main(){
    int N, E, i, j, *P, *L;
    long long **dp;
    cin>>N>>E;
    P=new int[N];
    L=new int[N];
    dp=new long long*[N+1];
    dp[0]=new long long[E+1]();
    for (i=0; i<N; i++){
        cin>>P[i]>>L[i];
        dp[i+1]=new long long[E+1];
    }

    for (i=1; i<=N; i++){
        for (j=0; j<=E; j++){
            if (L[i-1]<=j) dp[i][j]=max(dp[i-1][j], P[i-1]+dp[i-1][j-L[i-1]]);
            else dp[i][j]=dp[i-1][j];
        }
    }

    cout<<dp[N][E];

    delete P;
    delete L;
    delete dp;
    return 0;
}
