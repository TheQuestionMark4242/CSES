#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
    int n, q;
    cin>>n>>q;
    vector<ll> v(n, 0);
    for(auto& x: v) cin>>x;
    vector<ll> ps;
    partial_sum(all(v), (ps=v).begin());
    int a, b;
    while(q--){
        cin>>a>>b;
        cout<<ps[b-1]-((a-1)?ps[a-2]:0)<<"\n";
    }
    return 0;
}