#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll j(ll n, ll k){
    if(n == 1) return 1;
    ll r = (n+1)/2;
    if(n&1){
        if(k <= r) return (2*k)%n;
        return j(n-r, k-r)*2+1;
    }
    if(k <= r) return 2*k;
    else return 2*j(r, k-r)-1; 
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        cout<<j(n, k)<<"\n";
    }
}