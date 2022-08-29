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
    vector<int> v(n, 0);
    for(auto&x : v) cin>>x;
    map<int, int> h;
    int l = 0;
    int r = 0;
    int ml = 1;
    for(int i = 0; i < n; i++){
        if(h.find(v[i]) != h.end()) l = h[v[i]] + 1; 
        if(r-l+1 > ml) ml = r-l+1; 
        r++;
        h[v[i]] = i;
    }
    cout<<ml;
}