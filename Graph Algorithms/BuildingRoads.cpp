#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
int n,m;
vector<int> adj[MAXN];
bool visited[MAXN];
int components = 0;

void dfs(int start){
    visited[start] = true;
    for(int v: adj[start]){
        if(!visited[v]) dfs(v);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> rep;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            rep.push_back(i);
            dfs(i);
            components++;
        }
    }
    cout<<components-1<<"\n";
    for(int i = 0; i < components-1; i++){
        cout<<rep[i]+1<<" "<<rep[i+1]+1<<"\n";
    }
    return 0;
}