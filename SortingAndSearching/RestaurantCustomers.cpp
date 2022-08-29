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
    vector<pair<ll, ll>> v;
    rep(i, 0, n){
        ll a, b;
        cin>>a>>b;
        v.push_back({a, 1LL});
        v.push_back({b+1, -1LL});
    }
    sort(all(v));
    vector<ll> ps(2*n+1, 0);
    for(int i = 0; i < 2*n; i++){
        ps[i] += v[i].second;
    }
    for(int i = 1; i <= 2*n+1; i++){
        ps[i] += ps[i-1];
    }
    cout<<*max_element(all(ps));
    return 0;
}