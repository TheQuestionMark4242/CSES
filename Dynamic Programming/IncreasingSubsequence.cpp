#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

pii dp[400010];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    fill(dp, dp+400010, make_pair(0, 0));
    int n;
    vi a(n+1, 0);
    a[0] = INT_MIN;
    rep(i, 1, n+1) cin>>a[i];
    dp[0] = make_pair(0, 0);
    dp[1] = make_pair(1, 1);
    for(int i = 1; i <= 2*n; i++){
        if(i&1){
            if(dp[i-1].first > dp[i-2].first){
                dp[i] = dp[i-1];
            }
            else{
                dp[i] = dp[i-2];
            }
        }
        else{
            if(a[i] > a[dp[i-1].second]){
                dp[i] = make_pair(dp[i-1].first+1, i);
            }
            else if(a[i] > a[dp[i-2].second]){
                dp[i] = make_pair(dp[i-2].first+1, i);
            }
            else{
                dp[i] = make_pair(1, i);
            }
        }
    }
    cout<<max(dp[2*n+1].first, dp[2*n].first);
    return 0;
}