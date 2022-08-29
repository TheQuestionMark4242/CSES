#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
const int MAXN = 100010;
vector<int> adj[MAXN];
bool visited[MAXN]{};
int color[MAXN];
bool contradiction = false;
void dfs(int s){
    int col = color[s];
    visited[s] = true;
    col = 1-col;
    for(int v: adj[s]){
        if(!visited[v]){
            visited[v] = true;
            color[v] = col;
            dfs(v);
        }
        else{
            if(color[v] != col){
                contradiction = true;
                break;
            }
        }
    }
}
int main() {
    memset(color, -1, sizeof(color));
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin>>n>>m;
    while(m--){
        int a, b;
        cin>>a>>b;
        a--; 
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]) color[i] = 0;
        dfs(i);
    }
    if(contradiction) cout<<"IMPOSSIBLE\n";
    else{
        for(int i = 0; i < n; i++){
            cout<<color[i]+1<<" ";
        }
    }
    return 0;
}
 