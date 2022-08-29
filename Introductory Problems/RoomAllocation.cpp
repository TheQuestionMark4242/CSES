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
    vector<pair<int, int>> t(n, {0, 0});
    rep(i, 0, n){
        cin>>t[i].first>>t[i].second;
    }
    sort(all(t));
    priority_queue<pii, vector<pii>, greater<pii>> p;
    p.push(t[0]);
    rep(i, 1, n){
        if(t[i].first < p.top().second){
            p.push(t[i]);
        }
    }
    return 0;
}