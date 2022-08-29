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
    vector<pii> t(n, {0, 0});
    rep(i, 0, n){
        cin>>t[i].second>>t[i].first;
    }
    sort(all(t));
    int e = 0;
    int i = 0;
    int count = 0 ;
    while(i < n){
        while(i < n && t[i].second < e) i++;
        if(i >= n) break;
        e  = t[i].first;
        count++;
    }
    cout<<count;
    return 0;
}