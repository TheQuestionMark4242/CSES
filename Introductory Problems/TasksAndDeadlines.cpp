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
    vector<ll> t(n, 0);
    vector<ll> d(n, 0);
    rep(i, 0, n) cin>>t[i]>>d[i];
    sort(all(t));
    rep(i, 1, n) t[i] += t[i-1];
    cout<<-accumulate(all(t), 0LL)+accumulate(all(d), 0LL);
    return 0;
}