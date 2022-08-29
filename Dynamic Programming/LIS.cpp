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
    vi a(n, 0);
    for(auto &x: a) cin>>x;
    vi dp(n, INT_MAX);
    dp[0] = a[0];
    for(int i = 1; i < n; i++){
        int j = distance(dp.begin(), upper_bound(all(dp), a[i]));
        if(j != n) dp[j] = a[i];
    }
    int k = n-1;
    while(dp[k] == INT_MAX) k--;
    cout<<k+1;
    return 0;
}