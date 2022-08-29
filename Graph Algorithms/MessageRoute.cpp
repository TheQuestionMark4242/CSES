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
vector<int> adj[MAXN];
bool visited[MAXN]{};
int dist[MAXN]{};
int parent[MAXN] {};

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    dist[s] = 0;
    parent[s] = -1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: adj[u]){
            if(!visited[v]){
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
                parent[v] = u;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin>>n>>m;
    rep(i, 0, m){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);
    if(visited[n]){
        cout<<dist[n]+1<<"\n";
        stack<int> s;
        int k = n;
        do{
            s.push(k);
            k = parent[k];
        } while(k != -1);
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
    }
    else cout<<"IMPOSSIBLE";
    return 0;
}