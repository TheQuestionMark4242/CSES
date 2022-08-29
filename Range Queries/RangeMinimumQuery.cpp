#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct RMQ{ //Sparse Table method
    vector<vector<ll>> jmp;
    RMQ(const vector<ll> &V) : jmp(1, V){
        for(int k = 1, pw = 1; pw*2 <= sz(V); k++, pw *= 2){
            jmp.emplace_back(sz(V)-2*pw+1);
            rep(j, 0, sz(jmp[k]))
                jmp[k][j] = min(jmp[k-1][j], jmp[k-1][j+pw]);
        }
    }
    ll query(int a, int b){
        assert(a < b);
        int dep = 31-__builtin_clz(b-a);
        return min(jmp[dep][a], jmp[dep][b-(1<<dep)]);
    }
};
int main(){
    int n, q;
    cin>>n>>q;
    vector<ll> v(n, 0);
    rep(i,0,n) cin>>v[i];
    RMQ r(v);
    while(q--){
        int a, b;
        cin>>a>>b;
        cout<<r.query(a-1, b)<<"\n";
    }
    return 0;
}