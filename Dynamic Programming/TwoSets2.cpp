#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll mod = 1000000007LL;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int n;
    cin>>n;
    if(n%4 == 1 || n%4 == 2){
        cout<<0;
        return 0;
    } 
    int s = (n*(n+1))/4;
    vector<ll> dp(s+1, 0);
    dp[0] = 1;
    rep(i, 1, n){
        for(int j = s; j >= 0; j--){
            if(dp[j]){
                if(i+j <= s) 
                    (dp[j+i] += dp[j])%=mod;
            }
        }
    }
    cout<<dp[s];
}