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
    vector<ll> v(n, 0);
    for(auto &i: v) cin>>i;
    sort(all(v));
    ll m = (n&1)? v[(n-1)/2] : (v[n/2-1]+v[n/2])/2;
    transform(all(v), begin(v), [&](ll x){return abs(x-m);});
    cout<<accumulate(all(v), 0LL);
    return 0;
}