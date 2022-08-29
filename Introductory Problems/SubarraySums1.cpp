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
    ll n, x;
    cin>>n>>x;
    vector<ll> ps(n+1, 0);
    map<ll, ll> h;
    h[0] = 1;
    ll count = 0;
    rep(i, 1, n+1){
        cin>>ps[i];
        ps[i] += ps[i-1];
        if(h.find(ps[i]-x) != h.end()){
            count += h[ps[i]-x];
        }
        if(h.find(ps[i]) != h.end()) h[ps[i]]++;
        else h[ps[i]] = 1;
    }
    cout<<count;
    return 0;
}