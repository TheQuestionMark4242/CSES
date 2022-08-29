#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct DSU{
    vi e;
    void init(int N){
        e.assign(N, -1);
    }
    int get(int x){
        return (e[x] < 0 ? x : e[x] = get(e[x])); 
    }
    bool sameSet(int x, int y){ return get(x) == get(y);}
    void unite(int x, int y){
        x = get(x); y = get(y);
        if(-e[x] < -e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
    }
};
const int MAXN = 100010;
typedef pair<ll, pair<int, int>> edge; 

    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    int m;
    cin>>n;
    cin>>m;
    vector<edge> ej;
    for(int i = 0; i < m; i++){
        int f, t;
        ll w;
        cin>>f>>t>>w;
        ej.push_back({w, {f,t}});
    }
    sort(all(ej));
    DSU d;
    d.init(n+1);
    ll sum = 0;
    int count = 0;
    for(int i = 0; i < m; i++){
        if(!d.sameSet(ej[i].second.first, ej[i].second.second)){
            d.unite(ej[i].second.first, ej[i].second.second);
            sum += ej[i].first;
            count++;
        }
    }
    if(count == n-1) cout<<sum;
    else cout<<"IMPOSSIBLE";
    return 0;
}