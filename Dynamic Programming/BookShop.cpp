#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<int> w(n+1, 0);
    vector<int> v(n+1, 0);
    rep(i, 1, n+1) cin>>w[i];
    rep(i, 1, n+1) cin>>v[i];
    vector<ll> dp(x+1, -1);
    dp[0] = 0;
    for(int j = 1; j <= n; j++){
        for(int i = x; i >= 0; i--){
            if(dp[i] != -1) dp[i+w[j]]  = max(dp[i+w[j]], dp[i]+v[j]);
        }
    }
    cout<<*max_element(dp.begin(), dp.end());
    return 0; 
}