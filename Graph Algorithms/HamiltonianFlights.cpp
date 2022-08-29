#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int mod = 1000000007;
const int MAXN = 21;
vi adj[MAXN];
int routes[1<<21][MAXN];
int n, m;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    memset(routes, 0, sizeof(routes));
    cin>>n>>m;
    rep(i, 0, m){
        int a, b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
    }
    routes[1][0] = 1;
    int bit = 1<<n;
    rep(i, 1, bit){
        rep(j, 0, n){
            int mask = 1<<j;
            if(i & mask){
                for(int v: adj[j]){
                    int masker = 1<<v;
                    if(!(i & masker)) {
                        (routes[i|masker][v] += routes[i][j] ) %= mod;
                    }
                }
            }
        }
    }
    cout<<(routes[bit-1][n-1] + mod)%mod;
    return 0;
}