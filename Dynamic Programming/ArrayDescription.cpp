#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int mod = 1000000007LL;
const int MAXN = 100010;
const int MAXM = 110;
ll dp[MAXM][MAXN];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    memset(dp, 0, sizeof(dp));
    int n, m;
    cin>>n>>m;
    vi x(n, 0);
    for(auto& a: x) cin>>a;
    if(x[0] == 0) for(int j = 1; j <= m; j++) dp[j][0] = 1;
    else dp[x[0]][0]++;
    for(int i = 1; i < n; i++){
        if(!x[i]) for(int j = 1; j <= m; j++) (dp[j][i] = (dp[j-1][i-1]+dp[j][i-1]+dp[j+1][i-1])) %= mod; 
        else{
            (dp[x[i]][i] = dp[x[i]-1][i-1] + dp[x[i]][i-1] + dp[x[i]+1][i-1]) %= mod;
        }
    }
    ll sum = 0;
    for(int i = 1; i <= m; i++){
        (sum += dp[i][n-1]) %= mod;
    }
    cout<<sum;
}