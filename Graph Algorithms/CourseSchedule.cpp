#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 100010;
int n, m;
vi adj[MAXN];
bool visited[MAXN]{};
vi lo;

void dfs(int s){
    visited[s] = true;
    for(int u : adj[s]){
        if(!visited[u]){
            dfs(u);
        }
    }
    lo.push_back(s);
}

void ts(){
    rep(i, 0, n) if(!visited[i]) dfs(i);
    reverse(all(lo));
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin>>n>>m;
    while(m--){
        int a, b;
        cin>>a>>b;
        a--; b--;
        adj[a].push_back(b);
    }
    ts();
    vi ind(n, 0);
    rep(i, 0, n) ind[lo[i]] = i;
    rep(i, 0, n){
        for(int v: adj[i]){
            if(ind[v] <= ind[i]){
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    for(int x: lo) cout<<x+1<<" ";
    return 0;
}