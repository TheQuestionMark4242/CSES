#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll mod = 1000000007LL;
ll exp(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1) res = (res*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return (res+mod)%mod;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int t;
    cin>>t;
    while(t--){
        ll a, b;
        cin>>a>>b;
        cout<<exp(a, b)<<"\n";
    }
}
