#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool dp[100010];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int n;
    cin>>n;
    vector<int> c(n+1, 0);
    int s = 0;
    rep(i, 1, n+1) {
        cin>>c[i];
        s += c[i];
    }
    dp[0] = true;
    rep(i, 1, n+1){
        for(int j = s; j>=0; j--){
            if(dp[j] == true) {
                dp[j+c[i]] = true;
            }
        }
    }
    int k = count(dp + 1, dp + s + 1, true);
    cout<<k<<"\n";
    rep(i, 1, s+1){
        if(dp[i]) cout<<i<<" ";
    }
    return 0;
}