#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll dp[1000010];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    memset(dp, 0, 1000010*sizeof(int));
    int n;
    cin>>n;
    dp[0] = 0;
    rep(i, 1, n+1){
        dp[i] = LLONG_MAX-1;
        int k = i;
        while(k){
            if(i-(k%10) >= 0) dp[i] = min(dp[i], 1 + dp[i-(k%10)]);
            k/=10;
        }
    }
    cout<<dp[n];
}