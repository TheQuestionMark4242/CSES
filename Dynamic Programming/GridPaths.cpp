#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll mod = 1000000007LL;
ll p[1010][1010];
char t[1010][1010];
int main() {
    memset(p, 0, sizeof(p));
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int n;
    cin>>n;
    rep(i, 0, n) rep(j, 0, n) cin>>t[i][j];
    p[0][0] = (t[0][0] != '*');
    rep(i, 0, n) rep(j, 0, n) (p[i][j] += ((i)? p[i-1][j]: 0)*((t[i][j] != '*')? 1: 0) + ((j)? p[i][j-1]: 0)*((t[i][j] != '*')? 1: 0))%=mod;
    cout<<p[n-1][n-1];
}
