#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int mod = 1000000007LL;
ll ways[1000020][110];
int main() {
    memset(ways, 0, sizeof(ways));
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int n, x;
    cin>>n>>x;
    vi c(n+1, 0);
    rep(i, 1, n+1) cin>>c[i];
    rep(i, 0, n+1) ways[0][i] = 1;
    rep(i, 1, x+1){
        rep(j, 1, n+1){
            rep(k, 1, n+1)
                if(i-c[j] >= 0) (ways[i][j] += ways[i-c[j]][k]) %=mod;
        }
    }
    cout<<(ways[x][n]+mod)%mod;
    return 0;
}