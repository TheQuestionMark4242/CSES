#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1000000007LL;
ll dp[1000010];     
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    dp[0] = 1;
    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<int> c(n, 0);
    for(int& k: c) cin>>k;
    dp[0] = 1LL;
    for(int i = 1; i <= x; i++){
        for(auto k: c){
            if(i-k >= 0){
                (dp[i] += dp[i-k]) %= MOD;
            }
        }
    }
    cout<<dp[x];
} 