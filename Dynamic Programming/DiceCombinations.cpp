#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int dp[1000010];

int main(){
    int N;
    cin>>N;
    memset(dp, 0, (100010)*sizeof(int));
    dp[0] = 1;
    for(int i = 0; i <= N; i++){
        for(int ii = 1; ii <= 6; ii++){
            (dp[i] += ((i-ii >= 0) ? dp[i-ii] : 0)) %= MOD;
        }
    }
    cout<<dp[N];
    return 0;
}

