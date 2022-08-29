#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct ps2D{
    vector<vector<ll>> v;
    ps2D(const vector<vector<ll>>& m){
        int r = sz(m);
        int c = sz(m[0]);
        v.assign(r, vector<ll>(c, 0LL));
        v[0][0] = m[0][0];
        rep(i, 1, r) v[0][i] = v[0][i-1] + m[0][i];
          
    }

};
int main(){

    return 0;
}